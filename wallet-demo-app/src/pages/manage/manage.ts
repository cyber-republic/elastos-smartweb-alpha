import { Component } from '@angular/core';
import { IonicPage, NavController, NavParams } from 'ionic-angular';
import { File } from '@ionic-native/file';
import { FileChooser } from '@ionic-native/file-chooser';
import { FilePath } from "@ionic-native/file-path";
import { Zip } from '@ionic-native/zip';

import { HomePage } from '../home/home';
import { InfoPage } from '../info/info';
import { AppConfig } from "../../app/app.config";

/**
 * Generated class for the ManagePage page.
 *
 * See https://ionicframework.com/docs/components/#navigation for more info on
 * Ionic pages and navigation.
 */

@IonicPage()
@Component({
  selector: 'page-manage',
  templateUrl: 'manage.html',
})
export class ManagePage {
  public checkIndex = []; // 复选框选中的应用集合
  public isShow = false
  public appList = []; // 应用列表

  constructor(public navCtrl: NavController,
    public navParams: NavParams,
    public file: File,
    public fileChooser: FileChooser,
    public filePath: FilePath,
    public zip: Zip) {
    AppConfig.initAppListData();
    this.appList = AppConfig.getAppListData();
  }

  /**
  *
  * @desc  页面跳转到首页
  */
  goToIndex(index) {
    this.navCtrl.push(HomePage)
  }

  /**
   *
   * @desc  页面跳转到详情
   */
  goInfo(index) {
    this.navCtrl.push(InfoPage)
  }

  /**
   *
   * @desc 列表选中
   */
  checkApp(item) {
    item.checked = !item.checked;
    if (this.checkIndex.indexOf(item) < 0) {
      this.checkIndex.push(item);
    } else {
      this.checkIndex.splice(this.checkIndex.indexOf(item), 1)
    }
    if (this.checkIndex.length > 0) {
      this.isShow = true
    } else {
      this.isShow = false
    }
  }

  /**
   *
   * @desc   删除操作
   */
  doDel() {
    let that = this;
    this.checkIndex.forEach(function (item) {
      let path = that.file.externalRootDirectory + AppConfig.appName + "/";
      let dir = item.url.substr(0, item.url.lastIndexOf("/www/index.html"));

      // remove dir & info
      that.file.removeRecursively(path, dir)
        .then(result => {
          if (result) {
            that.appList.splice(that.appList.indexOf(item), 1);
            AppConfig.saveAppListData(that.appList);
          } else {
            alert("remove this app " + item.name + " failed!");
          }
        }).catch(err => alert(JSON.stringify(err)));
    });
    this.checkIndex = [];
  }

  /**
   *
   * @desc 添加应用
   */
  importFromEpk() {
    let destDir = this.file.externalRootDirectory + AppConfig.appName + "/";

    // choose *.epk
    this.fileChooser.open()
      .then(fileFullUri => {
        // for chinese file name
        let chooseFile = decodeURI(fileFullUri);

        // get file size
        let fileSize = "0MB";
        this.file.resolveLocalFilesystemUrl(fileFullUri)
          .then(fileEntry => {
            fileEntry.getMetadata(
              function (metadata) {
                // fileSize = this.fileTurnSize(metadata.size);
                fileSize = metadata.size >= 1048576 ? (metadata.size / 1048576).toFixed(2) + " MB" : (metadata.size / 1024).toFixed(2) + " KB";
              },
              function (error) {
                alert(error.message);
              }
            );
          }).catch(err => alert(JSON.stringify(err)));

        // get file path
        this.filePath.resolveNativePath(chooseFile)
          .then(fileFullPath => {
            let fileFullName = fileFullPath.substr(fileFullPath.lastIndexOf("/") + 1);
            let fileName = fileFullName.substr(0, fileFullName.lastIndexOf("."));
            let fileType = fileFullPath.substr(fileFullPath.lastIndexOf(".")).toLowerCase();

            // check the file type
            if (fileType != ".epk") {
              alert("please choose epk file formats!");
            } else {
              // unzip *.epk to sdcard
              this.zip.unzip(fileFullPath, destDir)
                .then((unzipResult) => {
                  if (unzipResult === -1) {
                    alert("unzip this file failed!");
                  } else if (unzipResult === 0) {
                    let infoFilePath = destDir + fileName + "/www/";
                    let infoFileFullName = "manifest.json";
                    // check if there exists info file
                    this.file.checkFile(infoFilePath, infoFileFullName)
                      .then(isFileExists => {
                        if (isFileExists) {
                          // read the info file
                          this.file.readAsText(infoFilePath, infoFileFullName)
                            .then(jsonString => {
                              // yyyy.MM.dd format date
                              let currentDate = new Date();
                              let currentMM = currentDate.getMonth() < 9 ? "0" + (currentDate.getMonth() + 1) : (currentDate.getMonth() + 1);
                              let currentDD = currentDate.getDay() < 9 ? "0" + (currentDate.getDay() + 1) : (currentDate.getDay() + 1);
                              // analyse the app info
                              let info = JSON.parse(jsonString);
                              this.appList.push({
                                path: "../" + fileName + "/www/" + info.icons[0].src,
                                name: info.name,
                                url: fileName + '/www/index.html',
                                size: fileSize,
                                date: currentDate.getFullYear() + "." + currentMM + "." + currentDD
                              });
                              // save app list
                              AppConfig.saveAppListData(this.appList);
                            }).catch(err => alert(JSON.stringify(err)));
                        } else {
                          alert("this file is broken!");
                        }
                      }).catch(err => alert(JSON.stringify(err)));
                  }
                }).catch(err => alert(JSON.stringify(err)));
            }
          }).catch(err => alert(JSON.stringify(err)));

      }).catch(err => alert(JSON.stringify(err)));
  }

}
