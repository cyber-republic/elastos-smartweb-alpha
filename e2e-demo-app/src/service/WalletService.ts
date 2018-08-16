import {Base} from './Base';

declare var cordova: any;

/***
 * wallet jni 交互
 *
 * WalletManager.ts -> Wallet.js -> wallet.java -> WalletManager.java
 */
let _instance = null;
export class WalletService extends Base {

  static get(isCordova){
    if(!_instance){
        _instance = new WalletService();
        _instance.setIsNative(isCordova);
    }

    return _instance;
  } 

  private wallet = null;
  private isNative = false;

  public static COINTYPE_ELA = 0;
  public static COINTYPE_ID = 1;
  public static LIMITGAP = 500;
  public static FEEPERKb = 500;
  public static PAGECOUNT = 100;

  setIsNative(flag){
    if(flag){
      this.isNative = flag;
      this.wallet = cordova.plugins.Wallet;
    }

    console.log('init Wallet Service');
  }

  /**通过android log 打印数据*/
  print(text: string, Fun): void {
    this.wallet.print(text, Fun, this.errorFun);
  }

  start() {
    this.wallet.start([], () => {
    }, this.errorFun);
  }

  stop() {
    this.wallet.stop([], () => {
    }, this.errorFun);
  }


  //--------------------------------------------------------------------------------子钱包操作


  /***
   * 创建子钱包
   * @param {String} chainID
   * @param {string} payPassword
   * @param {boolean} singleAddress
   * @param {long} feePerKb
   */
  createSubWallet(chainID:string,payPassword: string, singleAddress: boolean, feePerKb: number, Fun) {
      this.wallet.createSubWallet([chainID,payPassword, singleAddress,feePerKb], Fun, this.errorFun);
  }

  /***
   * 恢复子钱包
   * @param {string} chainID
   * @param {string} payPassword
   * @param {boolean} singleAddress
   * @param {int} limitGap
   * @param {long} limitGap
   */
  recoverSubWallet(chainID:string,payPassword: string, singleAddress: boolean,limitGap: number,feePerKb: number, Fun) {
      this.wallet.recoverSubWallet([chainID,payPassword,singleAddress,limitGap,feePerKb], Fun, this.errorFun);
  }

  /***
   * 获取子钱包公钥
   * @param Fun
   */
  getPublicKey(Fun) {
    this.wallet.getPublicKey([], Fun, this.errorFun);
  }


  //----------------------------------------------------------------------- 主钱包操作


  /**
   * 创建主钱包
   * @param {string} masterWalletId
   * @param {string} language
   * @param Fun
   */
  createMasterWallet(masterWalletId: string, mnemonic:string, phrasePassword:string, payPassword:string,language:string, Fun) {
    this.wallet.createMasterWallet([masterWalletId,mnemonic,phrasePassword,payPassword,language], Fun, this.errorFun);
  }
  /**
   * @param {string} masterWalletId
   * @param {string} keystoreContent
   * @param {string} backupPassword
   * @param {string} payPassword
   * @param {string} phrasePassword
   * @param Fun
   */
  importWalletWithKeystore(masterWalletId:string,keystoreContent: string, backupPassword: string, payPassword: string,phrasePassword:string, Fun) {
    this.wallet.importWalletWithKeystore([masterWalletId,keystoreContent, backupPassword, payPassword,phrasePassword], Fun, this.errorFun);
  }

    /**
   * @param {string} masterWalletId
   * @param {string} mnemonic
   * @param {string} phrasePassword
   * @param {string} payPassword
   * @param {string} language
   * @param Fun
   */
  importWalletWithMnemonic(masterWalletId:string,mnemonic: string, phrasePassword: string, payPassword,language:string, Fun) {
    this.wallet.createMasterWallet([masterWalletId,mnemonic,phrasePassword, payPassword,language], Fun, this.errorFun);
  }

  /**
   * @param {string} backupPassWord
   * @param {string} payPassword
   * @param {string} keystorePath
   * @param Fun
   */
  exportWalletWithKeystore(backupPassWord:string, payPassword: string,Fun) {
    this.wallet.exportWalletWithKeystore([backupPassWord,payPassword], Fun, this.errorFun);
  }
  /**
   * @param {string} backupPassWord
   * @param Fun
   */
  exportWalletWithMnemonic(backupPassWord: string, Fun) {
    this.wallet.exportWalletWithMnemonic([backupPassWord], Fun, this.errorFun);
  }

