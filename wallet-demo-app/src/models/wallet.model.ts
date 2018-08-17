export class WalletModel {

  public version: string;
  public name: string = '';
  public payPassword: string = '';
  public backupPassword: string = '';
  public pubKey: string = '';
  public mnemonic: string = '';
  public singleAddress: boolean = false;
  public addressList: any = [];
  public lastAddress: any = '';
  public balance: number = 0;

  constructor() {
    this.version = '1.0.0';

  }






}
