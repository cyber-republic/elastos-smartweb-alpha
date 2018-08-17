import {Injectable} from '@angular/core';
import { Storage } from '@ionic/storage';
import {Config} from "./Config";
import {Util} from '../providers/Util';
import {WalletModel} from "../models/wallet.model";
//import {Logger} from "./Logger";


/***
 * 封装原生平台存储操作
 */
@Injectable()
export class StorageUtil {

  public localStorage: any;

  constructor(private storage: Storage) {

  }

  public set(key: string, value: string): void {
    this.storage.set(key,value);
  }

  public get(key: string,Fun:any): void {
    this.storage.get(key).then((val)=>{
      Fun(val);
    });
  }

  public setObject(key: string, value: any): void {
    this.set(key,JSON.stringify(value));
  }

  public getObject(key: string,Fun:any): any {
    this.storage.get(key).then((val)=>{
      Fun(JSON.parse(val));
    });
  }

  public remove(key: string) {
    this.storage.remove(key);
  }

  public clear(): any {
    this.storage.clear();
  }

  public getWallet(Fun){
    this.getObject(Config.WalletKey, (val)=> {
      if(Util.isNull(val)){
        let walletModel = new WalletModel();
        this.setObject(Config.WalletKey,walletModel);

        Fun(walletModel);
      }else{

        Fun(val);
      }
    });
  }

  public setWallet(wallet){
    this.setObject(Config.WalletKey,wallet);
  }
}


