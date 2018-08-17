import {Injectable} from '@angular/core';
import {randomBytes, createHash} from 'crypto-browserify';
import secp256k1 from 'secp256k1';
import {Util} from './Util';
import {Config} from "./Config";
import  elliptic   from 'elliptic';
/***
 * id链相关
 */
@Injectable()
export class IDManager {
  constructor() {

  }

  public static test(): void {
    const msg = randomBytes(32);
    // const msg = this.hash("我是哈哈哈");
    let privKey;
    do {
      privKey = randomBytes(32)
    } while (!secp256k1.privateKeyVerify(privKey));

    const pubKey = secp256k1.publicKeyCreate(privKey);

    const sigObj = this.sign(msg, privKey);

    console.log("privKey:" + privKey);
    console.log("pubKey:" + pubKey);
    console.log("sign:" + sigObj);
    console.log("verify:" + this.verify(msg, sigObj.signature, pubKey));


  }


  public static sign(msg, privKey): any {
    let EC = elliptic.ec;
    let ec = new EC('p256'); // 获取secp256r1曲线
    let message =  this.hash(msg);
    let key = ec.keyFromPrivate(privKey, 'hex'); // 导入私钥
    let sign = key.sign(message).toDER('hex'); // 生成签名
    return sign;
  }

  public static sign1(msg, privKey): any {
    let EC = elliptic.ec;
    let ec = new EC('p256'); // 获取secp256r1曲线
    let message =  this.hash(msg);
    //let key = ec.keyFromPrivate(privKey, 'hex'); // 导入私钥
    let sign = ec.sign(message,privKey,16).toDER('hex'); // 生成签名
    //console.log("=====ssssss====="+sign);
    return sign;
  }

  public static verify(msg, signature, pubKey): boolean {
    return secp256k1.verify(msg, signature, pubKey)
  }

  public static hash(msg) {
    return createHash('sha256').update(msg).digest('hex');
  }

  //接口数字签名
  public static getInfoSign(obj){
    let keys = IDManager.getObjKeys(obj,"asc");
    let msg="";
    for(let index in keys){
         msg=msg+obj[keys[index]];
    }
    return this.sign1(msg,Config.getSmsSecretKey());
  }
 //checksum计算规则
  public static getCheckSum(obj,sort){
    let keys = IDManager.getObjKeys(obj,sort);
    let msg="";
    for(let index in keys){
         msg=msg+obj[keys[index]];
    }
    return  this.hash(msg);
    }

    public static getObjKeys(obj,sort=""){
      let arr = [];
      for(let key in obj){
         if(!Util.isNull(obj[key])){
            arr.push(key);
          }
      }

      if(sort === "asc"){
        IDManager.asc(arr);
      }else if(sort === "des"){
        IDManager.des(arr);
      }
      return arr;
    }

    /**
     * 从小到大
     */
    public static asc(keys){
      keys.sort(function (s1, s2) {
        let x1 = s1.toUpperCase();
        let x2 = s2.toUpperCase();
        if (x1 < x2) {
            return -1;
        }
        if (x1 > x2) {
            return 1;
        }
        return 0;
       });
    }

       /**
     * 从大到小
     */
    public static des(keys){
      keys.sort(function (s1, s2) {
        let x1 = s1.toUpperCase();
        let x2 = s2.toUpperCase();
        if (x1 > x2) {
            return -1;
        }
        if (x1 < x2) {
            return 1;
        }
        return 0;
       });
    }
    /**
     * 获得公钥
     * @param privKey
     */
    public static getPublicKey(privKey){
           return "111111";
    }

    public static getPriKey(){
      return "sssss"
    }
}





