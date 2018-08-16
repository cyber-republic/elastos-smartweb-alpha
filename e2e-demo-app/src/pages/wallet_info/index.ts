import { Component, ViewChild } from '@angular/core';
import * as _ from 'lodash';
import {wallet} from '../../utility';

import {Base} from '../Base';
import {WalletDetailPage} from '../wallet_detail';
import {WalletIdChainPage} from '../wallet_idchain';
import {WalletDidListPage} from '../wallet_did_list';


@Component({
  selector: 'page-wallet_info',
  templateUrl: 'main.html'
})
export class WalletInfoPage extends Base {
  private master_wallet_id = '';
  private wallet_list : any[] = [];
  private wallet_map : any = {};

  private memo: string[] = [];
  private execute;

  private isCreate = false;
  private create_master_param = {
    phrase_password : '',
    pay_password : ''
  };

  private idchain_exist = false;

  _init(){
    this.execute = this.wallet_execute;
  }

  showAddPrompt(){
    const alert = this.alertCtrl.create({
      title : 'Add Address',
      inputs : [
        {
          name : 'address',
          placeholder : 'Input new ela address'
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
            this.addNewAddress(data.address).then(()=>{});
          }
        }
      ]
    });
    alert.present();
  }

  async addNewAddress(address){
    
  }

  async importWalletWithMnemonic(){
    // const mem = this.normalizeMnemonic(this.memo);
    const mem = 'couple advice soldier cherry thunder huge wisdom fun wrist hill girl right';
    this.showLoading();
    this.walletService.importWalletWithMnemonic('Wallet-Mnemonic', mem, '12345678', '12345678', 'english', async (data)=>{
      if(data === 'OK'){
        await this.createSubWallet('12345678');
        // this.toast('success');
        // await this.init();
      }
      else{
        this.warning(JSON.stringify(data));
        this.hideLoading();
      }
      
    })

    // password : qweasd123
    // tenant parent skill hurry canal then actual census large giraffe flush shrug
  }

  async ionViewDidEnter(){
    await this.init();
  }

  async init(){
    // this.showLoading();
    const rs: any = await this.wallet_execute('getAllMasterWallets');
    this.master_wallet_id = rs.walletid;
    if(!this.master_wallet_id){
      this.hideLoading();
      return;
    }

    

    const sub = await this.wallet_execute('getAllSubWallets');
    if(_.includes(_.values(sub), 'IdChain')){
      this.idchain_exist = true;
    }
    this.wallet_list = _.map(_.values(sub), (address)=>{
      const tmp = {
        address,
        balance : 'NA'
      };
      return tmp;
    });
    console.log(wallet);
    _.each(this.wallet_list, async (item: any)=>{
      const rs: any = await this.wallet_execute('getBalance', item.address);

      item.balance = wallet.balance(rs.balance);
    })
    this.wallet_map = sub;
    // this.hideLoading();
  }

  // syncWallet(){
  //   this.wallet_list = this.userService.current.wallet;
  // }

  goDetailPage(item){
    if(item.address === 'IdChain'){
      this.navCtrl.push(WalletIdChainPage);

      return false;
    }
    this.navCtrl.push(WalletDetailPage, {
      walletId : item.address,
      balance : item.balance
    });

  }

  goSettingPage(){
    this.navCtrl.push(WalletDidListPage);
  }

  private normalizeMnemonic(words: string): string {
    if (!words || !words.indexOf) return words;
    let isJA = words.indexOf('\u3000') > -1;
    let wordList = words.split(/[\u3000\s]+/);

    return wordList.join(isJA ? '\u3000' : ' ');
  }  

  async createSubWallet(pwd){
    this.execute('recoverSubWallet', 'IdChain', pwd, true, 500, 1000).then(async (d)=>{
      this.toast('success');
      await this.init();
      this.hideLoading();
    }).catch((e)=>{
      this.warning(e);
      this.hideLoading();
    });
    // const alert = this.alertCtrl.create({
    //   title : 'Create sub wallet',
    //   inputs : [
    //     {
    //       name : 'pay_password',
    //       placeholder : 'Pay Password'
    //     }
    //   ],
    //   buttons : [
    //     {
    //       text : 'Cancel',
    //       role : 'cancel'
    //     },
    //     {
    //       text : 'Confirm',
    //       handler : (data)=>{
    //         this.showLoading();
    //         this.execute('recoverSubWallet', 'IdChain', data.pay_password, true, 500, 1000).then(async (d)=>{
    //           this.didService.removeDidName();
    //           this.toast('success');
    //           await this.init();
    //           this.hideLoading();
    //         }).catch((e)=>{
    //           this.warning(e);
    //           this.hideLoading();
    //         });
    //       }
    //     }
    //   ]
    // });
    // alert.present();
    
  }

  async importMasterWalletWithKeystore(){
    const s = {"iv":"ugAfgukvXFaYmDYsHBiIew==","v":1,"iter":10000,"ks":128,"ts":64,"mode":"ccm","adata":"","cipher":"aes","salt":"ys6oTOoJer0=","ct":"oGM4GiUVD3hqeeu2yCUrCn2NArs2v+KkO9Ax9eMgiEmRccSl5kDd2SDzx5cZB7on5vLtKtCdzTkfLmkMa0KRugaAsFSM8dB97ewvQ52ETqYLwvrdH1zjmJQfQJqDUvWBE4YH2iLk3DhpW3N1//d5PTU7+Qp+UbTBWoyAQ0bx4+/Hs9ZT5VpB/S58PisxdTrXhiRSC+5HtPdQlajgGyTrtAIks9ixYTSxXdf8AncWARCqfVXz+Y+dVyh91qo/kNbfX8kIoOnUyNOm7HwjoGVFZ2VBNT5XUiwulLPzCOJTnevvP7osdax/BLiSSy/VJxpNHEGnpoy0Fxj5Us/+lFZWPl+dvmimAoQb8YTMbgb0z96421/5Dv9zvEGrbTKqAGv982aL5xNBx6yBBDYrzMNH6hZWBMEoSEWpBJd7XkKNTg46ImGWzHb3eOGVTTw5H3vFV7oYiegQL1vsInxV32BASf8kb2UjbKm6BlRkm0LOwZF36LGq8cvaMrVoLF/Vk+49l59kiA+NKwCoLNUDz7vctg7o396M2mseTmYjto4hhA5gHW0JsC7Xx5/2jPJ4IZeAKhorPc2TE4L5H2qzVw3YRVSz5n58ABOMpi52SLecenN+JOXVYnPSAgZpLIyycwrnTK8SgAw5bnygTgiQ9HQc8WoSbS83DA3BU935SvopyzheewqqE+YLkhtF072H0S6p+jk9q+WVqvQwFqqbLoulnApfjERaq25zwh3tw+4z/sEXUmEy0pltGIKsZjFWXLLBBAeIgpkUisNfjp/k32fkYXBqQuxaKYY+DQ1wgOKY3/k+gLUj3vlV6f5qjdFKRI2EoY0JmdPyEbZNSKMocFyVGCef22HnEmEMajAUUU0zwIaWPFREMUz0nWITG0X8FjM39l7SxiCAuAalJMnT4AYGIO2I9tnnr59v5JfvTjuD6LeeP847VF15G8cFMYvyfOGlN99QJsgA7nmf8w/bK6WnxePqen+bOj8agurwKQL95zlsvVHOD+w4veCyndo3BzS2di+scyLGvGB758qPsyPLK6JOTMdNRYvXxxvm34MbR8asFyLoUBvPeIvKkXlPBaFfaVeXU4V5bhYfEblJsgX5UknDMsRbMi4WW1iZnCWNC8i1wbcmOZYdmlstKkzxMTAVU4FfEgk7IY3iEffbBa92Zj9xNUTb6ebLh+dbgzEHvTbrkRwBsgKkvCQDywIjupn9oFQkbIS9pLeIHsCH1qTQ388avipKhPtikxb3SY/myPStLZGMdxoNQ7v4bJ4wvsWWQP/+BkFEBiVJCjshEOX6YFVL176jc0+eTk9Jtrr96IaPjxi5G7/k8PAIM4f2kZBL6rkpUKksJydKUhGHier7wOEJ0jOL2ayNMasc+p8Fct0goLYhG8MRSfC9Qe51Z3HhNt2CcNjgsUtJm0/Pq78kqydoHbT/ihAA34Tb2I+B4rYxtINzsu4ceVPWszo/PfmXVs+KRlZxy5czjm6z/D36KPwmB92N3IfNfGF2Gu8mTQWl+NvhakSGB4JE7URAUOfWrbG2lEVT2zZZYdajYw76rl+5H6UUjWx8L3JCe8hBYBivmiHQRQaisunXkytyOyTgUSh8rsmrgOdolR5m3Y+A/l1A2r6hzRW/2QXx9G8wVke0TX+8AFR6SQHVW8vHcm6efVEZdvTeWGfPz1kQqCxpjx0GQdrK/MpY3PpLD9USZL2svmaLNsj1ulZ6G8RiA7oyLGlDo5tyFtz909m5KZ75ed4FW42koO5ZKPG2cYW+I5X7WNfUevF55SSxdtcI2zvXLA=="};
    // const rs = await this.execute('importWalletWithKeystore', '1', JSON.stringify(s), '111qqq,,,', 'zhangying', '');
    await this.execute('getAllMasterWallets');
    
    // return rs;
  }

  async createNewMasterWallet(){
    this.showLoading();
    this.isCreate = true;
    let rs = await this.execute('generateMnemonic', 'english');
    this.memo = rs.mnemonic.toString().split(/[\u3000\s]+/);

    this.hideLoading();
    
  }
  async clickCreateWallet(){
    if(!this.create_master_param.phrase_password){
      this.warning('invalide phrase password');
      return false;
    }
    if(!this.create_master_param.pay_password){
      this.warning('invalide pay password');
      return false;
    }

    this.showLoading();
    try{
      await this.execute('createMasterWallet', 'Ela Wallet', this.memo.join(' '), this.create_master_param.phrase_password, this.create_master_param.pay_password, 'english');
      await this.createSubWallet(this.create_master_param.pay_password);
      // this.toast('success');
      this.isCreate = false;
      // await this.init();
    }catch(e){
      this.warning(e);
    }
    
    // this.hideLoading();
  }

  async removeMasterWallet(){
    this.showLoading();
    try{
      await this.execute('destroyWallet', 'Ela Wallet');
      this.toast('success');
      this.wallet_list = [];
      this.wallet_map = {};
      this.master_wallet_id = '';
      this.idchain_exist = false;
    }catch(e){
      this.warning(e);
    }
    this.hideLoading();
    
  }

  async rechareToIdChain(){
    
  }

  async withdrawFromIdChain(){

  }

}
