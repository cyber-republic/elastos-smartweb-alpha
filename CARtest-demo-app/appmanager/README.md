## Elastos appmanager  plugin

###  前置条件
用户创建好了一个ionic的工程，将appmanager copy到工程目录下。
目前appmanager暂时只支持android平台

###  安装插件
ionic cordova plugin add D:\project\mytest2\appmanager


### 使用插件
1  在ts 文件前部添加

declare let cordova: any;

2 调用appmannager的start方法
   cordova.plugins.appmanager.StartApp(url + "?timestamp=" + new Date().getTime(), 
	  function (data) { }, 
	  function (error) { });
	  

### 打正式包指令
ionic cordova build --prod

