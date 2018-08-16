import { Component } from '@angular/core';
import {Base} from '../Base';
import {FileViewPage} from '../file_view';
import {Log} from '../../utility/Log';


@Component({
  selector: 'page-ipfs_info',
  templateUrl: 'main.html'
})
export class IpfsInfoPage extends Base {
  private list: any[];
  private api: any;
  private path;

  _init(){
    this.api = this.ipfsService.getAPI();
  }

  async getListByPath(path){
    this.path = path;
    this.showLoading();
    const list = await this.ipfsService.fetchListByPath(path);
    this.list = list;
    this.hideLoading();
  }
  
  async ionViewDidLoad_AfterLogin(){

    await this.getListByPath('/');
  }

  async clickItem(item){
    if(item.type !== 'file'){
      await this.getListByPath(this.path+'/'+item.name);
    }
    else{
      // const rs = await this.ipfsService.getFileBuffer(item.hash);
      // console.log(rs.toString('utf8'));
      const modal = this.modalCtrl.create(FileViewPage, {
        item,
      });
      modal.present();
    }
  }
  async goUp(){
    if(this.path){
      const path = this.path.split('/').slice(0, -1).join('/');
      await this.getListByPath(path);
    }
    
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
        await this.ipfsService.addFileToPath(this.path+'/'+file.name, buf);
        await this.getListByPath(this.path);
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
      title: this.getLang('ipfs.0002'),
      message: this.getLang('ipfs.0008'),
      inputs: [
        {
          name: 'title',
          placeholder: this.getLang('ipfs.0008'),
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
              await this.ipfsService.addDir(this.path+'/'+name);
              await this.getListByPath(this.path);
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
      title : this.getLang('ipfs.0003'),
      buttons: [
        {
          text : this.getLang('ipfs.0004'),
          handler : ()=>{
            const prompt = this.alertCtrl.create({
              title: this.getLang('ipfs.0004'),
              message: this.getLang('ipfs.0006'),
              inputs: [
                {
                  name: 'title',
                  placeholder: this.getLang('ipfs.0007')
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
                      await this.ipfsService.getAPI().files.mv(this.path+'/'+item.name, this.path+'/'+name);
                      await this.getListByPath(this.path);
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
          text : this.getLang('ipfs.0005'),
          role : 'destructive',
          handler : ()=>{
            this.showLoading();
            this.ipfsService.removeByPath(this.path+'/'+item.name).then(async ()=>{
              await this.getListByPath(this.path);
              this.hideLoading();
            });

          }
        }
      ]
    });

    actionSheet.present();
  }

  
}
