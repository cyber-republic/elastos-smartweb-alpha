import { Component } from '@angular/core';
import { NavController, Platform, LoadingController } from 'ionic-angular';
import { BarcodeScanner } from '@ionic-native/barcode-scanner';
import { AlertController } from 'ionic-angular';

import { QrcodePage } from '../qrcode/qrcode';
import { ChatPage } from '../chat/chat';
import { ChatService } from "../../providers/chat-service/chat-service";
import { Events } from 'ionic-angular';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {

  scannedCode = null;
  public isScanning = false;
  public unregisterBackButtonAction: any;

  items = [];
  loading = null;

  constructor(public navCtrl: NavController, private barcodeScanner: BarcodeScanner,
        private alertCtrl: AlertController, public platform: Platform,
        private chatService: ChatService,
        private events: Events, private loadingCtr: LoadingController) {
        this.loading = this.loadingCtr.create({
          content: 'connecting ...',
          dismissOnPageChange: true,
          showBackdrop: true
        });
        this.loading.present();
  }

  ionViewDidLoad() {

    this.events.subscribe('chat:ready', msg => {
      if (this.loading != null) {
        this.loading.dismiss();
        this.loading = null;
      }
    });

    this.events.subscribe('chat:friendonline', msg => {
      this.friendConnectionChanged(msg);
    });

    this.events.subscribe('chat:connectionchanged', msg => {
      console.log("==== home page receive connectionchanged " + msg.online);

      if (this.loading != null) {
        this.loading.dismiss();
        this.loading = null;
      }

      if (msg.online == 1) {
          this.items = this.chatService.getFriends();
      }
      console.log("=== home page getFriends " + this.items);
    });

    this.events.subscribe('chat:friendadded', msg => {
      console.log("==== home page receive friendadded " + msg);
      this.insertFriend(msg);
    });
  }

  ionViewWillEnter() {
    console.log("=== home page ionViewWillEnter");
    this.initializeBackButtonCustomHandler();
  }

  ionViewWillLeave() {
    console.log("=== home page ionViewWillLeave");
    // Unregister the custom back button action for this page
    this.unregisterBackButtonAction && this.unregisterBackButtonAction();
  }

  ionViewWillUnload() {
    console.log("=== home page ionViewWillUnload");
  }

  initializeBackButtonCustomHandler(): void {
    this.unregisterBackButtonAction = this.platform.registerBackButtonAction(event => {
      console.log("=== click back btn");
        if (this.isScanning) {
          this.isScanning = false;
        } else {
          if (this.navCtrl.canGoBack()) {
            this.navCtrl.pop();
          } else {
            this.chatService.stop();
            navigator['app'].exitApp();
          }
        }
    }, 101);
  }

  stop() {
    this.chatService.stop();
  }

  goQrCode() {
    var qrcode = this.chatService.getAddress();
    console.log("=== my address: " + qrcode);
    console.log("=== my uid: " + this.chatService.getUid());
    this.navCtrl.push(QrcodePage, {
        qrdata: qrcode
    });
  }

  scanCode() {
    this.isScanning = true;
    this.barcodeScanner.scan().then(barcodeData => {
      this.scannedCode = barcodeData.text;
      if (this.scannedCode == "") return;
      this.presentConfirm();
    }, (err) => {
        console.log('Error: ', err);
    });
  }

  itemSelected(item) {
    if (item.online == 0) {
      let alert = this.alertCtrl.create({
        title: 'Tips',
        message: 'Friend is not online',
        buttons: [
          {
            text: 'Ok',
            handler: () => {
              console.log("=== home page tips click");
            }
          }
        ]
      });
      alert.present();
      return;
    }
    this.navCtrl.push(ChatPage, {
        item: item
    });
  }

  presentConfirm() {
    let alert = this.alertCtrl.create({
        title: 'Confirm purchase',
        message: 'add ' + this.scannedCode + '?',
        buttons: [
          {
            text: 'Cancel',
            role: 'cancel',
            handler: () => {
              console.log('Cancel clicked');
            }
          },
          {
            text: 'Ok',
            handler: () => {
              let uid = this.chatService.addFriend(this.scannedCode);
              this.insertFriend(uid);
            }
          }
        ]
    });
    alert.present();
  }

  friendConnectionChanged(msg) {
    for (let i = 0; i < this.items.length; i++) {
      if (this.items[i].uid == msg.uid) {
        this.items[i].online = msg.online;
        break;
      }
    }

  }

  insertFriend(uid) {
    let friend = {
      uid: uid,
      online: 0,
      label: null
    }

    this.items.push(friend);
  }

  deleteFriend(event, uid) {
    event.stopPropagation();
    let alert = this.alertCtrl.create({
        title: 'Confirm purchase',
        message: 'delete ' + uid + '?',
        buttons: [
          {
            text: 'Cancel',
            role: 'cancel',
            handler: () => {
              console.log('Cancel clicked');
            }
          },
          {
            text: 'Ok',
            handler: () => {
              this.delete(uid);
            }
          }
        ]
    });
    alert.present();

  }

  delete(uid) {
    this.chatService.deleteFriend(uid);
    for (let i = 0; i < this.items.length; i++) {
      if (this.items[i].uid == uid) {
        this.items.splice(i, 1);
        break;
      }
    }

  }

  presentSetNickname(item) {
    let alert = this.alertCtrl.create({
      title: 'Set nickname',
      inputs: [
        {
          name: 'nickname',
          placeholder: 'nickname'
        }
      ],
      buttons: [
        {
          text: 'Cancel',
          role: 'cancel',
          handler: data => {
            console.log('Cancel clicked');
          }
        },
        {
          text: 'Ok',
          handler: data => {
            console.log('=== Ok clicked');
            this.chatService.setLabel(item.uid, data.nickname);
            item.label = data.nickname;
          }
        }
      ]
    });
    alert.present();
  }

}
