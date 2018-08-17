import { Component,OnInit } from '@angular/core';
import {BaseComponent} from "../../../../app/BaseComponent";
import {IdHomeComponent} from "../../../../pages/id/home/home";
import {IDManager} from "../../../../providers/IDManager";
import { Config } from '../../../../providers/Config';
//{notary:"COOIX"}

@Component({
  selector: 'page-person-write-chain',
  templateUrl: 'person-write-chain.html',
})
export class PersonWriteChainPage extends BaseComponent implements OnInit{
  type: string;
  pageObj = {};
  personObj={
     fullName:'sss',
     identityNumber:'410426198811151012',
     mobile:'18210230496',
     cardNumber:'6225260167820399',
     cardMobile:'18210230496'
  }

  phoneObj={
    fullName:'sss',
    identityNumber:'410426198811151012',
    mobile:'18210230496'
  }

  debitObj={
    fullName:'sss',
    identityNumber:'410426198811151012',
    cardNumber:'6225260167820399',
    cardMobile:'18210230496'
  }

  message:any={Id:"",Path:"",Proof:"",DataHash:"",Sign:""};
  passworld:string="";
  programJson:string;
  fromAddress:string;
  fee:number;
  did:string;
  idObj:any={};
 depositTransaction:string;
 depositTransactionFee:number;
 signature:string;
 orderStatus = 0;
 serialNum = "";
 ngOnInit(){
   this.events.subscribe("order:update",(orderStatus,appr)=>{
    if(appr === "person"){
      this.orderStatus = orderStatus;
    }
   });
    this.setTitleByAssets('text-kyc-result');
    this.idObj = this.getNavParams().data;
    console.log("ngOnInit ====="+JSON.stringify(this.idObj));
    this.did = this.idObj["id"];
    this.orderStatus = this.idObj["orderStatus"];
    this.serialNum = this.idObj["serialNum"];
    this.getPerson();
    if(this.isNull(status)){
      this.type = '0';
    }else{
      this.type = status;
    }
    this.setLeftIcon('',()=>{
           this.Go(IdHomeComponent);
    });
  }
  getPerson(){
    this.pageObj = this.getPageObj(this.idObj["adata"]);
    let index = this.idObj["adata"].length-1;
    let adata = this.idObj["adata"][index];
    //let pesronObj = adata["retdata"];

    this.message["Path"] = adata["type"];
    // this.approdType =  adata["type"];
    // if(this.message["Path"] === "identityCard"){
    //      this.personObj["fullName"] = pesronObj["fullName"];
    //      this.personObj["identityNumber"] = pesronObj["identityNumber"];
    //      this.signature = pesronObj["signature"];
    // }else if(this.message["Path"] === "phone"){
    //      this.phoneObj["fullName"] =  pesronObj["fullName"];
    //      this.phoneObj["identityNumber"] =  pesronObj["identityNumber"];
    //      this.phoneObj["mobile"] = pesronObj["mobile"];
    //      this.signature = pesronObj["signature"];
    // }else if(this.message["Path"] === "bankCard"){
    //     this.debitObj["fullName"] =  pesronObj["fullName"];
    //     this.debitObj["identityNumber"] =  pesronObj["identityNumber"];
    //     this.debitObj["cardNumber"] = pesronObj["cardNumber"];
    //     this.debitObj["cardMobile"] = pesronObj["mobile"];
    //     this.signature = pesronObj["signature"];
    // }

  }

  onCommit(){
    this.popupProvider.presentPrompt().then((val)=>{
              if(this.isNull(val)){
                this.messageBox("text-id-kyc-prompt-password");
                return;
              }
              this.passworld = val.toString();
              this.caulmessageNew();
    }).catch(()=>{

    });
    //this.didGenerateProgram();
  }

  didGenerateProgram(){

    console.log("---didGenerateProgram----"+"message="+JSON.stringify(this.message)+"passworld"+this.passworld);
    //console.log("---didGenerateProgram DataHash.length----"+ this.message.DataHash.length);
    //console.log("---didGenerateProgram----Sign.length"+ this.message.Sign.length);
    //console.log("---didGenerateProgram----Proof"+  this.message.Proof);
    //console.log("---didGenerateProgram----Proof"+ JSON.stringify(this.message.Proof) );

    this.walletManager.didGenerateProgram(this.did,JSON.stringify(this.message),this.passworld,(result)=>{
                   this.programJson  = result.value;
                   console.log("ElastosJs didGenerateProgram programJson "+JSON.stringify(this.programJson));
                   this.createfromAddress();
    });
  }

