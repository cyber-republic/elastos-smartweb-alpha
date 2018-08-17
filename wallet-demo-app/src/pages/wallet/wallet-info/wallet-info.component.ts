import { Component, OnInit } from '@angular/core';
import {BaseComponent} from './../../../app/BaseComponent';

@Component({
  selector: 'app-wallet-info',
  templateUrl: './wallet-info.component.html',
  // styleUrls: ['./wallet-info.component.scss']
})
export class WalletInfoComponent  extends BaseComponent implements OnInit  {

  walletName = ""

  ngOnInit() {
    this.setTitleByAssets('text-wallet-info');
    this.localStorage.getWallet().then((val) => {
      if (val) {
        this.walletName = JSON.parse(val).name;
      }
    });
  }

}
