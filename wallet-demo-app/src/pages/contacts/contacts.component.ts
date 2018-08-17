import { Component, OnInit } from '@angular/core';
import {BaseComponent} from '../../app/BaseComponent';
import {TransferComponent} from "../coin/transfer/transfer.component";
import {ContactListComponent} from "../contacts/contact-list/contact-list.component";
// import {QrcodeModel} from './../../models/qrcode.model';

@Component({
  selector: 'app-contacts',
  templateUrl: './contacts.component.html',
  // styleUrls: ['./contacts.component.scss']
})
export class ContactsComponent  extends BaseComponent implements OnInit {

  contactUser = {};
  qrcode: string = null;

  ngOnInit() {
    this.setTitleByAssets('text-contacts-info');
    this.setRightIcon('./assets/images/icon/icon-delete.svg', () => {
        this.rightHeader();
    });
    this.setHeadDisPlay({'right': true});
    this.localStorage.get('contactUsers').then((val)=>{
      let id = this.getNavParams().get("id");
      this.contactUser = JSON.parse(val)[id];
      this.qrcode = this.contactUser["address"].toString();
    });
  }

  rightHeader(): void {
    this.localStorage.get('contactUsers').then((val)=>{
      let contactUsers = JSON.parse(val);
      delete(contactUsers[this.contactUser["id"]]);
      this.localStorage.set('contactUsers', contactUsers);
      alert('删除成功');
      this.Go(ContactListComponent);
    });
  }

  pay(): void {
    this.Go(TransferComponent,{id:1});
  }
}
