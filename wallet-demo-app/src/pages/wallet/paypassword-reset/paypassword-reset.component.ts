import { Component, OnInit } from '@angular/core';
import {BaseComponent} from './../../../app/BaseComponent';
import {Util} from "../../../providers/Util";
import {ManagerComponent} from "../../wallet/manager/manager.component";

@Component({
  selector: 'app-paypassword-reset',
  templateUrl: './paypassword-reset.component.html',
  // styleUrls: ['./paypassword-reset.component.scss']
})
export class PaypasswordResetComponent  extends BaseComponent implements OnInit  {

  oldPayPassword: string;
  payPassword: string;
  rePayPassword: string;

  ngOnInit() {
    this.setTitleByAssets('text-wallet-info');
  }

  onSubmit() {
    if (!Util.password(this.payPassword)) {
      this.toast("text-pwd-validator");
      return;
    }
    if (this.payPassword != this.rePayPassword) {
      this.toast("text-repwd-validator");
      return;
    }
    // reset pay password
    this.walletManager.changePassword(this.oldPayPassword, this.payPassword, ()=>{
      this.toast("reset-pwd-success");
      this.Go(ManagerComponent);
    });
  }

}
