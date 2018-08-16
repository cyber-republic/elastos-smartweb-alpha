import {Base} from './Base';
import * as _ from 'lodash';
import {randomBytes, createHash} from 'crypto-browserify';
import {WalletService} from './WalletService';
import C from '../config';

declare var cordova: any;

const config = C.did;
let _instance = null;
export class DIDService extends Base {
    static get(isCordova){
        if(!_instance){
            _instance = new DIDService();
            _instance.setIsNative(isCordova);
        }
    
        return _instance;
    }

    private ws = null;
    private isNative = false;

    private didname: string;
    private key_map: any = {};

    setIsNative(flag=false){
        this.isNative = flag;
        this.ws = WalletService.get(flag);
    
        console.log('init DID Service');
    }

    getRootKey(){
        return config.key;
    }

    // async getDidName(){
    //     const key = await this.getPubKey();
    //     if(this.key_map[key]){
    //         this.didname = this.key_map[key];
    //     }
    //     else{
    //         const rs:any = await this.execute('createDID', '12345678');
    //         this.didname = rs.didname;   
    //         this.key_map[key] = rs.didname;
    //     }

    //     return this.didname;
    // }

    // removeDidName(){
    //     this.didname = null;
    //     this.key_map = {};
    // }

    async getPubKey(){
        const rs: any = await this.execute('getPublicKey');
        return rs.publickey;
    }
    

    public async execute(fnName, ...args): Promise<any>{
        const arg = _.map([args], (x)=>{
            return x.toString();
        })
        console.log(fnName + ' args => ' + arg.join(' | '));
        return new Promise((resolve, reject)=>{
            this.ws[fnName](...args, (data: any)=>{
                console.log('WalletService => '+fnName + ' ----- start');
                
                
                console.log(JSON.stringify(data));
                console.log('WalletService => '+fnName + ' ----- end');
                if(data.ERRORCODE){
                    reject(data.ERRORCODE);
                }
                else{
                    resolve(data);
                }
                
            });
        });
    }


    async saveData(did, key, data){
        
        await this.execute('didSetValue', did, key, JSON.stringify({
            '100' : data
        }));
        await this.execute('didGetValue', did, key);

        return true;
    }

    async getData(did, key){
        if(!this.isNative){
            return null;
        }
      
        const rs: any = await this.execute('didGetValue', did, key);
        if(!rs.value){
            return null;
        }
        const d = JSON.parse(rs.value)['100'];
        if(!d){
            return null;
        }
        return d;
    }

    



    hash(msg){
        return createHash('sha256').update(msg).digest('hex');
    }

    async createNewDID(){
        const rs:any = await this.execute('createDID', '12345678');
        const did = rs.didname;  

        this.execute('registerIdListener', did).then((data)=>{
            console.log("createDID registerIdListener data "+ JSON.stringify(data));
        })

        return did;
    }

    
}