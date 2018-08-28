import { NgModule } from '@angular/core';
import { LocalimportComponent } from './localimport/localimport';
import { IonicPageModule } from 'ionic-angular';

import { BrowserModule } from '@angular/platform-browser';

@NgModule({
	declarations: [LocalimportComponent],
	imports:[
		BrowserModule,
		IonicPageModule.forChild(LocalimportComponent)  // <- Add
	 ],
	exports: [LocalimportComponent]
})
export class ComponentsModule {}