  createfromAddress(){
    this.walletManager.createAddress("IdChain",(result)=>{
              this.fromAddress = result.address;
              this.cauFee();
    });
  }

  cauFee(){

    //alert("createIdTransaction before" + this.fromAddress);
    this.walletManager.createIdTransaction("IdChain","",this.message,this.programJson,"","",(result)=>{
            console.log("---createIdTransaction---"+"fromAddress="+this.fromAddress+"message="+JSON.stringify(this.message)+"programJson="+this.programJson);
             let rawTransaction = result['json'].toString();
             console.log("createIdTransaction rawTransaction =="+rawTransaction);
             this.calculateTransactionFee(rawTransaction);
     });
  }

  calculateTransactionFee(rawTransaction){
     this.walletManager.calculateTransactionFee("IdChain", rawTransaction,10000, (data) => {

      this.fee = data['fee'];
      //console.log("Elastos 111111111111111");
      console.log("rawTransaction" + JSON.stringify(rawTransaction));
      console.log("calculateTransactionFee fee=="+JSON.stringify(this.fee));
      this.popupProvider.presentConfirm(this.fee/Config.SELA).then(()=>{
            this.sendRawTransaction(rawTransaction);
      });

     });
  }
//////////////////////
  getKycContent(authType, authData){

    let retContent = {};

    switch (authData.type)
    {
      case "identityCard":
        retContent["fullName"] = authData["retdata"]["fullName"];
        retContent["identityNumber"] = authData["retdata"]["identityNumber"];
        break;

      case "phone":
        retContent["fullName"] =  authData["retdata"]["fullName"];
        retContent["identityNumber"] =  authData["retdata"]["identityNumber"];
        retContent["mobile"] = authData["retdata"]["mobile"];
        break;

      case "bankCard":
        retContent["fullName"] =  authData["retdata"]["fullName"];
        retContent["identityNumber"] =  authData["retdata"]["identityNumber"];
        retContent["cardNumber"] = authData["retdata"]["cardNumber"];
        retContent["cardMobile"] = authData["retdata"]["mobile"];
        break;

      case "enterprise":
        retContent["word"] = authData["retdata"]["word"];
        retContent["legalPerson"] = authData["retdata"]["legalPerson"];
        retContent["registrationNum"] = authData["retdata"]["RegistrationNum"];
        break;
    }
    return retContent;
  }

  getcontent(authType, authData){

    let retContent = {};
    retContent["Path"] = 'kyc' +'/' +authType +'/'+ authData["type"];

    let proofObj = {
      signature : authData["retdata"]["signature"],
      notary : "COOIX"
    }

    retContent["Proof"] = JSON.stringify(proofObj);

    console.info("getcontent Proof "+ retContent["Proof"]);

    let kycContent = this.getKycContent(authType, authData);

    console.info("getcontent kycContent "+ JSON.stringify(kycContent));

    let authDataHash = IDManager.hash(JSON.stringify(kycContent)+retContent["Proof"]);
    retContent["DataHash"] = IDManager.hash(authDataHash+retContent["Proof"]);

    console.info("getcontent retContent "+ JSON.stringify(retContent));

    return retContent;
  }

  caulmessageNew(){

    //
    ///////////////////////
    let signMessage= {};

    signMessage["Id"] = this.did ;//
    //signMessage["Sign"] = "" ;//
    signMessage["Contents"] =[];

    let content ;
    let params = this.idObj;//

    for (let ele of params.adata) {
      content = this.getcontent(params.type , ele);
      signMessage["Contents"].push(content);
    }

    console.log("caulmessageNew "+JSON.stringify(signMessage));
    //alert("caulmessageNew "+JSON.stringify(signMessage));

    this.walletManager.didSign(this.did,JSON.stringify(signMessage),this.passworld,(result)=>{
      this.message = {
        Id : this.did,
        Sign :result.value,
        Contents: signMessage["Contents"],
      };

      this.didGenerateProgram();
    });
  }
////////////////////////


