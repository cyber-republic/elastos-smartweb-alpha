import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';

declare let require_test: any;
declare let cordova: any;

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})

export class HomePage {
	   carpath = "libElastos.HelloCarDemo.so";
	   

  constructor(public navCtrl: NavController) {
        let type = this.GetQueryString("type");
          switch (type) {
            case "payment":
              this.carpath = this.GetQueryString("txId");
              break;
            case "did_login":
              this.carpath = this.GetQueryString("didNum");
              break;
            default:
              this.carpath = "libElastos.HelloCarDemo.so";;
              break;
          }
  }
  
  GetQueryString(name){
    var reg = new RegExp("(^|&)"+ name +"=([^&]*)(&|$)");
    var r = window.location.search.substr(1).match(reg);
    if(r!=null)return  decodeURI(r[2]); return null;
  }
  
  require_module(){
	 require_test(this.carpath);
  }

  
  require_DID(){
	  //console.log('Error: zhh ', "DATE require_wallet" );
	  cordova.plugins.appmanager.StartApp("wallet/www/index.html" + "?type=did_login&message=this is did login message&backurl=CarTest/www/index.html", 
	  function (data) { }, 
	  function (error) { });
  }
  
  require_pay(){
	  //console.log('Error: zhh ', "DATE require_wallet" );
	  cordova.plugins.appmanager.StartApp("wallet/www/index.html" + "?type=payment&amount=10000&address=EeDUy6TmGSFfVxXVzMpVkxLhqwCqujE1WL&memo=chinajoylottery-f-EHmMW4UVLBkr6QB61CBexUQiXvFigvDJwi-fe5d57161eb78e0d3ff5d5a24398e9aea8914f71e762f06a49cd515b45d96af2&information=sss&backurl=CarTest/www/index.html", 
	  function (data) { }, 
	  function (error) { });
  }
  

}
