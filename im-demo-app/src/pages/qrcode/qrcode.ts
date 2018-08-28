import { Component } from '@angular/core';
import { IonicPage, NavController, NavParams } from 'ionic-angular';
import { BarcodeScanner } from '@ionic-native/barcode-scanner';

/**
 * Generated class for the QrcodePage page.
 *
 * See https://ionicframework.com/docs/components/#navigation for more info on
 * Ionic pages and navigation.
 */

@Component({
  selector: 'page-qrcode',
  templateUrl: 'qrcode.html',
})
export class QrcodePage {

  createdCode = null;

  constructor(public navCtrl: NavController, public navParams: NavParams) {
    this.createdCode = navParams.get('qrdata');
  }

  ionViewDidLoad() {
    console.log('ionViewDidLoad QrcodePage');
  }

}
