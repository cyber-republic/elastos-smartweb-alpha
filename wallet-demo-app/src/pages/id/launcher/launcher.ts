import { Component,OnInit } from '@angular/core';
import {BaseComponent} from "../../../app/BaseComponent";
import {IdImportComponent} from "../../../pages/id/import/import";
import {IdHomeComponent} from "../../../pages/id/home/home";
import {Config} from "../../../providers/Config";

@Component({
  selector: 'id-launcher',
  templateUrl: 'launcher.html',
})
export class IdLauncherComponent extends BaseComponent implements OnInit{
  ngOnInit(){
      this.setTitleByAssets('text-id-my');
  }

  onNext(type){
    switch (type){
      case 0:
        this.createId();
        break;
      case 1:
        this.Go(IdImportComponent);
        break;
    }
  }

  createId(){
    let self = this;
    this.walletManager.createDID("s12345678",(result)=>{

          let idObj ={id:result.didname};


          console.info("ElastosJs luncher.ts createDID result add registerIdListener" + JSON.stringify(result));
          self.walletManager.registerIdListener(result.didname, (data) => {

            console.info("lacucher.ts ElastosJs createDID registerIdListener "+ JSON.stringify(data));
            //alert("home.ts createDID registerIdListener  data  callback"+ JSON.stringify(data));
            //first commit
            if(data["path"] == "Added"){

              let valueObj = JSON.parse(data["value"]) ;
              if((valueObj["Contents"].length > 0) && valueObj["Contents"][0]["Proof"]){

                let proofObj = JSON.parse(valueObj["Contents"][0]["Proof"]);

                console.info("lacucher.ts ElastosJs createDID proofObj[\"signature\"]  "+ proofObj["signature"]);
                let seqNumObj = self.dataManager.getSeqNumObj(proofObj["signature"]);

                let serialNum =  seqNumObj["serialNum"] ;
                console.info("lacucher.ts ElastosJs createDID serialNum "+ serialNum);
                self.setOrderStatus(3,serialNum);
               // alert("lacucher.ts createDID registerIdListener  data  callback"+ JSON.stringify(data));
              }
            }
            //console.info("home.ts ElastosJs createDID registerIdListener " + JSON.stringify(data));

            console.info("lacucher.ts ElastosJs createDID registerIdListener  data  callback !!!!!" + JSON.stringify(data));


          });
          this.localStorage.add("kycId",idObj).then(()=>{
               this.Go(IdHomeComponent);
          });
    })
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


