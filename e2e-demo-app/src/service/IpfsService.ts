import {Base} from './Base';
import ipfsAPI from 'ipfs-api';
import C from '../config';

declare var Buffer;

const config = C.ipfs;

export class IpfsService extends Base {
  private api;

  _init(){
    this.connect();
  }
  connect(url = config.url){
    this.api = ipfsAPI(config.url);
  }

  getAPI(){
    return this.api;
  }

  async fetchListByPath(path){
    const list = await this.api.files.ls(path);
    const result = [];
    for(let i=0, len=list.length; i<len; i++){
      const tmp = await this.api.files.stat(path+'/'+list[i].name);
      tmp.name = list[i].name;
      result.push(tmp);
    }
    return result;
  }

  async getFileBuffer(hash){
    const rs = await this.api.files.get(hash);

    return rs[0].content;
  }
  async getFileStream(hash){
    const rs = await this.api.files.getReadableStream(hash);
    console.log(rs);

    return rs;
  }

  async addFileToPath(path, content){
    return await this.api.files.write(path, Buffer.from(content), {create: true});


  }

  async addDir(path){
    return await this.api.files.mkdir(path);
  }

  async removeByPath(path){
    return await this.api.files.rm(path, {recursive: true});
  }
}