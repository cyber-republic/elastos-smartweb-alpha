import {Component, OnInit} from '@angular/core';
import {BaseComponent} from './../../../app/BaseComponent';


@Component({
  selector: 'app-exprot-prikey',
  templateUrl: './exprot-prikey.component.html'
})
export class ExprotPrikeyComponent extends BaseComponent implements OnInit {

  public backupWalletPlainText:any;
  exprotObj = {
    name: '',
    backupPassWord: '',
    reBackupPassWord: '',
    payPassword: ''
  };

  ngOnInit() {
    this.setTitleByAssets('text-wallet-export');

  }

  onWalletDatainit(){
    this.exprotObj.name = this.walletData.name;
  }

  checkparms(){

    if(this.isNull(this.exprotObj.backupPassWord)){
       this.messageBox("text-wallet-pwd");
       return false;
    }

    if(this.exprotObj.backupPassWord != this.exprotObj.reBackupPassWord){
      this.messageBox("text-passworld-compare");
       return false;
    }

    if(this.isNull(this.exprotObj.payPassword)){
      this.messageBox("text-pay-passworld-input");
      return false;
    }

     return true;
  }

  onDown() {
     if(this.checkparms()){
         this.onExport();
     }
  }

  onExport() {
    this.walletManager.exportWalletWithKeystore(this.exprotObj.backupPassWord,this.exprotObj.payPassword,(reslut) => {
                 this.backupWalletPlainText = reslut.keystoreContent;
    });
  }

  onCopay(){
    this.native.copyClipboard(this.backupWalletPlainText).then(()=>{
             this.toast('text-copied-to-clipboard');
    }).catch(()=>{

    });
  }

}
