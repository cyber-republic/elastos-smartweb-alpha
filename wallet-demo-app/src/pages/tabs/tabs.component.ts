import { Component, OnInit,ViewEncapsulation  } from '@angular/core';
import 'rxjs/add/observable/timer';
import {BaseComponent} from './../../app/BaseComponent';
//import { TabModule } from 'ngx-weui';
//import { InfiniteLoaderComponent } from 'ngx-weui';


@Component({
  selector: 'app-tabs',
  templateUrl: './tabs.component.html',
  // styleUrls: ['./tabs.component.scss']
  encapsulation: ViewEncapsulation.None

})
export class TabsComponent extends BaseComponent implements OnInit {



  ngOnInit() {
    // this.header.setHeaderDisplay(false);
    // console.log(this.header.getHeaderDisplay());
  }





}
