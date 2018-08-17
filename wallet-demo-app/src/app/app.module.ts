import { BrowserModule } from '@angular/platform-browser';
import { ErrorHandler, NgModule } from '@angular/core';
import { IonicApp, IonicErrorHandler, IonicModule } from 'ionic-angular';
import { SplashScreen } from '@ionic-native/splash-screen';
import { StatusBar } from '@ionic-native/status-bar';
import {HttpModule} from '@angular/http';
import {WeUiModule} from 'ngx-weui';
import {TranslateLoader, TranslateModule} from '@ngx-translate/core';
import {Observable} from 'rxjs/Observable';

import {zh} from './../assets/i18n/zh';
import {en} from './../assets/i18n/en';


import {QRCodeModule} from 'angularx-qrcode';

import {FormsModule} from '@angular/forms';
import { IonicStorageModule } from '@ionic/storage';



/**provider*/
import {Config} from './../providers/Config';
import {LocalStorage} from '../providers/Localstorage';
import { Clipboard } from '@ionic-native/clipboard';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { BackupProvider } from '../providers/backup';
import { HttpService } from '../providers/HttpService';
import { PopupProvider } from '../providers/popup';
import { DataManager } from '../providers/DataManager';

/**pages*/
import {AppComponent} from './app.component';
import {HeaderComponent} from './header/app.header';
import {TabsComponent} from './../pages/tabs/tabs.component';
import {HomeComponent} from './../pages/tabs/home/home.component';
import {MyComponent} from './../pages/tabs/my/my.component';
import {LauncherComponent} from '../pages/launcher/launcher.component';
import {ManagerComponent} from '../pages/wallet/manager/manager.component';
import {PaypasswordResetComponent} from '../pages/wallet/paypassword-reset/paypassword-reset.component';
import {ImportComponent} from '../pages/wallet/import/import.component';
import {ExprotPrikeyComponent} from '../pages/wallet/exprot-prikey/exprot-prikey.component';
import {MnemonicComponent} from '../pages/mnemonic/mnemonic.component';
import {WriteComponent} from '../pages/mnemonic/write/write.component';
import {AddressComponent} from '../pages/wallet/address/address.component';
import {MultiSignedComponent} from '../pages/multi-signed/multi-signed.component';
import {JoinComponent} from '../pages/multi-signed/join/join.component';
import {ContactsComponent} from '../pages/contacts/contacts.component';
import {SettingsComponent} from '../pages/universal/settings/settings.component';
import {ResultComponent} from '../pages/universal/result/result.component';
import {CoinComponent} from '../pages/coin/coin.component';
import {RecordComponent} from '../pages/coin/record/record.component';
import {TransferComponent} from '../pages/coin/transfer/transfer.component';
import {ReceiveComponent} from '../pages/coin/receive/receive.component';
import {RechargeComponent} from '../pages/coin/recharge/recharge.component';
import {CoinSelectComponent} from '../pages/coin/coin-select/coin-select.component';
import {WithdrawComponent} from '../pages/coin/withdraw/withdraw.component';
import {ContactListComponent} from '../pages/contacts/contact-list/contact-list.component';
import {ContactCreateComponent} from '../pages/contacts/contact-create/contact-create.component';
import {CoinListComponent} from '../pages/coin/coin-list/coin-list.component';
import {WalletCreateComponent} from '../pages/wallet/wallet-create/wallet-create.component';
import {WalletInfoComponent} from '../pages/wallet/wallet-info/wallet-info.component';
import {Native} from '../providers/Native';
import {Logger} from '../providers/Logger';
import {BaseComponent} from './BaseComponent';
import {RecordinfoComponent} from '../pages/coin/recordinfo/recordinfo.component';
import {AboutComponent} from '../pages/other/about/about.component';
import {HelpComponent} from '../pages/other/help/help.component';
import {NoticeComponent} from '../pages/other/notice/notice.component';
import {ChangePwdComponent} from '../pages/other/change-pwd/change-pwd.component';
import {ChangeNameComponent} from '../pages/other/change-name/change-name.component';
import {WalletManager} from "../providers/WalletManager";
import {BarcodeScanner} from "@ionic-native/barcode-scanner";
import {FileChooser} from "@ionic-native/file-chooser";

import {TestJniComponent} from '../pages/testjni/testjni.component';
import {kycSelectTypeComponent} from "../pages/id/kyc/selecttype/create"

