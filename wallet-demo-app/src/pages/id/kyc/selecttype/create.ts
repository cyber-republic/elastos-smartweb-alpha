import { Component,OnInit } from '@angular/core';
import {BaseComponent} from "../../../../app/BaseComponent";
import {KycOperationPage} from "../../../../pages/id/kyc/kyc-operation/kyc-operation";
@Component({
  selector: 'kyc-select-type',
  templateUrl: 'create.html',
})
export class kycSelectTypeComponent extends BaseComponent implements OnInit{
  idObj:any;
  createData = {
    createType: "person",   //1 个人  2企业
  };
  onChange(type){
    this.createData.createType = type;
  }

  ngOnInit(){
    this.idObj = this.getNavParams().data;
    this.setTitleByAssets('text-id-type');
  }

  onCommit(){
    this.selectType();
  }

  selectType(){
  let id = this.idObj["id"];
  let appName = this.idObj["appName"];
  this.idObj["type"] = this.createData.createType;
  this.localStorage.get("kycId").then((val)=>{
    let idsObj = JSON.parse(val);
    let idObj = idsObj[id][appName];
    if(this.isNull(idObj[this.createData.createType])){
         idObj[this.createData.createType] = {};
          this.localStorage.set("kycId",idsObj).then((newVal)=>{
          this.Go(KycOperationPage,this.idObj);
       });
    }else{
          this.Go(KycOperationPage,this.idObj);
    }
});

  }

}
