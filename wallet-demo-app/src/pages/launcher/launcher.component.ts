import {Component, OnInit} from '@angular/core';
import {BaseComponent} from '../../app/BaseComponent';
import {WalletCreateComponent} from "../wallet/wallet-create/wallet-create.component";
import {ImportComponent} from "../wallet/import/import.component";

@Component({
  selector: 'app-launcher',
  templateUrl: './launcher.component.html',
})
export class LauncherComponent extends BaseComponent implements OnInit {


  ngOnInit() {
  }

  onNext(type) {
    if (type === 1) {
      this.Go(WalletCreateComponent);
    } else {
      this.Go(ImportComponent);
    }
  }
}
