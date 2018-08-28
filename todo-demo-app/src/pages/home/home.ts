import { Component } from '@angular/core';
import { ModalController, NavController } from 'ionic-angular';

import { AddItemPage } from '../add-item/add-item';

import { DataProvider } from '../../providers/data/data';


//import Wallet;

@Component({
  selector: 'page-home',
  templateUrl: 'home.html',
  providers :[DataProvider]
})
export class HomePage {
 public items;
  constructor(public navCtrl: NavController, public modalCtrl: ModalController, public dataService: DataProvider) {

	this.dataService.getData().then((todos) => { 
      if(todos){
        this.items = JSON.parse(todos); 
      } else {
		this.items = [
		  {title: 'Elastos TODO1', description: 'TODO List1'},
		  {title: 'Elastos TODO2', description: 'TODO List2'},
		  {title: 'Elastos TODO3', description: 'TODO List3'}
		];
	  }
    });

  } 
  ionViewDidLoad(){

    /* 开始，
	  	//Second  Carrier  Wallet  UID components 
	var a_wallet = new Wallet()
    result = a_wallet.CreateSubWallet (
             chainID,  
           coinTypeIndex,    // 新增，币种的index号，用于构建路径
           payPassword,
          singleAddress)
		
		  
     this.items = [
      {title: 'Elastos TODO1', description: 'TODO List1'},
      {title: 'Elastos TODO2', description: 'TODO List2'},
      {title: 'Elastos TODO3', description: 'TODO List3'}
    ];
	   */
   }
   
	addItem(){
     let addModal = this.modalCtrl.create(AddItemPage);
     addModal.onDidDismiss((item) => {
           if(item){
            this.saveItem(item);
          }
     });
     addModal.present();
   }
   
   saveItem(item){
    this.items.push(item);
    this.dataService.save(this.items);
   }

   viewItem(){
   }

}
