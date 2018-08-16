import { Component, ViewChild } from '@angular/core';
import {Base} from '../Base';
import {wallet} from '../../utility';
import * as _ from 'lodash';


import C from '../../config';

const config = C.wallet;

@Component({
  selector: 'page-wallet_detail',
  templateUrl: 'main.html'
})
export class WalletDetailPage extends Base {
  private walletId;
  private address_list = [];
  private qrcode = '';
  private qrcode_balance = 0;
  private balance = 0;
  private info: any;
  private history:any[] = [];

  private sec: string;

  private send_ready = false;
  private target: any;
  private param: any;

  _init(){
    this.walletId = this.navParam.get('walletId');
    this.info = {
      balance : this.navParam.get('balance')
    };
    this.resetSend();
  }

  resetSend(){
    this.target = {
      address : '',
      amount : '',
      memo : '',
      fee : 0
    };
    this.param = {};
  }

  
  async ionViewDidLoad_AfterLogin(){
    this.showLoading();
    
    await this.setAddressList();

    this.hideLoading();
    this.sec = 'sec_receive';
  }

  async setAddressList(){
    const rs: any = await this.wallet_execute('getAllAddress', this.walletId, 0);
    const list = JSON.parse(rs).Addresses;
    const len = list.length > 5 ? 5 : list.length;
    this.address_list = _.slice(list, 0, len);

    await this.setQRCode(this.address_list[0]);
  }

  async setQRCode(address){
    this.qrcode = address;
    const x: any = await this.wallet_execute('getBalanceWithAddress', this.walletId, address);
    this.qrcode_balance = x.balance/config.SELA;
  }
  scanQRCode(){
    this.scanBarcode((flag, data: any)=>{
      console.log(JSON.stringify(data));
      if(flag){
        this.target.address = data.text.replace('elastos:', '');
      }
      
    });

    // 刘 涂 抹 仿 邦 纶 强 咨 筛 领 狱 压
  }

  async prepearForSend(){
    if(!this.target.amount){
      this.warning('invalid amount');
      return false;
    }

    this.param.amount = parseFloat(this.target.amount) * config.SELA;
    let res:any = await this.wallet_execute('createTransaction', 
      this.walletId, 
      '',
      this.target.address,
      this.param.amount,
      this.target.fee,
      this.target.memo,
      ''
    );
    this.param.transaction = res.transactionId.toString();
    // console.log(this.param.transaction)
    res = await this.wallet_execute('calculateTransactionFee',
      this.walletId, 
      this.param.transaction,
      100000
    );
    this.param.fee = res.fee;
    this.target.fee = res.fee/config.SELA;

    this.send_ready = true;
  }
  async confirmSend(){
    const alert = this.alertCtrl.create({
      title : 'Input password',
      inputs : [
        {
          name : 'password',
          placeholder : 'Input password'
        }
      ],
      buttons : [

        {
          text : 'Cancel',
          role : 'cancel'
        },
        {
          text : 'confirm',
          handler : (data)=>{
            if(!data.password){
              this.warning('invalid password');
              return false;
            }
            this._confirmSend(data.password);
          }
        }
      ]
    });
    alert.present();
  }
  async _confirmSend(password){
    this.showLoading('confirming ...');
    try{
      let res:any = await this.wallet_execute('sendRawTransaction', this.walletId, this.param.transaction, this.param.fee, password||'12345678');
   
      this.param.txId = res["json"]["txHash"];
      this.walletService.registerWalletListener(this.walletId, async (d: any)=>{
        console.log('registerWalletListener => ' + JSON.stringify(d));
        if(d.confirms === 1){
    
          _.delay(async ()=>{
            const xx = await this.wallet_execute('getBalance', this.walletId);
            this.info.balance = (xx.balance/config.SELA);
            this.toast('success');
            this.resetSend();
            
  
            this.hideLoading();
          }, 10);
          
        }

      });
      
    }catch(e){
      this.warning(e.toString());
      this.hideLoading();
    }
    
  }

  
  async segmentChanged(e:any){
    const v = e.value;
    if(v === 'sec_history'){
      await this.initHistory();
    }
  }
  
  async initHistory(){
    try{
      const res:any = await this.wallet_execute('getAllTransaction', this.walletId, 0, '');
      const data = JSON.parse(res.allTransaction)['Transactions'];
      const list = _.map(data, (transaction)=>{
        
        const timestamp = transaction['Timestamp']*1000;
   
        const datetime = wallet.dateFormat(new Date(timestamp), 'yyyy-MM-dd hh:mm:ss');
        const summary = transaction['Summary'];
        console.log(JSON.stringify(summary));
        const incomingAmount = summary["Incoming"]['Amount'];
        const outcomingAmount = summary["Outcoming"]['Amount'];
        const incomingAddress = summary["Incoming"]['ToAddress'];
        const outcomingAddress = summary["Outcoming"]['ToAddress'];
        const balanceResult = incomingAmount - outcomingAmount;
        return {
          name: this.walletId,
          status: summary["Status"],
          balance: balanceResult/config.SELA,
          incomingAmount: incomingAmount/config.SELA,
          outcomingAmount: outcomingAmount/config.SELA,
          incomingAddress: incomingAddress,
          outcomingAddress: outcomingAddress,
          transactionTime: datetime,
          timestamp: timestamp,
          payfees: summary['Fee']/config.SELA,
          confirmCount: summary["ConfirmStatus"],
          remark: summary["Remark"]
        };
      });

      this.history = list;
    }catch(e){
      this.warning(e);

    } 
  }

}