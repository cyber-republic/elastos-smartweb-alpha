import { Component } from '@angular/core';
import {Base} from '../Base';
import {HomePage} from '../home/home';
// import * as _ from 'lodash';

@Component({
  selector: 'page-login',
  templateUrl: 'main.html'
})
export class LoginPage extends Base {
  private main = 'sign_in';

  private signup_param: any;
  private signin_param: any;

  _init(){
    this.resetSignUp();
    this.resetSignIn();
  }

  resetSignUp(){
    this.signup_param = {
      username : '',
      password : '',
      nickname : ''
    };
  }
  resetSignIn(){
    this.signin_param = {
      username : '',
      password : ''
    };
  }
  async actionDidLogin(){
    this.showLoading('login ...');
    

    return false;

    // const data = this.signin_param;
    // const key = data.username;

    // if(!data.username || !data.password){
    //   this.warning('invalid param');
    //   return false;
    // }

    // this.showLoading();
    // const rs = await this.didService.getData(key);
    // if(!rs || !rs.password || rs.password !== data.password){
    //   this.hideLoading();
    //   this.warning('incorrect username or password');
    //   return false;
    // }
    // this.hideLoading();
    // alert(rs.nickname);
  }

  async ionViewDidLoad(){
    this.main = 'sign_in';
    
    // await this.didService.startSyncNode();
  }

  async testDID(){
    
  }

  async signup(){
    
  }

}
