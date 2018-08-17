import { Component, OnInit } from '@angular/core';
import {BaseComponent} from './../../../app/BaseComponent';
import {ContactListComponent} from "../contact-list/contact-list.component";
import {Util} from "../../../providers/Util";

@Component({
  selector: 'app-contact-create',
  templateUrl: './contact-create.component.html',
  // styleUrls: ['./contact-create.component.scss']
})
export class ContactCreateComponent  extends BaseComponent implements OnInit  {

  name: String;
  address: String;
  phone: String;
  email: String;
  remark: String;

  ngOnInit() {
    this.setTitleByAssets('text-contacts-add');
  }

  add(): void {
    let contactUsers = {
      id: this.name,
      name: this.name,
      address: this.address,
      phone: this.phone,
      email: this.email,
      remark: this.remark
    }
    if (this.isNull(this.name)) {
      this.messageBox("contact-name-notnull");
      return;
    }
    if (this.isNull(this.address)) {
      this.messageBox("contact-address-notnull");
      return;
    }
    if (!Util.isAddressValid(this.address)) {
      this.messageBox("contact-address-digits");
      return;
    }
    if (this.phone && this.checkCellphone(this.phone.toString())) {
      this.messageBox("contact-phone-check");
      return;
    }
    this.localStorage.add('contactUsers', contactUsers).then((val)=>{
      this.Go(ContactListComponent);
    });
  }

}
