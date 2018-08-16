import { Component } from '@angular/core';
import {Base} from '../Base';
import {wallet} from '../../utility';
import C from '../../config';
import * as _ from 'lodash';

const config = C.wallet;

@Component({
  selector: 'page-wallet_idchain',
  templateUrl: 'main.html'
})
export class WalletIdChainPage extends Base {
  private main;
  private ela: any;
  private id_chain: any;
  private param1: any;
  private param2: any;

  _init(){
    this.main = 'recharge';
    this.ela = {};
    this.id_chain = {};
    this.reset();
    this.initRecharge();
  }
  reset(){
    this.param1 = {
      amount : ''
    };
    this.param2 = {
      amount : ''
    };
  }

  async segmentChanged(e:any){
    const v = e.value;
    if(v === 'recharge'){
      await this.initRecharge();
    }
    else if(v === 'withdraw'){
      await this.initWithdraw();
    }
  }

  async initRecharge(){
    const rs: any = await this.wallet_execute('getBalance', 'ELA');

    this.ela = {
      balance : wallet.balance(rs.balance)
    };
  }

  async initWithdraw(){
    const rs: any = await this.wallet_execute('getBalance', 'IdChain');

    this.id_chain = {
      balance : wallet.balance(rs.balance)
    };
  }

  async recharge(){
    if(!this.param1.amount){
      this.warning('invalid amount');
      return false;
    }
    if(this.param1.amount > this.ela.balance){
      this.warning('not enough ela token');
      return false;
    }
    const pwd = await this.inputPassword();
    const amount = this.param1.amount * config.SELA;

    this.showLoading();
    try{
      let rs: any;
      const p: any = {};
      
      rs = await this.wallet_execute('getAllAddress', 'IdChain', 0);
      const list = JSON.parse(rs).Addresses;
      const id_chain_address = list[0];
  
      const address = await this.wallet_execute('getGenesisAddress', 'ELA');
      rs = await this.wallet_execute('createDepositTransaction', 'ELA', '', 
        address, amount, 
        JSON.stringify([id_chain_address]), 
        JSON.stringify([amount - 20000]), 
        JSON.stringify([0]), 'recharge memo', 'recharge remark');
      p.rawTransaction = rs.json.toString();
      rs = await this.wallet_execute('calculateTransactionFee', 'ELA', p.rawTransaction, 10000);
      p.fee = rs.fee;
  
      rs = await this.wallet_execute('sendRawTransaction', 'ELA', p.rawTransaction, p.fee, pwd);
      
      this.walletService.registerWalletListener('ELA', async (d: any)=>{
        if(d.confirms === 1){
          alert('recharge success');
          this.reset();
          await this.initRecharge();
          this.hideLoading();
        }
      })

    }catch(e){
      this.warning(e);
      this.hideLoading();
    }
    
  }

  async withdraw(){
    if(!this.param2.amount){
      this.warning('invalid amount');
      return false;
    }
    if(this.param2.amount > this.id_chain.balance){
      this.warning('not enough id_chain token');
      return false;
    }
    const pwd = await this.inputPassword();
    const amount = this.param2.amount * config.SELA;
    
    this.showLoading();
    try{
      let rs: any;
      const p: any = {};
      
      rs = await this.wallet_execute('getAllAddress', 'ELA', 0);
      const list = JSON.parse(rs).Addresses;
      const ela_address = list[0];
  
      const address = await this.wallet_execute('getGenesisAddress', 'IdChain');
      rs = await this.wallet_execute('createWithdrawTransaction', 'IdChain', '', 
        address, amount, 
        JSON.stringify([ela_address]), 
        JSON.stringify([amount - 20000]), 
        JSON.stringify([0]), 'withdraw memo', 'withdraw remark');
      p.rawTransaction = rs.json.toString();
      rs = await this.wallet_execute('calculateTransactionFee', 'IdChain', p.rawTransaction, 10000);
      p.fee = rs.fee;
  
      rs = await this.wallet_execute('sendRawTransaction', 'IdChain', p.rawTransaction, p.fee, pwd);
      
      _.delay(async ()=>{
        alert('withdraw success');
        this.reset();
        await this.initWithdraw();
        this.hideLoading();
      }, 5000);
      
    }catch(e){
      this.warning(e);
      this.hideLoading();
    }
  }

  inputPassword(): Promise<void>{
    return new Promise((resolve)=>{
      const alert = this.alertCtrl.create({
        title : 'Input Password',
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
            text : 'Save',
            handler : (data)=>{
              resolve(data.password);
            }
          }
        ]
      });
      alert.present();
    });
  }
}
