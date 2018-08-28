import { BrowserModule } from '@angular/platform-browser';
import { ErrorHandler, NgModule } from '@angular/core';
import { IonicApp, IonicErrorHandler, IonicModule } from 'ionic-angular';
import { SplashScreen } from '@ionic-native/splash-screen';
import { StatusBar } from '@ionic-native/status-bar';
import { QRCodeModule } from 'angular2-qrcode';
import { LongPressModule } from 'ionic-long-press';

import { NgxQRCodeModule } from 'ngx-qrcode2';
import { BarcodeScanner } from '@ionic-native/barcode-scanner';

import { MyApp } from './app.component';
import { HomePage } from '../pages/home/home';
import { QrcodePage } from '../pages/qrcode/qrcode';
import { ChatPage } from '../pages/chat/chat';
import { ChatService } from '../providers/chat-service/chat-service';

@NgModule({
  declarations: [
    MyApp,
    HomePage,
    QrcodePage,
    ChatPage
  ],
  imports: [
    BrowserModule,
    IonicModule.forRoot(MyApp),
    NgxQRCodeModule,
    LongPressModule
  ],
  bootstrap: [IonicApp],
  entryComponents: [
    MyApp,
    HomePage,
    QrcodePage,
    ChatPage
  ],
  providers: [
    StatusBar,
    SplashScreen,
    {provide: ErrorHandler, useClass: IonicErrorHandler},
    BarcodeScanner,
    ChatService
  ]
})
export class AppModule {}
