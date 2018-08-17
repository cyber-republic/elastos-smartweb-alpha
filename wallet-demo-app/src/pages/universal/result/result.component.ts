import { Component, OnInit } from '@angular/core';
import {BaseComponent} from './../../../app/BaseComponent';
import {HomeComponent} from "../../tabs/home/home.component";

@Component({
  selector: 'app-result',
  templateUrl: './result.component.html',
  // styleUrls: ['./result.component.scss']
})
export class ResultComponent  extends BaseComponent implements OnInit  {
  type: string;
  ngOnInit() {
    // this.type = this.activateRoute.snapshot.params['type'];
  }

  back(): void {
    this.Go(HomeComponent);
  }

}