  getBalance(chainId:string,Fun) {
    if(!this.isNative){
      return Fun({
        balance : 100000000000
      })
    }
    this.wallet.getBalance([chainId], Fun, this.errorFun);
  }

  createAddress(chainId:string,Fun) {
    this.wallet.createAddress([chainId], Fun, this.errorFun);
  }

  getAllAddress(chainId:string,start:number,Fun) {
    if(!this.isNative){
      return Fun(JSON.stringify({
        Addresses : [
          'aaaaaaaaaaaaaaaaaa',
          'bbbbbbbbbbbbbbbbbb'
        ]
      }));
    }
    this.wallet.getAllAddress([chainId,start, WalletService.PAGECOUNT], Fun, this.errorFun);
  }

  getBalanceWithAddress(chainId:string,address, Fun) {
    if(!this.isNative){
      return Fun({
        balance: 100
      })
    }
    this.wallet.getBalanceWithAddress([chainId,address], Fun, this.errorFun);
  }

  generateMultiSignTransaction(chainId:string,fromAddress, toAddress, amount, fee, payPassword, memo, Fun) {
    this.wallet.generateMultiSignTransaction([chainId,fromAddress, toAddress, amount, fee, payPassword, memo], Fun, this.errorFun);
  }

  createMultiSignAddress(chainId:string,multiPublicKeyJson, totalSignNum, requiredSignNum, Fun) {
    this.wallet.createMultiSignAddress([multiPublicKeyJson, totalSignNum, requiredSignNum], Fun, this.errorFun);
  }

  getAllTransaction(chainId:string,start, addressOrTxId, Fun) {
    this.wallet.getAllTransaction([chainId,start, WalletService.PAGECOUNT, addressOrTxId], Fun, this.errorFun);
  }

  registerWalletListener(chainId:string,Fun) {
    this.wallet.registerWalletListener([chainId], Fun, this.errorFun);
  }
  registerIdListener(chainId:string,Fun) {
    this.wallet.registerIdListener([chainId], Fun, this.errorFun);
  }

  sign(chainId:string,message, payPassword, Fun) {
    this.wallet.sign([chainId,message, payPassword], Fun, this.errorFun);
  }

  checkSign(chainId:string,address, message, signature, Fun) {
    this.wallet.checkSign([chainId,address, message, signature], Fun, this.errorFun);
  }
  /**
   * @param {string} masterWalletId
   */
  destroyWallet(masterWalletId:string,Fun) {
    this.wallet.destroyWallet([masterWalletId], Fun, this.errorFun);
  }


  getFee(Fun) {
    Fun(0.01);
  }

  deriveIdAndKeyForPurpose(purpose:number,index:number,payPassword:string,Fun){
    this.wallet.deriveIdAndKeyForPurpose([purpose,index,payPassword], Fun, this.errorFun);
  }

  getAllMasterWallets(Fun){
    if(!this.isNative){
      return Fun({
        walletid: 'Test'
      });
    }
    this.wallet.getAllMasterWallets([], Fun, this.errorFun);
  }

  getBalanceInfo(chainId:string,Fun){
    this.wallet.getBalanceInfo([chainId], Fun, this.errorFun);
  }

  isAddressValid(address:string,Fun){
      this.wallet.isAddressValid([address], Fun, this.errorFun);
  }

  generateMnemonic(language:string,Fun){
    if(!this.isNative){
      return Fun({
        mnemonic: 'aaa bbb ccc ddd eee fff ggg hhh iii jjj kkk lll'
      });
    }
    this.wallet.generateMnemonic([language],Fun,this.errorFun);
  }

  saveConfigs(Fun){
    this.wallet.saveConfigs([],Fun,this.errorFun);
  }

  getWalletId(Fun){
    this.wallet.getWalletId([],Fun,this.errorFun);
  }

  getAllChainIds(Fun){
    this.wallet.getAllChainIds([],Fun,this.errorFun);
  }


  getSupportedChains(Fun){
    this.wallet.getSupportedChains([],Fun,this.errorFun);
  }

  getAllSubWallets(Fun){
    if(!this.isNative){
      return Fun({
        'AAA': 'AAA',
        'BBB': 'BBB',
        'IdChain': 'IdChain'
      });
    }
    this.wallet.getAllSubWallets([],Fun,this.errorFun);
  }

