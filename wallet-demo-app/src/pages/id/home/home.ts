import { Component,OnInit } from '@angular/core';
import {BaseComponent} from "./../../../app/BaseComponent";
import {IdImportComponent} from "../../../pages/id/import/import";
import {IdManagerComponent} from "../../../pages/id/manager/manager";
import {IdAppListComponent} from "../../../pages/id/app-list/app-list";
import {TabsComponent} from "../../../pages/tabs/tabs.component";
import { Config } from '../../../providers/Config';
@Component({
  selector: 'id-home',
  templateUrl: 'home.html',
})
export class IdHomeComponent extends BaseComponent implements OnInit{
  public kycIdArr:any;
  ngOnInit(){
    this.setTitleByAssets('text-id-home');
    this.setLeftIcon("",()=>{
       this.Go(TabsComponent);
    });

    var self = this;
    this.localStorage.get("kycId").then((val)=>{

             let seqNumJsonObj = JSON.parse(val);
             this.kycIdArr = this.objtoarr(seqNumJsonObj);

             console.info("ElastosJs IdHomeComponent val" + val);
             self.initSeqObj(seqNumJsonObj);

             this.kycIdArr.forEach(function(e){
               console.info("ElastosJs IdHomeComponent e.id registerIdListener begin  " + e.id);
               self.walletManager.registerIdListener(e.id, (data) => {

                 console.info("home.ts ElastosJs ngOnInit registerIdListener "+ JSON.stringify(data));
                 //alert("home.ts createDID registerIdListener  data  callback"+ JSON.stringify(data));
                 //first commit
                 if(data["path"] == "Added"){

                   let valueObj = JSON.parse(data["value"]) ;
                   if((valueObj["Contents"].length > 0) && valueObj["Contents"][0]["Proof"]){

                     let proofObj = JSON.parse(valueObj["Contents"][0]["Proof"]);

                     console.info("home.ts ElastosJs ngOnInit proofObj[\"signature\"]  "+ proofObj["signature"]);
                     let seqNumObj = self.dataManager.getSeqNumObj(proofObj["signature"]);

                     let serialNum =  seqNumObj["serialNum"] ;
                     console.info("home.ts ElastosJs ngOnInit serialNum "+ serialNum);
                     self.setOrderStatus(3,serialNum);
                   }
                 }
                 //alert("home.ts createDID registerIdListener ngOnInit data  callback"+ JSON.stringify(data));
                 //console.info("home.ts ElastosJs createDID registerIdListener " + JSON.stringify(data));

                 console.info("home.ts ElastosJs ngOnInit registerIdListener  data  callback !!!!!" + JSON.stringify(data));

               });
               console.info("ElastosJs IdHomeComponent e.id  end registerIdListener" + e.id);
              });


    });

    this.events.subscribe('idhome:update', () => {
      this.localStorage.get("kycId").then((val)=>{
        this.kycIdArr = this.objtoarr(JSON.parse(val));
      });
    });
  }

  initSeqObj(allStoreSeqNumJsonObj){
    console.info("ElastosJs initSeqObj begin allStoreSeqNumJsonObj" + JSON.stringify(allStoreSeqNumJsonObj));
    var self = this;

    let ids = allStoreSeqNumJsonObj;
    for(let id in ids){
      let  idJsonObj = ids[id];
      if (! idJsonObj["kyc"]){
        continue;
      }

      for (let authType in idJsonObj["kyc"]){
        if (!idJsonObj["kyc"][authType]["order"]){
          continue
        }
        let order = idJsonObj["kyc"][authType]["order"];

        for (let prop in order) {

          if ( order[prop]["params"] && order[prop]["params"]["adata"])
          {
            var addataArry = [];
            addataArry = order[prop]["params"]["adata"];
            addataArry.forEach(function (value) {
              if (value && value["retdata"]) {
                if ( value["retdata"]["signature"]) {
                  let sign = value["retdata"]["signature"];
                  self.dataManager.addSeqNumObj(sign, order[prop] );
                 //console.info( "ElastosJs add sign " + sign + " obj "+ JSON.stringify(order[prop]));
                }
              }
            })
          }
        }
      }
    }
    console.info("ElastosJs initSeqObj end ");
  }

  onNext(type){
    switch (type){
      case 0:
        this.createDID();
        break;
      case 1:
        this.Go(IdImportComponent);
        break;
      case 2:
        this.Go(IdManagerComponent);
        break;
    }
  }

  onItem(item){
    this.Go(IdAppListComponent,{"id":item.id});
  }

  createDID(){

    this.walletManager.createDID("s12345678",(result)=>{
      let idObj ={id:result.didname};
      let self = this;
      this.walletManager.registerIdListener(result.didname, (data) => {

        console.info("home.ts ElastosJs createDID registerIdListener "+ JSON.stringify(data));
        //alert("home.ts createDID registerIdListener  data  callback"+ JSON.stringify(data));
        //first commit
        if(data["path"] == "Added"){

          let valueObj = JSON.parse(data["value"]) ;
          if((valueObj["Contents"].length > 0) && valueObj["Contents"][0]["Proof"]){

            let proofObj = JSON.parse(valueObj["Contents"][0]["Proof"]);

            console.info("home.ts ElastosJs createDID proofObj[\"signature\"]  "+ proofObj["signature"]);
            let seqNumObj = self.dataManager.getSeqNumObj(proofObj["signature"]);

            let serialNum =  seqNumObj["serialNum"] ;
            console.info("home.ts ElastosJs createDID serialNum "+ serialNum);
            self.setOrderStatus(3,serialNum);
            //alert("home.ts createDID registerIdListener  data  callback"+ JSON.stringify(data));

            /*for(let ele of valueObj["Contents"]){
              //get value

              let proofObj = JSON.parse(ele["Proof"])

              //newSeqNumObj这里可能有多个 提交的。 要找到path对应的那个
              let newSeqNumObj = self.dataManager.getSeqNumObj(proofObj["signature"]);

              //遍历result中的proof 找到对应的seqNumObj 比较这两个seqNumObj中的关键字。如果相同则先删除后添加。
              //否则添加
              self.walletManager.didGetValue(data["id"] , ele["Path"] ,(result)=>{

              })
              //check duplicate

              //setvalue
            }*/
            //

          }
        }

        //console.info("home.ts ElastosJs createDID registerIdListener " + JSON.stringify(data));

        console.info("home.ts ElastosJs createDID registerIdListener  data  callback !!!!!" + JSON.stringify(data));


      });


      this.localStorage.add("kycId",idObj).then(()=>{
           this.kycIdArr.push({id:result.didname});
      });
    });
  }


  getDID(){
    this.walletManager.getDIDList((result)=>{
      this.kycIdArr = JSON.parse(result["list"]);
    });
  }

  setOrderStatus(status,serialNum){

    console.info("setOrderStatus begin status " + status +" serialNum " + serialNum);

    let serids = Config.getSerIds();
    let serid = serids[serialNum];

    console.info("setOrderStatus serid" + JSON.stringify(serid));
    console.info("setOrderStatus serids" + JSON.stringify(serids));

    let did = serid["id"];
    let appName = serid["appName"];
    let appr = serid["appr"];

    console.info("setOrderStatus appr" + appr);

    let idsObj = {};
    this.localStorage.getKycList("kycId").then((val)=>{
        if(val == null || val === undefined || val === {} || val === ''){
             return;
        }
     idsObj = JSON.parse(val);
     idsObj[did][appName][appr]["order"][serialNum]["status"] = status;
     this.localStorage.set("kycId",idsObj).then(()=>{
          this.events.publish("order:update",3,appr);
     });
    });
}
}
