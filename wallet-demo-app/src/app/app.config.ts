// import {File} from '@ionic-native/file';
// import { SQLite, SQLiteObject } from '@ionic-native/sqlite';

export class AppConfig {

  /*
  app info
   */
  public static appName = "elastos";

  private static storageKeyAppList = AppConfig.appName + "_appList";

  private static currentDate = new Date();

  private static currentDateYYYYMMDD = AppConfig.currentDate.getFullYear()  + "."
    + (AppConfig.currentDate.getMonth() < 9 ? "0" + (AppConfig.currentDate.getMonth() + 1) : (AppConfig.currentDate.getMonth() + 1)) + "."
    + (AppConfig.currentDate.getDay() < 9 ? "0" + (AppConfig.currentDate.getDay() + 1) : (AppConfig.currentDate.getDay() + 1));

  private static initAppList = [
    {
      path: "../wallet/www/assets/imgs/logo.png",
      name: "Wallet",
      url: "wallet/www/index.html",
      size: "1 MB",
      date: AppConfig.currentDateYYYYMMDD
    }, {
      path: "../todo/www/assets/imgs/logo.png",
      name: "ToDO",
      url: "todo/www/index.html",
      size: "2 MB",
      date: AppConfig.currentDateYYYYMMDD
    }, {
      path: "../CarTest/www/assets/imgs/logo.png",
      name: "CarTest",
      url: "CarTest/www/index.html",
      size: "666 KB",
      date: AppConfig.currentDateYYYYMMDD
    }, {
      path: "../guess/www/assets/imgs/logo.png",
      name: "Guess",
      url: "guess/www/index.html",
      size: "500 KB",
      date: AppConfig.currentDateYYYYMMDD
    }
  ];

  public static initAppListData() {
    if(null == window.localStorage.getItem(AppConfig.storageKeyAppList)) {
      AppConfig.saveAppListData(AppConfig.initAppList);
    }
  }

  public static getAppListData() {
    return JSON.parse(window.localStorage.getItem(AppConfig.storageKeyAppList));
  }

  public static saveAppListData(appList) {
    window.localStorage.setItem(AppConfig.storageKeyAppList, JSON.stringify(appList));
  }

  // /*
  // db info
  //  */
  // private static sqlite = new SQLite();
  //
  // private static dbName = AppConfig.appName + ".db";
  //
  // private static dbLocation = "default";
  //
  // private static initDB() {
  //   AppConfig.sqlite.create({
  //     name: AppConfig.dbName,
  //     location: AppConfig.dbLocation
  //   }).then((db: SQLiteObject) => {
  //     db.executeSql("CREATE TABLE IF NOT EXISTS appList(id INT, appInfo VARCHAR(320));");
  //   }).catch(err => alert(JSON.stringify(err)));
  // }

}
