import { Component } from '@angular/core';
import { Platform } from 'ionic-angular';
import { StatusBar } from '@ionic-native/status-bar';
import { SplashScreen } from '@ionic-native/splash-screen';
import { TranslateService } from '@ngx-translate/core';

import {Log} from '../utility/Log';

import {FirstPage} from '../pages/first';

@Component({
  templateUrl: 'app.html'
})
export class MyApp {
  rootPage:any = null;

  constructor(platform: Platform, statusBar: StatusBar, splashScreen: SplashScreen, public translateService: TranslateService) {
    this.rootPage = FirstPage;
    platform.ready().then(() => {
      // Okay, so the platform is ready and our plugins are available.
      // Here you can do any higher level native things you might need.
      statusBar.styleDefault();
      statusBar.overlaysWebView(false);
      splashScreen.hide();
      
      Log.info('platforms', platform.platforms());
      // console.log(translateService.getBrowserCultureLang())
      translateService.setDefaultLang('en');

      let lang = localStorage.getItem('current_lang');
      if(!lang){
        lang = 'en'
        localStorage.setItem('current_lang', lang);
      }
      translateService.use(lang)
    });
  }
}

