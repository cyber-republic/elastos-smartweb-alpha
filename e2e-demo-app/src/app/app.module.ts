import { BrowserModule } from '@angular/platform-browser';
import { ErrorHandler, NgModule } from '@angular/core';
import { IonicApp, IonicErrorHandler, IonicModule, Platform } from 'ionic-angular';
import { SplashScreen } from '@ionic-native/splash-screen';
import { StatusBar } from '@ionic-native/status-bar';
import { TranslateModule, TranslateLoader } from '@ngx-translate/core';
import {HttpClientModule, HttpClient} from '@angular/common/http';
import { HttpModule } from '@angular/http';
import { HTTP } from '@ionic-native/http';
import { Observable } from 'rxjs/Observable';
import 'rxjs/add/observable/of';
import { FileChooser } from '@ionic-native/file-chooser';
import { File } from '@ionic-native/file';
import { FilePath } from '@ionic-native/file-path';
import {QRCodeModule} from 'angularx-qrcode';
import { BarcodeScanner } from '@ionic-native/barcode-scanner';

import { MyApp } from './app.component';
import {FirstPage} from '../pages/first';
import {HomePage} from '../pages/home/home';
import {Base} from '../pages/Base';
import {LoginPage} from '../pages/login';
import {DittoListPage} from '../pages/ditto_list';
import {ProfilePage} from '../pages/profile';
import {DittoDetailPage} from '../pages/ditto_detail';
import {WalletInfoPage} from '../pages/wallet_info';
import {WalletSettingPage} from '../pages/wallet_setting';
import {WalletDetailPage} from '../pages/wallet_detail';
import {IpfsInfoPage} from '../pages/ipfs_info';
import {FileViewPage} from '../pages/file_view';
import {EditWalletFriendPage} from '../pages/edit_wallet_friend';
import {DittoConfigPage} from '../pages/ditto_config';
import {WalletIdChainPage} from '../pages/wallet_idchain';
import {WalletDidListPage} from '../pages/wallet_did_list';

declare var require;

const Lang = {
  en : require('../assets/i18n/en.json'),
  'zh-cn' : require('../assets/i18n/zh-cn.json')
};

const list = [
  MyApp,
  Base,
  LoginPage,
  FirstPage,
  HomePage,
  DittoListPage,
  ProfilePage,
  DittoDetailPage,
  WalletInfoPage,
  WalletSettingPage,
  IpfsInfoPage,
  FileViewPage,
  WalletDetailPage,
  EditWalletFriendPage,
  DittoConfigPage,
  WalletIdChainPage,
  WalletDidListPage
];



export const createTranslateLoader = class implements TranslateLoader {
  getTranslation(lang: string): Observable<any> {
    return Observable.of(Lang[lang]);
  }
}

@NgModule({
  declarations: [
    ...list,
  ],
  imports: [
    BrowserModule,
    HttpModule,
    HttpClientModule,
    IonicModule.forRoot(MyApp, {
      iconMode: 'ios',
      mode: 'ios'
    }),
    TranslateModule.forRoot({
      loader: {
          provide: TranslateLoader,
          useClass: createTranslateLoader
      },
    }),
    QRCodeModule
  ],
  bootstrap: [IonicApp],
  entryComponents: list,
  providers: [
    StatusBar,
    SplashScreen,
    FileChooser,
    FilePath,
    File,
    HTTP,
    {provide: ErrorHandler, useClass: IonicErrorHandler},
    BarcodeScanner
  ]
})
export class AppModule {}
