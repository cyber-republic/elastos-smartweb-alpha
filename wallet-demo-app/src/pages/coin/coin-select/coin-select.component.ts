import {Component, OnInit, ViewChild} from '@angular/core';
import {BaseComponent} from '../../../app/BaseComponent';
import { PopupComponent } from "ngx-weui";
import {RechargeComponent} from "../recharge/recharge.component";


@Component({
  selector: 'app-coin-list',
  templateUrl: './coin-select.component.html'
})
export class CoinSelectComponent extends BaseComponent implements OnInit {

  @ViewChild('subscribe') subPopup: PopupComponent;

  coinList = [];

  ngOnInit() {
    this.setTitleByAssets('text-coin-list');
    this.localStorage.get('coinListCache').then((val)=>{
      let coinListCache = JSON.parse(val);
      this.coinList = [];
      for (let coin in coinListCache) {
        if (coin != 'ELA') {
          this.coinList.push({name: coin});
        }
      }
    });
  }

  onItem(item) {
    this.Go(RechargeComponent, {chianId: item.name});
  }

}
