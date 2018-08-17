import {Component, OnInit} from '@angular/core';
import {BaseComponent} from "../../../../app/BaseComponent";
import {Observable} from 'rxjs';
import 'rxjs/add/observable/timer';
import {IDManager} from "../../../../providers/IDManager"
import {ApiUrl} from "../../../../providers/ApiUrl"
import {TransferComponent} from "../../../../pages/coin/transfer/transfer.component";

@Component({
  selector: 'id-person',
  templateUrl: 'person.html',
})
export class IdKycPersonComponent extends BaseComponent implements OnInit {
  validateObj ={"identityCard":{isValidate:false,isSelect:true,payMoney:0.3},
                "phone":{isValidate:false,isSelect:false,payMoney:0.1},
                "bankCard":{isValidate:false,isSelect:false,payMoney:0.1}};
  personValidate = {fullName:'宋家准',identityNumber:'410426198811151012'};//个人验证对象
  phoneValidate  = {mobile:'18210230496',code:''};//手机验证对象
  debitCard = {cardNumber:'6225880167820399',cardMobile:'18210230496',cardCode:''};//银行卡验证对象
  payMoney = 0;
  unit:string="ELA"
  priceObj:any={};
  serialNum:string;
  parms:any;
  did:any;
  ngOnInit() {
    this.setTitleByAssets('text-certified-person');
    this.parms = this.getNavParams().data;
    this.did = this.parms["id"];
    this.getPrice();
  }

  onSendCode(): Observable<boolean> {
    return Observable.timer(1000).map((v, i) => true);
  }

  onSendCode1(): Observable<boolean> {
    return Observable.timer(1000).map((v, i) => true);
  }
  sendCode(phone){
    if(this.isNull(phone)){
      this.messageBox('text-phone-message-1');
       return;
}

if(this.checkCellphone(phone)){
  this.messageBox('text-phone-message-2');
  return;
}
   this.sendCodeHttp(phone);
  }

  sendCodeHttp(mobile){
    let code = (Math.random()*1000000000000000).toString().substring(0,6);
    let timestamp = this.getTimestamp();
    let parms ={"mobile":mobile,"code":code,"serialNum":this.serialNum,"timestamp":timestamp};
    let checksum = IDManager.getCheckSum(parms,"asc");
    parms["checksum"] = checksum;
    this.getHttp().postByAuth(ApiUrl.SEND_CODE,parms).toPromise().then(data=>{

    }).catch(error => {

    });
  }

  calculateMenoy(){
    let pay = 0;
    for(let key in this.validateObj){
         if(!this.validateObj[key].isValidate && this.validateObj[key].isSelect){
              pay =pay+this.validateObj[key].payMoney;
         }
    }
    this.payMoney = pay;
  }

  getSelectType(){
    let type:string;
    for(let key in this.validateObj){
      if(!this.validateObj[key].isValidate && this.validateObj[key].isSelect){
             if(this.isNull(type)){
               type =key;
             }else{
               type =type+"/"+key;
             }
      }
     }
     return type;
  }

  getpayParms(){
    let obj  = {};
    for(let key in this.validateObj){
         let vobj = this.validateObj[key];
         //console.log("===key==="+key+typeof(key));
         if(key=="identityCard"){
                obj["fullName"] = this.personValidate.fullName;
                obj["identityNumber"] = this.personValidate.identityNumber;
         }else if(!vobj.isValidate && vobj.isSelect&&key=="phone"){
                obj["mobile"] = this.phoneValidate.mobile;
                obj["code"] = this.phoneValidate.code;
         }else if(!vobj.isValidate && vobj.isSelect&&key=="bankCard"){
                obj["cardNumber"] = this.debitCard.cardNumber;
                obj["cardMobile"] = this.debitCard.cardMobile;
                obj["cardCode"] = this.debitCard.cardCode;
         }
    }
        return obj;
  }
  onCommit(): void {
    /**个人身份验证 */
     if(!this.validateObj['identityCard'].isValidate && this.validateObj['identityCard'].isSelect){
              if(this.isNull(this.personValidate.fullName)){
                    this.messageBox('text-realname-message');
                     return;
              }

              if(this.isNull(this.personValidate.identityNumber)){
                    this.messageBox('text-cardNo-message-1');
                return;
              }

              if(this.isCardNo(this.personValidate.identityNumber)){
                this.messageBox('text-cardNo-message-2');
                return;
              }
     }

     /**手机验证 */
     if(!this.validateObj['phone'].isValidate && this.validateObj['phone'].isSelect){
      if(this.isNull(this.phoneValidate.mobile)){
            this.messageBox('text-phone-message-1');
             return;
      }

      if(this.checkCellphone(this.phoneValidate.mobile)){
        this.messageBox('text-phone-message-2');
        return;
      }

      if(this.isNull(this.phoneValidate.code)){
            this.messageBox('text-sendcode-message-1');
        return;
       }
      }

      /**邮政卡验证 */
      if(!this.validateObj['bankCard'].isValidate && this.validateObj['bankCard'].isSelect){

        if(this.isNull(this.debitCard.cardNumber)){
          this.messageBox('text-debitCard-message-1');
           return;
         }

         if(this.isBankCard(this.debitCard.cardNumber)){
          this.messageBox('text-debitCard-message-2');
           return;
         }

        if(this.isNull(this.debitCard.cardMobile)){
              this.messageBox('text-phone-message-1');
               return;
        }

        if(this.checkCellphone(this.debitCard.cardMobile)){
          this.messageBox('text-phone-message-2');
          return;
        }

        if(this.isNull(this.debitCard.cardCode)){
              this.messageBox('text-sendcode-message-1');
          return;
         }
        }
        //appType authType
        let parms =this.getpayParms();
        let type = this.getSelectType();
        parms["type"] = type;
        parms["serialNum"] =this.serialNum;
        this.Go(TransferComponent,{did:this.did,addr:"EKZCcfqBP1YXiDtJVNdnLQR74QRHKrgFYD",money:this.payMoney,appType:"kyc",chianId:"ELA",selectType:"person",parms:parms});
  }

  getPrice(){
    let timestamp = this.getTimestamp();
    let parms ={"appid":"elastid","timestamp":timestamp};
    let checksum = IDManager.getCheckSum(parms,"asc");
    parms["checksum"] = checksum;
    this.getHttp().postByAuth(ApiUrl.GET_PRICE,parms).toPromise().then().then(data => {
        if(data["status"] === 200){
          this.priceObj = JSON.parse(data["_body"]);
          this.payMoney = this.priceObj["price"] || 0.1;
          this.unit = this.priceObj["unit"] || "ELA";
          this.serialNum = this.priceObj["serialNum"];
         }
    }).catch(error => {

    });
  }

}