/*id相关页面*/
import {IdLauncherComponent} from '../pages/id/launcher/launcher';
import {IdHomeComponent} from '../pages/id/home/home';
import {IdCreateComponent} from '../pages/id/create/create';
import {IdImportComponent} from '../pages/id/import/import';
import {IdManagerComponent} from '../pages/id/manager/manager';
import {IdKycPersonComponent} from '../pages/id/kyc/person/person';
import {IdKycCompanyComponent} from '../pages/id/kyc/company/company';
import {IdKycResultComponent} from '../pages/id/kyc/result/result';
import {IdAppListComponent} from '../pages/id/app-list/app-list';
import {IdResultComponent} from '../pages/id/result/result';
import {KycOperationPage} from '../pages/id/kyc/kyc-operation/kyc-operation';
import {KycOrderPage} from '../pages/id/kyc/kyc-order/kyc-order';
import {CompanyWriteChainPage} from '../pages/id/kyc/company-write-chain/company-write-chain';
import {PersonWriteChainPage} from '../pages/id/kyc/person-write-chain/person-write-chain';
/*id相关页面*/

/** 通过类引用方式解析国家化文件 */
export class CustomTranslateLoader implements TranslateLoader {
  public getTranslation(lang: string): Observable<any> {
    return Observable.create(observer => {
      switch (lang) {
        case 'zh':
        default:
          observer.next(zh);
          break;
        case 'en':
          observer.next(en);
      }

      observer.complete();
    });
  }
}

export function TranslateLoaderFactory() {
  return new CustomTranslateLoader();
}


@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    BaseComponent,
    TabsComponent,
    HomeComponent,
    MyComponent,
    LauncherComponent,
    ManagerComponent,
    PaypasswordResetComponent,
    ImportComponent,
    ExprotPrikeyComponent,
    MnemonicComponent,
    WriteComponent,
    AddressComponent,
    MultiSignedComponent,
    JoinComponent,
    ContactsComponent,
    SettingsComponent,
    ResultComponent,
    CoinComponent,
    RecordComponent,
    TransferComponent,
    ReceiveComponent,
    RechargeComponent,
    CoinSelectComponent,
    WithdrawComponent,
    ContactListComponent,
    ContactCreateComponent,
    CoinListComponent,
    WalletCreateComponent,
    WalletInfoComponent,
    RecordinfoComponent,
    AboutComponent,
    HelpComponent,
    NoticeComponent,
    ChangePwdComponent,
    ChangeNameComponent,
    TestJniComponent,
    IdLauncherComponent,
    IdHomeComponent,
    IdCreateComponent,
    IdImportComponent,
    IdManagerComponent,
    IdKycPersonComponent,
    IdKycCompanyComponent,
    IdKycResultComponent,
    IdAppListComponent,
    IdResultComponent,
    kycSelectTypeComponent,
    KycOperationPage,
    KycOrderPage,
    CompanyWriteChainPage,
    PersonWriteChainPage
  ],
  imports: [
    BrowserModule,
    HttpModule,
    FormsModule,
    TranslateModule.forRoot({
      loader: {
        provide: TranslateLoader,
        useFactory: (TranslateLoaderFactory)
      }
    }),
    QRCodeModule,
    BrowserAnimationsModule,
    IonicModule.forRoot(AppComponent,{tabsHideOnSubPages: 'true'}),
    IonicStorageModule.forRoot({
      name: '__walletdb',
      driverOrder: ['localstorage','indexeddb', 'sqlite', 'websql']
    }),
    WeUiModule.forRoot()
  ],
  bootstrap: [IonicApp],
  entryComponents: [
    AppComponent,
    HeaderComponent,
    BaseComponent,
    TabsComponent,
    HomeComponent,
    MyComponent,
    LauncherComponent,
    ManagerComponent,
    PaypasswordResetComponent,
    ImportComponent,
    ExprotPrikeyComponent,
    MnemonicComponent,
    WriteComponent,
    AddressComponent,
    MultiSignedComponent,
    JoinComponent,
    ContactsComponent,
    SettingsComponent,
    ResultComponent,
    CoinComponent,
    RecordComponent,
    TransferComponent,
    ReceiveComponent,
    RechargeComponent,
    CoinSelectComponent,
    WithdrawComponent,
    ContactListComponent,
    ContactCreateComponent,
    CoinListComponent,
    WalletCreateComponent,
    WalletInfoComponent,
    RecordinfoComponent,
    AboutComponent,
    HelpComponent,
    NoticeComponent,
    ChangePwdComponent,
    ChangeNameComponent,
    TestJniComponent,
    IdLauncherComponent,
    IdHomeComponent,
    IdCreateComponent,
    IdImportComponent,
    IdManagerComponent,
    IdKycPersonComponent,
    IdKycCompanyComponent,
    IdKycResultComponent,
    IdAppListComponent,
    IdResultComponent,
    kycSelectTypeComponent,
    KycOperationPage,
    KycOrderPage,
    CompanyWriteChainPage,
    PersonWriteChainPage
  ],
  providers: [
    StatusBar,
    SplashScreen,
    BarcodeScanner,
    FileChooser,
    Clipboard,
    Config,
    LocalStorage,
    Native,
    Logger,
    HeaderComponent,
    WalletManager,
    BackupProvider,
    HttpService,
    PopupProvider,
    DataManager,
    {provide: ErrorHandler, useClass: IonicErrorHandler}
  ]
})
export class AppModule {}
