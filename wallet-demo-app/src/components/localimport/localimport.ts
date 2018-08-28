import { Component } from '@angular/core';

/**
 * Generated class for the LocalimportComponent component.
 *
 * See https://angular.io/api/core/Component for more info on Angular
 * Components.
 */
@Component({
  selector: 'localimport',
  templateUrl: 'localimport.html'
})
export class LocalimportComponent {

  text: string;

  constructor() {
    console.log('Hello LocalimportComponent Component');
    this.text = 'Hello World';
  }

}
