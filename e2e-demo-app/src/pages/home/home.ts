import { Component, ViewChild } from '@angular/core';

import {Base} from '../Base';
import {DittoListPage} from '../ditto_list';
import {ProfilePage} from '../profile';
import {WalletInfoPage} from '../wallet_info';
import {IpfsInfoPage} from '../ipfs_info';
import {DittoConfigPage} from '../ditto_config';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage extends Base {
  private DittoPage;
  private ProfilePage;
  private WalletInfoPage;
  private IpfsInfoPage;

  private select;

  _init(){
    this.DittoPage = DittoConfigPage;
    this.ProfilePage = ProfilePage;
    this.WalletInfoPage = WalletInfoPage;
    this.IpfsInfoPage = IpfsInfoPage;

    this.select = this.navParam.get('select') || 0;
  }
  


}
