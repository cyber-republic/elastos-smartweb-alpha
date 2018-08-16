import { Component, ViewChild } from '@angular/core';

import {Base} from '../Base';
import {WalletSettingPage} from '../wallet_setting';
import * as _ from 'lodash';


const C = {
  info : 'settting.info',
  friends : 'setting.friends'
};

@Component({
  selector: 'page-wallet_did_list',
  templateUrl: 'main.html'
})
export class WalletDidListPage extends Base {
  private did_list: any[];

  _init(){
    this.did_list = [];
  }

  async ionViewDidLoad_AfterLogin(){
    await this.fetchList();
    this.wallet_execute('registerIdListener', 'IdChain').then((data)=>{
      console.log("createDID registerIdListener data "+ JSON.stringify(data));
    })
  }

  async fetchList(){
    const rs: any = await this.wallet_execute('getDIDList');
    const list = JSON.parse(rs.list);

    

    this.did_list = list;
  }

  goSettingPage(item){
    this.navCtrl.push(WalletSettingPage, {
      did : item
    });
  }

  async addDID(){
    await this.didService.createNewDID();

    await this.fetchList();
  }

  async showMenu(did){
    const actionSheet = this.actionSheetCtrl.create({
      title : '',
      buttons: [
        {
          text : 'Remove',
          role : 'destructive',
          handler : ()=>{
            this.showLoading();
            this.wallet_execute('destoryDID', did).then(async ()=>{
              await this.fetchList();
              this.hideLoading();
            }) 

          }
        }
      ]
    });

    actionSheet.present();
  }




}
