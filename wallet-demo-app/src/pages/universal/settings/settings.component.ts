import { Component, OnInit } from '@angular/core';
import {BaseComponent} from './../../../app/BaseComponent';

@Component({
  selector: 'app-settings',
  templateUrl: './settings.component.html',
  // styleUrls: ['./settings.component.scss']
})
export class SettingsComponent  extends BaseComponent implements OnInit {
  cho1: string;
  country: string;
  ngOnInit() {
  }

}
