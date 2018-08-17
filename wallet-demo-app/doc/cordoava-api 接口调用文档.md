
# elastos 钱包 native jni 调用接口文档

## 一、手机硬件相关

#### > 接口示例



```
ES5标准:

 /***
 * options 接口参数
 * SuccessFun 成功回调
 * ErrorFun 失败回调
 */
 function funName(options,SuccessFun,ErrorFun)

/***
 * data 响应的实体
 */
 function SuccessFun(data)

/***
 * errCode 错误码
 * errMsg  错误信息
 */
 function SuccessFun(errCode,errMsg)
 
 
 
 

---

ES6标准:

function funName(options){
    return Promise.reject(options)
    .then()
    .catch();
}

调用：

funName(options).then((data)=>{
    //成功回调
}).catch((errCode,errMsg)=>{
    //失败回调
});




```

#### > 错误码


```
{
    2001 : 参数错误
    2002 : 权限错误
    2003 : 网络错误
    ...
}


```




#### 1. 设备管理


```

/**
* 1.获取设备信息
*/
getDeviceInfo()

return 
{
    platform:Android/IOS    //平台
    model:Apple Iphone 6s   //机型设备信息
    version:6.0             //接口版本
    uuid：15165165          //设备通用标示
    ua: webkit              //webkit 内核标示
    
}


---

/**
* 2.获取网络信息
*/
getNetWorkInfo()

return 
{
    ConnectionType:unknown，ethernet，wifi，2g，3g，4g，cellular，none    //网络连接类型
}

---


```




#### 2. 调用二维码（Zxing）



```

/**
* 1.调用二维码扫描  可让用户直接在图库选择图片
*/
scan()

return 
{
    codeData：webwbsgs      //扫描的结果
    
}



```

#### 3. 调用本地文件

```
/**
* 1.打开文件管理器 选择文件
* 最好可以适配<input type="file">
*/
openFile()

return 
{
    file：文件      //返回的文件，或byte数组,或json数据，
    path: /mnt/xxx  //文件的路径
    fileType:jpg    //文件的类型
    其他：字符集 目前应该不需要
    
}


---



/**
* 2.导出文件，让用户保存到本地
*/
exportFile(options)

options 
{
    json:{xxxx}    //导出的私钥文件字符串
    name:keystore  //文件名字
}

return 
{
   //
}


```







#### 4. 调用剪贴板


```
/**
* 1.复制到剪贴板
*/
CopyClipboard(options)

options 
{
    text:xxxx    //内容
}

return 
{
   //
}

---

/**
* 2.读取剪贴板
*/
PasteClipboard()


return 
{
   text: xxxx     //内容
}



```

#### 5. 跨域配置
```
/**
* 1.配置跨域
*/

crossDomain(options)

options 
{
    domain:xxxx        //域名
    status:ture/false  //开关
}

return 
{
   status: return/false //开关
}


//如果无法在js层做到跨域的请求访问，可能会需要根据kyc三方接口提供jni调用

/**
* 2. kyc 验证   如果无法跨域，启用该接口
*/

kyc(options)

options 
{
    //kyc 的参数
}

return 
{
   // 返回三个固定参数
}



```



#### 6. 调用指纹、手势锁  v2

```
/**
* 1.注册用户识别
*/

encrypt(options)

options 
{
   type: gesture/fingerprint/Pin  识别类型 手势/指纹/密码
}

return 
{
   //
}


/**
* 2.验证用户识别
*/
decrypt(options)
options 
{
   type: gesture/fingerprint/Pin 识别类型 手势/指纹/密码
}

return 
{
   //
}


```




### 二、SPV 

1. 目前五个接口








### 可能出现的问题：

 - 打包
 - jni回调
 - 跨域访问 ~
 - 性能与兼容