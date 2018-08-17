import {Component, OnInit} from '@angular/core';
import {BaseComponent} from "../../../../app/BaseComponent";
import {ApiUrl} from "../../../../providers/ApiUrl";
import {IDManager} from "../../../../providers/IDManager";
import {TransferComponent} from "../../../../pages/coin/transfer/transfer.component";

@Component({
  selector: 'id-company',
  templateUrl: 'company.html',
})
export class IdKycCompanyComponent extends BaseComponent implements OnInit {
  businessObj={
              "type":"enterprise",
              "word":"北京比特大陆科技有限公司",
              "legalPerson":"詹克团",
              "registrationNum":"911101080804655794"
              };
  priceObj:any={};
  payMoney:number = 0;
  unit:string ="ELA";
  serialNum:string;
  parms:any;
  did:any;
  ngOnInit() {
    this.setTitleByAssets('text-certified-company');
    this.parms = this.getNavParams().data;
    this.did = this.parms["id"];
    this.getPrice();
  }

  onCommit(): void {
    if(this.checkParms()){
      this.businessObj["serialNum"] = this.serialNum;
      this.Go(TransferComponent,{did:this.did,addr:"EKZCcfqBP1YXiDtJVNdnLQR74QRHKrgFYD",money:this.payMoney,appType:"kyc",chianId:"ELA",selectType:"company",parms:this.businessObj});
      //this.Go(IdKycResultComponent,this.parms);
    }
  }

  checkParms(): boolean{
     if(this.isNull(this.businessObj.word)){
         this.messageBox('text-word-message');
         return false;
     }

     if(this.isNull(this.businessObj.legalPerson)){
      this.messageBox('text-legalPerson-message');
      return false;
     }

     if(this.isNull(this.businessObj.registrationNum)){
      this.messageBox('text-registrationN-message');
      return false;
     }

     return true;
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
