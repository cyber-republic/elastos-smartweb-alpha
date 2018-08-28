import { NgModule, ErrorHandler } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { IonicApp, IonicModule, IonicErrorHandler } from 'ionic-angular';
import { MyApp } from './app.component';

import { ComponentsModule } from '../components/components.module'; // 引入模块

import { HomePage } from '../pages/home/home';
import { ManagePage } from '../pages/manage/manage';
import { InfoPage } from '../pages/info/info';

import { File } from '@ionic-native/file';
import { FileChooser } from "@ionic-native/file-chooser";
import { FilePath } from "@ionic-native/file-path";
import { SplashScreen } from '@ionic-native/splash-screen';
import { SQLite } from '@ionic-native/sqlite';
import { StatusBar } from '@ionic-native/status-bar';
import { Zip } from '@ionic-native/zip';

@NgModule({
  declarations: [
    MyApp,
    HomePage,
    ManagePage,
    InfoPage
  ],
  imports: [
    BrowserModule,
    ComponentsModule,
    // IonicModule.forRoot(MyApp)
    IonicModule.forRoot(MyApp,{
      tabsHideOnSubPages: 'true', //隐藏全部子页面 tabs
      backButtonText: '' /*配置返回按钮*/
    })
  ],
  bootstrap: [IonicApp],
  entryComponents: [
    MyApp,
    HomePage,
    ManagePage,
    InfoPage
  ],
  providers: [
    File,
    FileChooser,
    FilePath,
    SplashScreen,
    SQLite,
    StatusBar,
    Zip,
    {provide: ErrorHandler, useClass: IonicErrorHandler}
  ]
})
export class AppModule {}
