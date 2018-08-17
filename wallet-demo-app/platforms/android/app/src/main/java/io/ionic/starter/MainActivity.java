/*
       Licensed to the Apache Software Foundation (ASF) under one
       or more contributor license agreements.  See the NOTICE file
       distributed with this work for additional information
       regarding copyright ownership.  The ASF licenses this file
       to you under the Apache License, Version 2.0 (the
       "License"); you may not use this file except in compliance
       with the License.  You may obtain a copy of the License at

         http://www.apache.org/licenses/LICENSE-2.0

       Unless required by applicable law or agreed to in writing,
       software distributed under the License is distributed on an
       "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
       KIND, either express or implied.  See the License for the
       specific language governing permissions and limitations
       under the License.
 */

package io.ionic.starter;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;

import org.apache.cordova.*;

import cn.jpush.android.api.JPushInterface;
import com.elastos.spvcore.MasterWalletManager;

import ElaJava2JSBridge.Java2JSBridge;

public class MainActivity extends CordovaActivity
{
    static {
        System.loadLibrary("spvsdk");
        System.loadLibrary("idchain");
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("Elastos.Wallet");
        System.loadLibrary("Elastos.DID");
        System.loadLibrary("elastoswallet");
    }

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        // enable Cordova apps to be started in the background
        Bundle extras = getIntent().getExtras();
        if (extras != null && extras.getBoolean("cdvStartInBackground", false)) {
            moveTaskToBack(true);
        }

        // Set by <content src="index.html" /> in config.xml
        loadUrl(launchUrl);

        initJG();
    }

    @Override
    protected void onPause() {
        super.onPause();

        MasterWalletManager walletManager = MyUtil.GetCurrentMasterWalletManager();
        if (walletManager != null) {
            walletManager.SaveConfigs();
        }
    }

    private void initJG(){
        MyUtil.moveConfigFiles2RootPath(this);

        Context applicationContext = getApplicationContext();
        MyUtil.setApplicationContext(applicationContext);

        String udid =  MyUtil.getImei(applicationContext, "");
        if (null != udid) Log.w("xxl-jg","Imei uuid is " + udid);

        String appKey = MyUtil.getAppKey(applicationContext);
        if (null == appKey) appKey = "AppKey异常";
        Log.w("xxl-jg","AppKey " + appKey);

        String packageName =  getPackageName();
        Log.w("xxl-jg","PackageName " + packageName);

        String deviceId = MyUtil.getDeviceId(applicationContext);
        Log.w("xxl-jg","deviceId " + deviceId);
        Java2JSBridge.deviceID = deviceId;

        String versionName =  MyUtil.GetVersion(applicationContext);
        Log.w("xxl-jg","versionName " + versionName);


        String regID=JPushInterface.getRegistrationID(MainActivity.this);
        Log.w("xxl-jg","rid " + regID);
        Java2JSBridge.getRegistrationID = regID;
        //

        JPushInterface.init(applicationContext);
    }

}
