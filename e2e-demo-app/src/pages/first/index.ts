import { Component } from '@angular/core';
import {Base} from '../Base';

import {HomePage} from '../home/home';

@Component({
  selector: 'page-first',
  templateUrl: 'main.html'
})
export class FirstPage extends Base {
  goTo(name){
    let select;
    if(name === 'ditto'){
      select = 0;
    }
    else if(name === 'ipfs'){
      select = 1;
    }
    else if(name === 'wallet'){
      select = 2;
    }

    this.navCtrl.push(HomePage, {select});
  }

  async test(){
    console.log(11111);
    fetch('http://127.0.0.1/abc').then((res)=>{
      console.log(res.type);
    }).catch((e)=>{
      console.log(e);
    });

  }

  async ionViewDidLoad_AfterLogin(){
    // await this.wallet_execute('getAllMasterWallets');
    // await this.wallet_execute('getAllSubWallets');
  }

  async test1(){
    console.log(2222);
    const x = new Image();
    x.src = 'https://www.baidu.com';
    x.onload = ()=>{
      console.log(2222222);
    }
 
  }
}
