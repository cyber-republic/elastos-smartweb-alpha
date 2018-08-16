import { Component } from '@angular/core';
import {Base} from '../Base';
import {DittoListPage} from '../ditto_list';

@Component({
  selector: 'page-ditto_config',
  templateUrl: 'main.html'
})
export class DittoConfigPage extends Base {
  private param: any;

  _init(){
    this.reset();
  }

  reset(){
    this.param = {
      address : '',
      username : 'admin',
      password : '111111'
    };
  }

  scan(){
    this.scanBarcode((flag, data: any)=>{
      if(flag){
        this.param.address = data.text.replace('elastos:', '');
      }
      
    });
  }

  confirm(){
    if(!this.param.username || !this.param.password){
      this.warning('invalid username or password');
      return false;
    }

    if(!this.param.address){
      this.warning('please scan server qrcode to input address');
      return false;
    }

    this.navCtrl.push(DittoListPage, this.param);
  }

}
