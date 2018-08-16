import { Component } from '@angular/core';
import {DomSanitizer} from '@angular/platform-browser';
import { 
  LoadingController, NavController, NavParams, 
  AlertController, ToastController, ActionSheetController, ModalController, ViewController
} from 'ionic-angular';
import { TranslateService } from '@ngx-translate/core';
import { HTTP } from '@ionic-native/http';
import { Platform } from 'ionic-angular';
import { FileChooser } from '@ionic-native/file-chooser';
import { File } from '@ionic-native/file';
import { FilePath } from '@ionic-native/file-path';
import { BarcodeScanner } from '@ionic-native/barcode-scanner';

import {DIDService} from '../service/DIDService';
import {DittoService} from '../service/DittoService';
import {WalletService} from '../service/WalletService';
import {UserService} from '../service/UserService';
import {IpfsService} from '../service/IpfsService';

import * as _ from 'lodash';

@Component({
  template: ''
})
export class Base {
  private _loading;
  private _loading_show: boolean = false;
  protected didService: DIDService;
  protected dittoService: DittoService;
  protected walletService: WalletService;
  protected ipfsService: IpfsService;

  protected userService: UserService;

  constructor(
    public loadingCtrl: LoadingController,
    public navCtrl: NavController,
    public navParam: NavParams,
    public alertCtrl: AlertController,
    public toastCtrl: ToastController,
    public translateService: TranslateService,
    public actionSheetCtrl: ActionSheetController,
    public _http: HTTP,
    public modalCtrl: ModalController,
    public viewCtrl: ViewController,
    public _sanitizer: DomSanitizer,
    public _plt: Platform,
    public _fileChooser: FileChooser,
    public _file: File,
    public _filePath: FilePath,
    private barcodeScanner: BarcodeScanner
  ){
    this.buildDIDService();
    this.buildDittoService();
    this.buildWalletService();
    this.userService = new UserService();
    this.ipfsService = new IpfsService();

    this._init();
  }

  _init(){

  }

  protected showLoading(str: string = 'fetch data...'): void{
    if(this._loading_show){
      // this.hideLoading();
      return;
    }
    this._loading = this.loadingCtrl.create({
      content : str
    });
    this._loading.present();
    this._loading_show = true;
  }
  protected hideLoading(): void{
    if(!this._loading_show){
      return;
    }
    if(this._loading){
      this._loading.dismiss();
    }
    this._loading_show = false;
  }

  protected buildDIDService(): DIDService{
    if(!this.didService){
      this.didService = DIDService.get(this._plt.is('cordova'));
    }
    return this.didService;
  }
  protected buildDittoService(): DittoService{
    if(!this.dittoService){
      this.dittoService = DittoService.get(this._plt.is('cordova'));
    }
    return this.dittoService;
  }
  protected buildWalletService(): WalletService{
    if(!this.walletService){
      this.walletService = WalletService.get(this._plt.is('cordova'));
    }

    return this.walletService;
  }

  async ionViewDidLoad(){
    await this.ionViewDidLoad_AfterLogin();
    // if(true){
      
    // }
    // else{
    //   this.ionViewDidLoad_BeforeLogin();
    // }
  }
  ionViewWillEnter(){}
  ionViewDidEnter(){}
  ionViewWillLeave(){}
  ionViewDidLeave(){}
  ionViewWillUnload(){}
  ionViewCanEnter(){}
  ionViewCanLeave(){}

  async ionViewDidLoad_AfterLogin(){}
  async ionViewDidLoad_BeforeLogin(){}

  protected warning(msg){

    const alert = this.alertCtrl.create({
      title : 'Warning',
      subTitle : msg,
      buttons : ['Dismiss']
    });
    alert.present();
  }

  protected toast(msg){
    const toast = this.toastCtrl.create({
      message : msg,
      duration : 3000,
      position : 'bottom'
    });
    toast.present();
  }

  protected getLang(key){
    return _.get(this.translateService.get(key), 'value');
  }

  protected sanitize(url){
    return this._sanitizer.bypassSecurityTrustUrl(url);
  }

  protected async wallet_execute(fnName, ...args){
    return this.didService.execute(fnName, ...args);
  }

  protected scanBarcode(callback){
    this.barcodeScanner.scan().then((data)=>{
      callback(true, data);
    }).catch((err)=>{
      callback(false, err);
    })
  }
};