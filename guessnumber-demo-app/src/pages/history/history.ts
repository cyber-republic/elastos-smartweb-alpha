import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';
import { DomSanitizer } from '@angular/platform-browser';

/**
 * Generated class for the HistoryPage page.
 *
 * See https://ionicframework.com/docs/components/#navigation for more info on
 * Ionic pages and navigation.
 */

@Component({
  selector: 'page-history',
  templateUrl: 'history.html',
})
export class HistoryPage {

  private CreditRuleUrl: any = 'https://fun-dev.elastos.org/lotteryall';

  constructor(public navCtrl: NavController, public navParams: NavParams, private sanitizer: DomSanitizer) {
    this.openIframe()
  }

  ionViewDidLoad() {
    console.log('ionViewDidLoad HistoryPage');
  }

  openIframe(){
    this.CreditRuleUrl = this.sanitizer.bypassSecurityTrustResourceUrl(this.CreditRuleUrl);
  }

}
