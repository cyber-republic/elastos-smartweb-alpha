import {Base} from './Base';
import * as _ from 'lodash';
import createClient from 'webdav-fs';
import {wallet} from '../utility';

import C from '../config';

declare var Buffer, cordova: any;


const config: any = C.ditto;

let _instance = null;
export class DittoService extends Base {
    private client;
    private isNative = false;
    private plugin:any;

    static get(isCordova){
        if(!_instance){
            _instance = new DittoService();
            _instance.setIsNative(isCordova);
        }

        return _instance;
    }

    setIsNative(flag){
        if(flag){
            this.isNative = flag;
            this.plugin = cordova.plugins.ElaCarrier;
        }

        console.log('init Ditto Service');
    }

    start(finish, opts:any={}){
        const address = opts.address || config.address || null;
        const username = opts.username || config.username;
        const password = opts.password || config.passowrd;
        if(address){
            this.carrier_init((json)=>{
                // alert(JSON.stringify(json));
                this.carrierCallback(json, finish);
            }, address, config.secret);
        }
        else{
            this.client = createClient(encodeURI(config['url']), username, password);
            finish();
        }
        
    }

    carrierCallback(json:any, finish){
        const key = _.keys(json)[0];

        if(key === 'connected'){
            console.log(json[key]);
            this.client = createClient(encodeURI(config.getUrl(json[key])), config.username, config.password);
            finish && finish();
        }
    }

    _promise(fn, args, endArgs=[]){
        return new Promise((resolve, reject)=>{
            this.client[fn](...args, (err, rs)=>{
                if(err){
                    reject(err);
                }
                else{
                    resolve(rs);
                }
            }, ...endArgs);
        }).catch((e)=>{
            console.error(e);
            throw fn+' error : '+e.message;
        });
    }

    async fetchList(path: string): Promise<any[]>{
        const rs = await this._promise('readdir', [path], ['stat']);
        const list = _.map(rs, (item: any)=>{
            item.type = item.isFile() ? 'file' : 'dir';
            return item;
        });
        return _.sortBy(list, ['type']);
    }


    // create dir with path
    async createFoler(path: string): Promise<any>{
        const rs = await this._promise('mkdir', [path]);
        return rs;
    }

    // rename a folder or file
    async rename(path: string, newPath: string): Promise<any>{
        const rs = await this._promise('rename', [path, newPath]);
        return rs;
    }

    async writeFileByBuffer(path: string, dataOrBuffer): Promise<any>{
        return await this._promise('writeFile', [path, dataOrBuffer]);
    }


    // fetch a file
    async fetchFile(path: string): Promise<any>{
        return this._promise('readFile', [path, 'utf8']);
    }

    // fetch a file, return stream
    async fetchFileByBuffer(path: string): Promise<any>{
        const data = await this._promise('readFile', [path, 'binary']);
        return Buffer.from(data);
    }

    // delete a folder or file
    async delete(path: string): Promise<any>{
        return await this._promise('unlink', [path]);
    }

    carrier_init(callback, address, pwd){
        if(!this.isNative){
            return callback({
                'connected' : '192.168.1.105:8000'
            });
        }
        this.plugin.connect([address, pwd], callback, (arg)=>{
            console.error(arg);
        })
    }
}