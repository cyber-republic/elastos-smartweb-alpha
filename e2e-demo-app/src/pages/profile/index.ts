import { Component } from '@angular/core';
import {Base} from '../Base';
import * as _ from 'lodash';

@Component({
  selector: 'page-profile',
  templateUrl: 'main.html'
})
export class ProfilePage extends Base {
  
  logout(){
    this.userService.logout();

    location.reload();
  }

  showLangActionSheet(){
    const actionSheet = this.actionSheetCtrl.create({
      title : this.getLang('setting.0002'),
      buttons: [
        {
          text : 'English',
          handler : ()=>{
            this.changeLang('en');
          }
        },
        {
          text : '中文',
          handler : ()=>{
            this.changeLang('zh-cn')
          }
        }
      ]
    });

    actionSheet.present();
  }

  changeLang(lang){
    this.translateService.use(lang);
    localStorage.setItem('current_lang', lang);
    // location.reload(true);
  }

}
