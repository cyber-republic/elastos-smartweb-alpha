import {Injectable} from '@angular/core';





/***
 * 封装配置信息
 */
@Injectable()
export class Config {

  public static COIN_LIST = {"ELA": {id: 0, name: 'ELA', balance: 0}};

  public static WalletKey = "wallet";

  public static LIST_COUNT = 20;

  public static SELA = 100000000;

  public static BLOCKCHAIN_URL: String = 'https://blockchain.elastos.org/';

  public static appList=[{"id":0,"appkeyName":"kyc"}];

  private static smsSecretKey = "";

  public static test: any = '';

  private static kycObj:any={};

  private static deviceID:string="";

  private static serIds:any ={};

  public static getKycObj(){
       return this.kycObj;
  }

  public static setKycObj(obj){
        this.kycObj = obj;
  }

  public static getSmsSecretKey(){
      return this.smsSecretKey;
  }

  public static setDeviceID(deviceID){
       this.deviceID = deviceID;
  }

  public static getdeviceID(){
        return this.deviceID;
  }

  public static getSerIds(){
         return this.serIds;
  }

  public static setSerIds(serIds){
        this.serIds = serIds;
  }

 public static add(idObj,newIds,id,appName,appr){
    if(idObj[appName][appr]){
      if(idObj[appName][appr]["order"]){
         for(let index in idObj[appName][appr]["order"]){
          let data = idObj[appName][appr]["order"][index];
          newIds[index] ={"id":id,"appName":appName,"appr":appr,"txHash":data["txHash"]};
         }
      }
  }
 }

 public static getSertoId(ids){
  let newIds = {};
  for(let key in ids){

      let id =  key;
      let idObj = ids[id];
      let appName ="kyc";
      if(!idObj[appName]){
        break;
      }

      let appr = "person";
      this.add(idObj,newIds,id,appName,appr);
      appr = "company";
      this.add(idObj,newIds,id,appName,appr);
  }
    return newIds;
  }
}


