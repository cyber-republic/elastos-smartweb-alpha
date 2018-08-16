import { Component } from '@angular/core';
import {Base} from '../Base';
import * as _ from 'lodash';
import BlobStream from 'blob-stream';

const C = {
  video : ['mp4'],
  image : ['png', 'jpeg', 'jpg'],
  audio : ['mp3'],
  html : ['html']
};

@Component({
  selector: 'page-file_view',
  templateUrl: 'main.html'
})
export class FileViewPage extends Base {
  private data:any = {};
  private content:any = null;

  private isText = false;
  private isVideo = false;
  private isImage = false;
  private isHtml = false;
  private isAudio = false;

  async ionViewDidLoad(){
    const data = this.navParam.data.item;

    await this.processData(data);
  }

  closeModal(){
    this.viewCtrl.dismiss();
  }

  async processData(data){
    this.data = data;
    const self = this;

    this.showLoading();
    const ext = _.last(data.name.split('.'));

    if(_.includes(C.video, ext)){
      this.isVideo = true;
      await this.handleVideo(data.hash);

    }
    else if(_.includes(C.image, ext)){
      this.isImage = true;
      const buffer = await this.ipfsService.getFileBuffer(data.hash);
      this.content = 'data:image/'+ext+';base64,'+buffer.toString('base64');
    }
    else if(_.includes(C.audio, ext)){
      this.isAudio = true;
    }
    else if(_.includes(C.html, ext)){
      this.isAudio = true;
    }
    else{
      this.isText = true;
      const buffer = await this.ipfsService.getFileBuffer(data.hash);
      this.content = buffer.toString('utf8');
    }
    console.log(this.content);
    this.hideLoading();
  }

  async handleVideo(hash){
    const buffer = await this.ipfsService.getFileBuffer(hash);
    const blob = new Blob([buffer]);
    const url = URL.createObjectURL(blob);
    this.content = this.sanitize(url);
  }
}