  caulmessage(){

     //kyc 内容
     let kycContent={};
    if(this.message["Path"] === "identityCard"){
            kycContent = this.personObj;
         this.message["Path"] = 'kyc'+"|"+"person"+"|"+"identityCard";
     }else if(this.message["Path"] === "phone"){
            kycContent = this.phoneObj;
         this.message["Path"] = 'kyc'+"|"+"person"+"|"+"phone";
     }else if(this.message["Path"] === "bankCard"){
            kycContent = this.debitObj;
          this.message["Path"] = 'kyc'+"|"+"person"+"|"+"bankCard";
     }
     //kyc 结果
     let authSign = {
                     signature:this.signature,
                     notary:"COOIX"
                    }
    console.log("caulmessage this.signature " +this.signature);
    console.log("caulmessage this.signature " +this.signature);

    let authDataHash = IDManager.hash(JSON.stringify(kycContent)+JSON.stringify(authSign));

    //console.log("caulmessage 2"+ authDataHash);


    let kycChainDataHash = IDManager.hash(authDataHash+JSON.stringify(authSign));

    console.log("caulmessage kycChainDataHash.length " +kycChainDataHash.length);

    //console.log("caulmessage 3"+ kycChainDataHash);

    let singObj = {Id:this.did,Path:this.message["Path"],Proof:authSign,DataHash:kycChainDataHash};

     this.walletManager.didSign(this.did,JSON.stringify(singObj),this.passworld,(result)=>{
      console.log("didSign 4"+ JSON.stringify(result));

       let proofString = JSON.stringify(authSign);
       //console.log("didSign proofString"+ proofString);

       this.message = {Id:this.did,Path:this.message["Path"],Proof: proofString,DataHash:kycChainDataHash,Sign:result.value};
       this.didGenerateProgram();
       //console.log("caulmessage Sign " +result.value + " result.value length "+ result.value.length);
       //console.log("didSign 5"+ JSON.stringify(this.message));

     });
 }

  sendRawTransaction( rawTransaction){
    //alert("sendRawTransaction begin==");

    this.walletManager.sendRawTransaction("IdChain",rawTransaction,this.fee,this.passworld,(result)=>{


      let rawTransactionObj = JSON.parse(rawTransaction);

      console.log("ElastosJs ---sendRawTransaction---"+"rawTransaction="+JSON.stringify(rawTransactionObj)+"fee="+this.fee);
      //console.log("ElastosJs ---sendRawTransaction--- PayLoad"+ JSON.stringify(rawTransactionObj.PayLoad));

      if (!rawTransactionObj.PayLoad) {
        console.log("ElastosJs ---sendRawTransaction--- PayLoad NULL");
        return;
      }

      if (!rawTransactionObj["PayLoad"]["Contents"]){
        console.log("ElastosJs ---sendRawTransaction--- Contents NULL");
        return ;
      }

      for (let ele of rawTransactionObj["PayLoad"]["Contents"] ) {

        console.log("ElastosJs ---sendRawTransaction--- ele " + JSON.stringify(ele));
        let arr = ele["Path"].split("/");

        if (arr[1]) {

          let proofObj = JSON.parse(ele["Proof"]);
          let self = this;

          this.localStorage.getSeqNumObj(proofObj["signature"], rawTransactionObj.PayLoad.Id,"kyc", arr[1], function (reult : any) {
            console.info("ElastosJs reult" + JSON.stringify(reult) );
            self.dataManager.addSeqNumObj(proofObj["signature"] , reult );

          });
        }
      }

      this.setOrderStatus(2);
      //this.messageBox("text-id-kyc-china");
    })
  }

