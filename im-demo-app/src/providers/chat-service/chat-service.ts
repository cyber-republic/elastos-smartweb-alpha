

import { Injectable } from '@angular/core';
import { Events } from 'ionic-angular';
import { AlertController } from 'ionic-angular';

declare let Carrier: any;
//declare let Friend[]: any;

export class ChatMessage {
  messageId: string;
  userId: string;
  userAvatar: string;
  toUserId: string;
  time: number | string;
  message: string;
  status: string;
}

@Injectable()
export class ChatService {

  messageList: ChatMessage[] = [];
  carrier = null;

  interval = 0;

  constructor(private events: Events, private alertCtrl: AlertController) {
    this.carrier = new Carrier();
    this.carrier.Start('/data/data/org.elastos.desktop/files');

    this.interval = setInterval(this.receiveMessage.bind(this), 500);
  }

  receiveMessage() {
      var message = this.carrier.recevMessage();
      if (typeof(message) == 'undefined') return;

      console.log("=== receive message: " + message);
      var msg = JSON.parse(message);
      if (msg.callback == 'OnReady') {
        this.OnReady();
      } else if (msg.callback == 'OnConnectionChanged') {
        this.OnConnectionChanged(msg.para1);
      } else if (msg.callback == 'OnFriendConnetionChanged') {
        this.OnFriendConnetionChanged(msg.para1, msg.para2);
      } else if (msg.callback == 'OnFriendRequest') {
        this.OnFriendRequest(msg.para1, msg.para2);
      } else if (msg.callback == 'OnMessageReceived') {
        this.OnMessageReceived(msg.para1, msg.para2);
      }
  }

  OnReady() {
    console.log("=== js OnReady ");
    this.events.publish('chat:ready', 'ready', Date.now());
  }

  OnConnectionChanged(online) {
    //alert("OnConnectionChanged:"+online);
    console.log("=== js OnConnectionChanged " + online);

    let msg = {
      online: online
    }

    this.events.publish('chat:connectionchanged', msg, Date.now());
    console.log("=== js OnConnectionChanged end");
  }

  OnFriendConnetionChanged(uid, online) {
    console.log("=== js OnFriendConnetionChanged " + uid);
    let msg = {
      uid: uid,
      online: online
    }

    this.events.publish('chat:friendonline', msg, Date.now());
  }

  OnFriendRequest(uid, hello) {
    console.log("=== js OnFriendRequest " + uid);
    let alert = this.alertCtrl.create({
        title: 'Confirm purchase',
        message: uid + ' saied: ' + hello,
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
              this.accpetFriendRequest(uid);
              setTimeout(() => {
                this.events.publish('chat:friendadded', uid, Date.now());
              }, 200);
            }
          }
        ]
    });
    alert.present();
  }

  OnMessageReceived(uid, msg) {
    const newMsg: ChatMessage = {
      messageId: Date.now().toString(),
      userId: uid,
      userAvatar: './assets/imgs/avatar.png',
      toUserId: this.getUid(),
      time: Date.now(),
      message: msg,
      status: 'success'
    };

    console.log("=== service receive new message: " + msg);

    setTimeout(() => {
        this.events.publish('chat:received', newMsg, Date.now())
    }, 200);

  }

  accpetFriendRequest(uid) {
    this.carrier.AccpetFriendRequest(uid);
  }

  getAddress(): string {
    return this.carrier.GetAddress();
  }

  getUid(): string {
    return this.carrier.GetUserid();
  }

  getFriends(): any[] {
    console.log("=== getFriends");
    return this.carrier.GetFriends();
  }

  addFriend(address): string {
    return this.carrier.AddFriend(address, "hello");
  }

  deleteFriend(friend) {
    this.carrier.RemoveFriend(friend);
  }

  stop() {
    console.log("=== js call carrier stop");
    this.carrier.Stop();
    clearInterval(this.interval);
  }

  mockNewMsg(msg) {
    const mockMsg: ChatMessage = {
      messageId: Date.now().toString(),
      userId: msg.toUserId,
      userAvatar: './assets/imgs/avatar.png',
      toUserId: msg.userId,
      time: Date.now(),
      message: msg.message,
      status: 'success'
    };

    setTimeout(() => {
      this.events.publish('chat:received', mockMsg, Date.now())
    }, Math.random() * 1800)
  }

  getMsgList(): ChatMessage[] {
    return this.messageList;
  }

  sendMsg(msg: ChatMessage) {

    return new Promise(resolve => {
      this.carrier.SendMessage(msg.toUserId, msg.message);
      resolve(msg);
    });
    //return new Promise(resolve => setTimeout(() => resolve(msg), Math.random() * 1000))
    //.then(() => this.mockNewMsg(msg));
  }

  setLabel(uid, label) {
    console.log('=== set friend label uid: ' + uid + ' label: ' + label);
    this.carrier.SetFriendLabel(uid, label);
  }

}

