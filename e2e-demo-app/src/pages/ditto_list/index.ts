import { Component } from '@angular/core';
import {Base} from '../Base';
import {DittoDetailPage} from '../ditto_detail';
import {Log} from '../../utility/Log';

@Component({
  selector: 'page-ditto_list',
  templateUrl: 'main.html'
})
export class DittoListPage extends Base {
  private list: any[];
  private showUpBtn = false;
  private path: string;

  _init(){
    this.path = '';
  }

  async ionViewDidLoad_AfterLogin(){
    const param = this.navParam.data;
    this.showLoading('init carrier');
    this.dittoService.start(()=>{
      this.goToDir(this.path);
    }, param);
    // await this.goToDir(this.path);
  }

  async goToDir(path){
    this.showLoading();
    try{
      if(!path){
        // root 
        this.list = await this.dittoService.fetchList('/');
      }
      else{
        this.list = await this.dittoService.fetchList(path);
      }
    }catch(e){
      this.warning(e);
      this.navCtrl.pop();
    }
    
    
    this.path = path;
    this.hideLoading();
    this.showUpBtn = path.indexOf('/') !== -1;
  }
  async goUp(){
    if(this.path){
      const path = this.path.split('/').slice(0, -1).join('/');

      await this.goToDir(path);
    }
  }

  async clickItem(item){
    if(item.type === 'dir'){
      const path = this.path + '/' + item.name;
      await this.goToDir(path);
    }
    else{
      await this.goToFile(item);
    }
  }

  async goToFile(item){
    const path = this.path + '/' +item.name;
    item.path = path;
    const modal = this.modalCtrl.create(DittoDetailPage, {
      item,
    });
    modal.present();
  }

  async selectFile(elem){
    if(this._plt.is('cordova')){
      try{
        const uri = await this._fileChooser.open();
        Log.info('select file', uri);
        await this.addFileForCordova(decodeURI(uri));
      }catch(e){
        Log.info('select file error', JSON.stringify(e));
        this.warning(e.message);
      }
      
    }
    else{
      elem.click();
    }
  }

  async addFileForCordova(fileUri){
    const res = await this._filePath.resolveNativePath(fileUri);
    const entity = await this._file.resolveLocalFilesystemUrl(res);

    entity.getParent(async (dirEntity)=>{
      const file = await this._file.getFile(dirEntity, entity.name, {});
      file.file(async (file)=>{
        Log.info('File', JSON.stringify(file));
        await this.addFile({
          files : [file]
        });
      })
    })

  }

  async addFile(elem){
    // console.log(elem.files);
    const file = elem.files[0];
    if(!file){
      this.warning('invalid file');
      return false;
    }

    const fs = new FileReader();
    fs.onload = async (e:any)=>{
      const buf = e.target.result;
      
      try{
        this.showLoading();
        await this.dittoService.writeFileByBuffer(this.path+'/'+file.name, buf);
        await this.goToDir(this.path);
        elem.value = '';
        this.hideLoading();
      }catch(e){
        this.warning(e);
      }
      
    };
    fs.readAsArrayBuffer(elem.files[0]);
  }

  async addFolder(){
    const prompt = this.alertCtrl.create({
      title: this.getLang('ditto.0002'),
      message: this.getLang('ditto.0008'),
      inputs: [
        {
          name: 'title',
          placeholder: this.getLang('ditto.0008'),
        },
      ],
      buttons: [
        {
          text: this.getLang('cancel'),
          handler: (d)=>{}
        },
        {
          text: this.getLang('confirm'),
          handler: async (d)=>{
            const name = d.title;
            if(!name){
              this.warning('invalid name');
              return false;
            }
            this.showLoading();
            try{
              await this.dittoService.createFoler(this.path+'/'+name);
              await this.goToDir(this.path);
            }catch(e){
              this.warning(e);
            }
            this.hideLoading();
          }
        }
      ]
    });
    prompt.present();
  }

  async showItemMenu(item){
    const actionSheet = this.actionSheetCtrl.create({
      title : this.getLang('ditto.0003'),
      buttons: [
        {
          text : this.getLang('ditto.0004'),
          handler : ()=>{
            const prompt = this.alertCtrl.create({
              title: this.getLang('ditto.0004'),
              message: this.getLang('ditto.0006'),
              inputs: [
                {
                  name: 'title',
                  placeholder: this.getLang('ditto.0007')
                },
              ],
              buttons: [
                {
                  text: this.getLang('cancel'),
                  handler: (d)=>{}
                },
                {
                  text: this.getLang('confirm'),
                  handler: async (d)=>{
                    const name = d.title;
                    if(!name){
                      this.warning('invalid name');
                      return false;
                    }
                    this.showLoading();
                    try{
                      await this.dittoService.rename(this.path+'/'+item.name, this.path+'/'+name);
                      await this.goToDir(this.path);
                    }catch(e){
                      this.warning(e);
                    }
                    this.hideLoading();
                  }
                }
              ]
            });
            prompt.present();
          }
        },
        {
          text : this.getLang('ditto.0005'),
          role : 'destructive',
          handler : ()=>{
            this.showLoading();
            this.dittoService.delete(this.path+'/'+item.name).then(async ()=>{
              await this.goToDir(this.path);
              this.hideLoading();
            });

          }
        }
      ]
    });

    actionSheet.present();
  }

}
