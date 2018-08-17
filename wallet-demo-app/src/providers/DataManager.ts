import {Injectable} from '@angular/core';





/***
 * 封装配置信息
 */
@Injectable()
export class DataManager {

  //map key is signature value is jsonObj (with seqnum and so on)
  public  SignSeqNumObjetMap = {};

  //add obj
  public  addSeqNumObj(sign :string , obj : any ){
    console.info("ElastosJs DataManager addSeqNumObj sign "+ sign + "obj "+ JSON.stringify(obj));

    this.SignSeqNumObjetMap[sign] = obj;
  }

  //get object
  public  getSeqNumObj(sign : string){
    console.info("ElastosJs DataManager getSeqNumObj sign "+ sign + "obj "+ JSON.stringify(this.SignSeqNumObjetMap[sign]));
    return this.SignSeqNumObjetMap[sign];
  }



}


