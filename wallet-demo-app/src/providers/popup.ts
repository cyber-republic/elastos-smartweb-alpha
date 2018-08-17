import { Injectable } from '@angular/core';
import { TranslateService } from '@ngx-translate/core';
import { AlertController } from 'ionic-angular';

@Injectable()
export class PopupProvider {
  constructor(
    private alertCtrl: AlertController,
    private translate: TranslateService
  ) {
  }

  public ionicAlert(title: string, subTitle?: string, okText?: string): Promise<any> {
    return new Promise((resolve, reject) => {
      let alert = this.alertCtrl.create({
        title : this.translate.instant(title),
        subTitle : this.translate.instant(subTitle),
        enableBackdropDismiss: false,
        buttons: [
          {
            text: okText ? okText : this.translate.instant('confirm'),
            handler: () => {
              console.log('Ok clicked');
              resolve();
            }
          }
        ]
      });
      alert.present();
    });
  };

  public ionicConfirm(title: string, message: string, okText?: string, cancelText?: string): Promise<any> {
    return new Promise((resolve, reject) => {
      let confirm = this.alertCtrl.create({
        title : this.translate.instant(title),
        message  : this.translate.instant(message),
        buttons: [
          {
            text: cancelText ? cancelText : this.translate.instant('cancel'),
            handler: () => {
              console.log('Disagree clicked');
              resolve(false);
            }
          },
          {
            text: okText ? okText : this.translate.instant('confirm'),
            handler: () => {
              console.log('Agree clicked');
              resolve(true);
            }
          }
        ]
      });
      confirm.present();
    });
  };

  public ionicPrompt(title: string, message: string, opts?: any, okText?: string, cancelText?: string): Promise<any> {
    return new Promise((resolve, reject) => {
      let defaultText = opts && opts.defaultText ? opts.defaultText : null;
      let placeholder = opts && opts.placeholder ? opts.placeholder : null;
      let inputType = opts && opts.type ? opts.type : 'text';
      let cssClass = opts.useDanger ? "alertDanger" : null;
      let enableBackdropDismiss = !!opts.enableBackdropDismiss;

      let prompt = this.alertCtrl.create({
        title,
        message,
        cssClass,
        enableBackdropDismiss,
        inputs: [
          {
            value: defaultText,
            placeholder,
            type: inputType
          },
        ],
        buttons: [
          {
            text: cancelText ? cancelText : this.translate.instant('Cancel'),
            handler: data => {
              console.log('Cancel clicked');
              resolve(null);
            }
          },
          {
            text: okText ? okText : this.translate.instant('Ok'),
            handler: data => {
              console.log('Saved clicked');
              resolve(data[0]);
            }
          }
        ]
      });
      prompt.present();
    });
  }

  presentPrompt() {
    return new Promise((resolve, reject) => {
      let alert = this.alertCtrl.create({
        title: this.translate.instant("text-id-kyc-prompt-title"),
        inputs: [
          {
            name: 'password',
            placeholder: this.translate.instant("text-id-kyc-prompt-password"),
            type: 'password'
          }
        ],
        buttons: [
          {
            text: this.translate.instant('cancel'),
            role: 'cancel',
            handler: data => {
              console.log('Cancel clicked');
              reject(null);
            }
          },
          {
            text: this.translate.instant('Ok'),
            handler: data => {
              resolve(data.password);
            }
          }
        ]
      });
      alert.present();
    });
  }

  presentConfirm(price){

    return new Promise((resolve, reject) => {

      let alert = this.alertCtrl.create({
        title: this.translate.instant("text-id-kyc-prompt-title"),
        message: this.translate.instant('text-id-kyc-cochain')+price+"ELA",
        buttons: [
          {
            text: this.translate.instant('cancel'),
            role: 'cancel',
            handler: () => {
              reject();
            }
          },
          {
            text: this.translate.instant('Ok'),
            handler: () => {
              resolve();
            }
          }
        ]
      });
      alert.present();


    });

  }

}