 // sendRawTransaction( rawTransaction){
 //    //alert("sendRawTransaction begin==");
 //
 //    this.walletManager.sendRawTransaction("IdChain",rawTransaction,this.fee,this.passworld,(result)=>{
 //
 //
 //     let rawTransactionObj = JSON.parse(rawTransaction);
 //
 //      console.log("ElastosJs ---sendRawTransaction---"+"rawTransaction="+JSON.stringify(rawTransactionObj)+"fee="+this.fee);
 //      //console.log("ElastosJs ---sendRawTransaction--- PayLoad"+ JSON.stringify(rawTransactionObj.PayLoad));
 //
 //      if (rawTransactionObj.PayLoad) {
 //        let arr = rawTransactionObj.PayLoad.Path.split("|");
 //        //
 //        if (arr[1]) {
 //
 //          //let proofStr = rawTransactionObj.PayLoad.Proof;
 //          let proofObj = JSON.parse(rawTransactionObj.PayLoad.Proof);
 //          let self = this;
 //          //console.info("ElastosJs this.dataManager 1111111 " + this.dataManager );
 //           this.localStorage.getSeqNumObj(proofObj["signature"], rawTransactionObj.PayLoad.Id,"kyc", arr[1], function (reult : any) {
 //           console.info("ElastosJs reult" + JSON.stringify(reult) );
 //
 //            self.dataManager.addSeqNumObj(proofObj["signature"] , reult );
 //            // if (reult) {
 //            //
 //            // }
 //          });
 //
 //
 //
 //        }
 //
 //      }
 //
 //
 //      this.messageBox("text-id-kyc-china");
 //    })
 // }


 //从主链转一批钱到测链

createDepositTransaction(){
  this.walletManager.createDepositTransaction("ELA","","XQd1DCi6H62NQdWZQhJCRnrPn7sF9CTjaU",this.fee,this.fromAddress,"qq",this.fee+"","","",(result)=>{
            this.depositTransaction = result['transactionId'].toString();
            //this.getDepositTransaction();
  });
}

getDepositTransaction(){
  this.walletManager.calculateTransactionFee("ELA",this.depositTransaction,10000, (data) => {
    this.depositTransactionFee = data['fee'];
  });
}

 sendDepositTransaction(){
     this.walletManager.sendRawTransaction("ELA",this.depositTransaction,20000,this.passworld,(result)=>{
       alert("sendDepositTransaction result"+JSON.stringify(result));
     })
 }



getPageObj(obj){
  let aprObj ={};

for(let index in obj){
 let data = obj[index];
 let retdata= data["retdata"];
 if(data["type"] === "identityCard"){
   aprObj["identityCard"] = {"identityNumber":retdata["identityNumber"],"fullName":retdata["fullName"]}
 }else if(data["type"] === "phone"){
   aprObj["phone"] = {"mobile":retdata["mobile"]};
 }else if(data["type"] === "bankCard"){
   aprObj["bankCard"] = {"cardMobile":retdata["mobile"],"cardNumber":retdata["cardNumber"]};
 }
}
 return aprObj;
}


// setOrderStatus(){
//   let serids = Config.getSerIds();
//   let serid = serids[this.serialNum];
//   let did = serid["id"];
//   let appName = serid["appName"];
//   let appr = serid["appr"];
//   let idsObj = {};
//   this.localStorage.getKycList("kycId").then((val)=>{
//       if(val == null || val === undefined || val === {} || val === ''){
//            return;
//       }
//    idsObj = JSON.parse(val);
//    idsObj[did][appName][appr]["order"][this.serialNum]["status"] = 2;
//    this.localStorage.set("kycId",idsObj).then(()=>{
//             this.orderStatus = 2;
//    });
//   });
// }
// }


  setOrderStatus(status){
    console.info("setOrderStatus status begin" + status);
    let serids = Config.getSerIds();
    let serid = serids[this.serialNum];
    let did = serid["id"];
    let appName = serid["appName"];
    let appr = serid["appr"];
    let idsObj = {};
    this.localStorage.getKycList("kycId").then((val)=>{
      if(val == null || val === undefined || val === {} || val === ''){
        console.info("setOrderStatus val == null return ");
        return;
      }
      idsObj = JSON.parse(val);
      idsObj[did][appName][appr]["order"][this.serialNum]["status"] = status;
      this.localStorage.set("kycId",idsObj).then(()=>{
        console.info("setOrderStatus  end  status " + status);
        this.orderStatus = status;
      });
    });
  }
}

