import { Component, ViewChild } from '@angular/core';

import {Base} from '../Base';
import * as _ from 'lodash';
import {EditWalletFriendPage} from '../edit_wallet_friend';

const C = {
  info : 'settting.info',
  friends : 'setting.friends'
};

@Component({
  selector: 'page-wallet_setting',
  templateUrl: 'main.html'
})
export class WalletSettingPage extends Base {
  private info: any;
  private friends: any[];
  private did;
  
  _init(){
    this.info = {
      nickName : ''
    };
    this.friends = [];
  
    this.did = this.navParam.get('did');
  }

  async ionViewDidLoad_AfterLogin(){
    this.showLoading();

    const info = await this.didService.getData(this.did, C.info);
    if(info && info.nickName){
      this.info.nickName = info.nickName;
    }

    const list = await this.didService.getData(this.did, C.friends);
    if(list){
      this.friends = list;
    }

    this.hideLoading();
  }

  async editNickName(){
    const alert = this.alertCtrl.create({
      title : 'Set Nick Name',
      inputs : [
        {
          name : 'name',
          placeholder : 'Nick Name'
        }
      ],
      buttons : [
        {
          text : 'Cancel',
          role : 'cancel'
        },
        {
          text : 'Confirm',
          handler : (data)=>{
            const info = _.clone(this.info);
            info.nickName = data.name;
            if(!data.name){
              this.warning('invalid name');
              return false;
            }

            this.showLoading();
            this.didService.saveData(this.did, C.info, info).then(()=>{
              this.hideLoading();
              this.info.nickName = data.name;
            }).catch((e)=>{
              this.warning(e);
              this.hideLoading();
            })
          }
        }
      ]
    });
    alert.present();
  }

  addFriend(){
    this.showModal('add', {}, 0);
  }

  editFriend(item, index){
    this.showModal('edit', _.clone(item), index);
  }

  showModal(type, info={}, index){
    const modal = this.modalCtrl.create(EditWalletFriendPage, {
      type,
      info
    });
    modal.onDidDismiss(async (data)=>{
      if(!data){
        return false;
      }
      if(data.type === 'add'){
        this.friends.push(data.param);
        await this.didService.saveData(this.did, C.friends, this.friends);
      }
      else if(data.type === 'edit'){
        this.friends[index] = data.param;
        await this.didService.saveData(this.did, C.friends, this.friends);
      }
    });
    modal.present();
  }
}