  changePassword(oldPassword:string , newPassword:string ,Fun){
     this.wallet.getAllSubWallets([oldPassword,newPassword],Fun,this.errorFun);
  }

  createTransaction(chainId:string,fromAddress:string , toAddress:string ,amount:number,fee:number, memo:string, remark: string,Fun){
    if(!this.isNative){
      return Fun({
        
      })
    }
    this.wallet.createTransaction([chainId,fromAddress,toAddress,amount,fee,memo, remark],Fun,this.errorFun);
  }

  calculateTransactionFee(chainId:string,rawTransaction:string,feePerKb:number,Fun){
    this.wallet.calculateTransactionFee([chainId,rawTransaction,feePerKb],Fun,this.errorFun);
  }

  sendRawTransaction(chainId:string,transactionJson:string ,fee:number, payPassword:string,Fun){
    this.wallet.sendRawTransaction([chainId,transactionJson,fee,payPassword],Fun,this.errorFun);
  }

  createDID(password:string,Fun){
    if(!this.isNative){
      return Fun({
        didname : 'test_did_name'
      })
    }
    this.wallet.createDID([password],Fun,this.errorFun);
  }

  getDIDList(Fun){
    this.wallet.getDIDList([],Fun,this.errorFun);
  }

  destoryDID(did:string,Fun){
    this.wallet.destoryDID([did],Fun,this.errorFun);
  }

  didSetValue(did:string,keyPath:string,value:string,Fun){
    this.wallet.didSetValue([did,keyPath,value],Fun,this.errorFun);
  }

  didGetValue(did:string,keyPath:string,Fun){
    this.wallet.didGetValue([did,keyPath],Fun,this.errorFun);
  }

  didGetHistoryValue(did:string,keyPath:string,Fun){
    this.wallet.didGetValue([did,keyPath],Fun,this.errorFun);
  }

  didGetAllKeys(did:string,start:number,count:number,Fun){
    this.wallet.didGetAllKeys([did,start,count],Fun,this.errorFun);
  }

  didSign(did:string,message:string,password:string,Fun){
    this.wallet.didSign([did,message,password],Fun,this.errorFun);
  }

  didCheckSign(did:string,message:string,signature:string,Fun){
    this.wallet.didCheckSign([did,message,signature],Fun,this.errorFun);
  }

  didGetPublicKey(did:string,Fun){
    this.wallet.didGetPublicKey([did],Fun,this.errorFun);
  }

  createIdTransaction(chainId:string,fromAddress:string,payloadJson:string,programJson:string,memo:string,remark:string,Fun){
    this.wallet.createIdTransaction([chainId,fromAddress,payloadJson,programJson,memo,remark],Fun,this.errorFun);
  }  

  createDepositTransaction(chainId:string,fromAddress:string,toAddress:string,amount:number
    ,sidechainAccounts:string,sidechainAmounts:string,sidechainIndex:string,memo:string,remark:string,Fun){
    this.wallet.createDepositTransaction([chainId,fromAddress,toAddress,amount,sidechainAccounts,sidechainAmounts,sidechainIndex,memo,remark],Fun,this.errorFun);
  }

  createWithdrawTransaction(chainId:string,fromAddress:string,toAddress:string,amount:number
    ,mainchainAccounts:string,mainchainAmounts:string,mainchainIndexs:string,memo:string,remark:string,Fun){
    this.wallet.createWithdrawTransaction([chainId,fromAddress,toAddress,amount,mainchainAccounts,mainchainAmounts,mainchainIndexs,memo,remark],Fun,this.errorFun);
  }

  getGenesisAddress(chainId:string,Fun){
    if(chainId === 'ELA'){
      return Fun('XKUh4GLhFJiqAMTF6HyWQrV9pK9HcGUdfJ');
    }
    if(chainId === 'IdChain'){
      return Fun('1111111111111111111114oLvT2');
    }
    this.wallet.getGenesisAddress([chainId],Fun,this.errorFun);
  }

  didGenerateProgram(did:string,message:string,password:string,Fun){
      this.wallet.didGenerateProgram([did,message,password],Fun,this.errorFun);
  }

  getAllCreatedSubWallets(Fun){
    this.wallet.getAllCreatedSubWallets([],Fun,this.errorFun);
  }

  errorFun(error) {
    alert("错误信息：" + error);
    //this.native.toast(error);
  }


}


