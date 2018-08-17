import { Component, OnInit } from '@angular/core';
import {BaseComponent} from './../../../app/BaseComponent';
import {Config} from '../../../providers/Config';
import { Util } from '../../../providers/Util';

@Component({
  selector: 'app-recordinfo',
  templateUrl: './recordinfo.component.html',
  // styleUrls: ['./recordinfo.component.scss']
})
export class RecordinfoComponent extends BaseComponent implements OnInit {

  transactionRecord: any = {};

  start = 0;

  blockchain_url = Config.BLOCKCHAIN_URL;

  ngOnInit() {
    this.setTitleByAssets('text-record');
    let txId = this.getNavParams().get("txId");
    let chainId = this.getNavParams().get("chainId");
    this.walletManager.getAllTransaction(chainId, this.start, txId, (data) => {
      let allTransaction = data['allTransaction'];
      let transactions = JSON.parse(allTransaction)['Transactions'];
      // alert("getAllTransaction" + JSON.stringify(transactions));
      let transaction = transactions[0];
      let timestamp = transaction['Timestamp']*1000;
      // alert(timestamp)
      let datetime = Util.dateFormat(new Date(timestamp), 'yyyy-MM-dd hh:mm:ss');
      let summary = transaction['Summary'];
      let incomingAmount = summary["Incoming"]['Amount'];
      let outcomingAmount = summary["Outcoming"]['Amount'];
      let incomingAddress = summary["Incoming"]['ToAddress'];
      let outcomingAddress = summary["Outcoming"]['ToAddress'];
      let balanceResult = incomingAmount - outcomingAmount;
      this.transactionRecord = {
        name: chainId,
        status: summary["Status"],
        balance: balanceResult/Config.SELA,
        incomingAmount: incomingAmount/Config.SELA,
        outcomingAmount: outcomingAmount/Config.SELA,
        incomingAddress: incomingAddress,
        outcomingAddress: outcomingAddress,
        txId: txId,
        transactionTime: datetime,
        timestamp: timestamp,
        payfees: summary['Fee']/Config.SELA,
        confirmCount: summary["ConfirmStatus"],
        remark: summary["Remark"]
      }
    });
  }  

}
