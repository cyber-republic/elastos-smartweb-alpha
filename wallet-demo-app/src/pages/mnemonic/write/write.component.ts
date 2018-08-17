import {Component, OnInit} from '@angular/core';
import {BaseComponent} from './../../../app/BaseComponent';
import {TabsComponent} from "../../tabs/tabs.component";
import {Util} from "../../../providers/Util";


@Component({
  selector: 'app-write',
  templateUrl: './write.component.html',
})
export class WriteComponent extends BaseComponent implements OnInit {


  mnemonicList: Array<any> = []
  selectList: Array<any> = [];
  mnemonicStr: string;
  selectComplete = false;

  ngOnInit() {
    // this.setHeadDisPlay({left:false});
    this.setTitleByAssets('text-mnemonic-check');
    this.mnemonicStr = this.clone(this.getNavParams().get("mnemonicStr"));
    this.mnemonicList = this.clone(this.getNavParams().get("mnemonicList")).sort(function(){ return 0.5 - Math.random() });
  }

  onNext() {
    let mn = "";
    for(let i =0;i<this.selectList.length;i++){
      mn += this.selectList[i].text;
    }
    //hptest
    if(!Util.isNull(mn) && mn == this.mnemonicStr.replace(/\s+/g,"")){
      this.toast('text-mnemonic-ok');
      //this.Go(TabsComponent)
      this.setRootRouter(TabsComponent);
    }else{
      this.toast('text-mnemonic-prompt3');
    }

    //this.Go(TabsComponent);
  }

  public addButton(index: number, item: any): void {
    var newWord = {
      text: item.text,
      prevIndex: index
    };
    this.selectList.push(newWord);
    this.mnemonicList[index].selected = true;
    this.shouldContinue();
  }



  public removeButton(index: number, item: any): void {
    // if ($scope.loading) return;
    this.selectList.splice(index, 1);
    this.mnemonicList[item.prevIndex].selected = false;
    this.shouldContinue();
  }

  private shouldContinue(): void {
    this.selectComplete = this.selectList.length === this.mnemonicList.length ? true : false;
  }
}
