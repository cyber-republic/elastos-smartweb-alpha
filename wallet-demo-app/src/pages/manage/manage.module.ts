import {NgModule} from '@angular/core';
import {IonicPageModule} from 'ionic-angular';
import {ManagePage} from './manage';

@NgModule({

  imports: [
    IonicPageModule.forChild(ManagePage),
  ],
})
export class ManagePageModule {
}
