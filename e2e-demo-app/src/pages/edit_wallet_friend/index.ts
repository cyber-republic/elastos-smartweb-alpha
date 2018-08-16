import { Component, ViewChild } from '@angular/core';

import {Base} from '../Base';
import * as _ from 'lodash';



@Component({
  selector: 'page-edit_wallet_friend',
  templateUrl: 'main.html'
})
export class EditWalletFriendPage extends Base {
  private type;
  private param:any;

  closeModal(){
    this.viewCtrl.dismiss();
  }

  _init(){
    this.type = this.navParam.get('type');
    if(this.type === 'add'){
      this.param = {
        name : '',
        address : ''
      };
    }
    else{
      this.param = this.navParam.get('info');
    }
  }

  async confirm(){
    this.viewCtrl.dismiss({
      type : this.type,
      param : this.param
    });
  }
}
