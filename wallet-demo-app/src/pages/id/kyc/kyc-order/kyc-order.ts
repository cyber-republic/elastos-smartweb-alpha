import { Component ,OnInit} from '@angular/core';
import {BaseComponent} from "../../../../app/BaseComponent";
import {IDManager} from "../../../../providers/IDManager";
import {ApiUrl} from "../../../../providers/ApiUrl";
import {CompanyWriteChainPage} from "../../../../pages/id/kyc/company-write-chain/company-write-chain";
import {PersonWriteChainPage} from "../../../../pages/id/kyc/person-write-chain/person-write-chain";
@Component({
  selector: 'page-kyc-order',
  templateUrl: 'kyc-order.html',
})
export class KycOrderPage  extends BaseComponent implements OnInit{
  serialNumList = [];
  orderList:any;
  params:any;
  did:any;
  aprType:any;
  idsObj:any;
  ngOnInit(){
     this.params = this.getNavParams().data;
     this.did = this.params["id"];
     if(this.params["type"] === "company"){
         this.aprType = "company"
     }else{
         this.aprType = "person"
     }

     this.setTitleByAssets("text-id-kyc-order-list");
     this.localStorage.getKycList("kycId").then((val=>{
            if(this.isNull(val)){
                  return;
            }
            this.idsObj = JSON.parse(val);
            this.orderList = JSON.parse(val)[this.did]["kyc"][this.aprType]["order"];
            this.serialNumList = this.objtoarr(this.orderList);
     }));
  }

  onNext(item) {
      if(this.isNull(item["status"])){
        this.getAppAuth(item["serialNum"],item["txHash"]);
      }else {
          this.params = item["params"];
          this.params["orderStatus"] = this.idsObj[this.did]["kyc"][this.aprType]["order"][item["serialNum"]]["status"];
          this.params["serialNum"] = item["serialNum"];
          if(this.params["type"] === "company"){
            this.Go(CompanyWriteChainPage,this.params);
          }else{
            this.Go(PersonWriteChainPage,this.params);
          }
      }

  }

    getAppAuth(serialNum,txHash){
    console.log("getAppAuth======= txHash type "+typeof(txHash));
    console.log('ElastosJs----getAppAuth----'+"---serialNum---"+serialNum+"---txHash---"+txHash);
    let timestamp = this.getTimestamp();
    let parms ={"serialNum":serialNum,
                "txHash":txHash,
                "timestamp":timestamp,
               }
    let checksum = IDManager.getCheckSum(parms,"asc");
    parms["checksum"] = checksum;
    this.getHttp().postByAuth(ApiUrl.APP_AUTH,parms).toPromise().then().then(data => {
      if(data["status"] === 200){
        console.log("sssss======="+JSON.stringify(data));
        let authResult = JSON.parse(data["_body"]);
        if(authResult["errorCode"] === "1"){
          this.messageBox("text-id-kyc-auth-fee-fail");
          return;
        }
        if(authResult["errorCode"] === "2"){
                 this.messageBox("text-id-kyc-auth-query-timeout");
                 return;
        }
        if(authResult["errorCode"] === "4"){
            this.messageBox("text-id-kyc-auth-uncompleted");
               return;
        }
        if(authResult["errorCode"] === "0"){
            this.params["adata"] = authResult["data"];
            this.saveSerialNumParm(serialNum);
        }
       }
    }).catch(error => {

    });
  }

  saveSerialNumParm(serialNum){
     this.idsObj[this.did]["kyc"][this.aprType]["order"][serialNum]["status"] = 1;
     this.idsObj[this.did]["kyc"][this.aprType]["order"][serialNum]["params"] = this.params;
     this.localStorage.set("kycId",this.idsObj).then(()=>{
      this.params["orderStatus"] = this.idsObj[this.did]["kyc"][this.aprType]["order"][serialNum]["status"];
      this.params["serialNum"] = serialNum;
      if(this.params["type"] === "company"){
       this.Go(CompanyWriteChainPage,this.params);
      }else{
        this.Go(PersonWriteChainPage,this.params);
      }
     });
  }
}
