package com.plugin.appmanager;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.util.Log;

import io.ionic.starter.MainActivity;


/**
 * This class echoes a string called from JavaScript.
 */
public class appmanager extends CordovaPlugin {

  public String TAG = "Elastos.appmanager";

  private static CallbackContext mCallbackContext;

  private static final int openwallet = 100;

  @Override
  public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
    mCallbackContext = callbackContext;
    if (action.equals("StartApp")) {
      String message = args.getString(0);
      this.StartApp(message, callbackContext);
      return true;
    } else if(action.equals("SetResult")){

    }
    return false;
  }
  private void SetResult(String message, CallbackContext callbackContext) {
    Log.e("Elastos SetResult", message);
    if (message != null && message.length() > 0) {
      //cordova.getActivity().runOnUiThread(new Runnable() {
      //  public void run() {
      Intent mIntent = new Intent();
      if (message.equalsIgnoreCase("www/index.html")) {
        //mIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
        mIntent.setData(Uri.parse("main://main?action=20&url=" + message));
        //cordova.getActivity().startActivity(mIntent);
      } else if (message.contains("wallet")) {
        //mIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
        mIntent.setData(Uri.parse("wallet://wallet?action=20&url=" + message));
        //cordova.getActivity().startActivity(mIntent);
      } else {
        // mIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        mIntent.setData(Uri.parse("elastos://elastos?action=21&url=" + message));
        //cordova.getActivity().startActivity(mIntent);
      }
      //mIntent.setPackage("org.elastos.desktop");
      cordova.getActivity().setResult(openwallet, mIntent);
      cordova.getActivity().finish();
      //   }
      //});
      callbackContext.success(message);
    } else {
      callbackContext.error("Expected one non-empty string argument.");
    }
  }
  private void StartApp(String message, CallbackContext callbackContext) {
    Log.e("Elastos StartApp", message);
    if (message != null && message.length() > 0) {
      //cordova.getActivity().runOnUiThread(new Runnable() {
      //  public void run() {

          Intent mIntent = new Intent();
          if (message.equalsIgnoreCase("www/index.html")) {
            //mIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
            mIntent.setData(Uri.parse("main://main?action=20&url=" + message));
            //cordova.getActivity().startActivity(mIntent);
          } else if (message.contains("wallet")) {
            //mIntent.addFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
            mIntent.setData(Uri.parse("wallet://wallet?action=20&url=" + message));
            //cordova.getActivity().startActivity(mIntent);
          } else {
            // mIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            mIntent.setData(Uri.parse("elastos://elastos?action=21&url=" + message));
            //cordova.getActivity().startActivity(mIntent);
          }
          mIntent.setPackage("org.elastos.desktop");
          if(message.contains("backurl=")) {
            cordova.startActivityForResult(this, mIntent, openwallet);
          } else {
            cordova.getActivity().startActivity(mIntent);
          }
     //   }
      //});
      callbackContext.success(message);
    } else {
      callbackContext.error("Expected one non-empty string argument.");
    }
  }

  @Override
  public void onNewIntent(Intent intent) {
    //Intent tempintent = getIntent();
    Log.e(TAG, "intent: " + intent);
    if (null != intent) {
      Uri data = intent.getData();
      if (null != data) {
        String scheme = data.getScheme();
        String host = data.getHost();
        if (scheme.equals("wallet") && host.equals("wallet")) {
            String path = data.toString();
            int urlindex = path.indexOf("url=");
            String url = path.substring(urlindex + 4);
            String message = "handle.OnPlugInMessage('" + url + "')";
            PluginResult dataResult = new PluginResult(PluginResult.Status.OK, message);
            dataResult.setKeepCallback(true);// 非常重要
            mCallbackContext.sendPluginResult(dataResult);
        }
      }
    }
  }
  @Override
  public void onActivityResult(int requestCode, int resultCode, Intent data) {

    if (requestCode == openwallet && mCallbackContext != null) {

      if (resultCode == Activity.RESULT_OK) {

        Uri uri = data.getData();

        if (uri != null) {

          Log.w(TAG, uri.toString());
          String path = data.toString();
          int urlindex = path.indexOf("url=");
          String url = path.substring(urlindex + 4);
          mCallbackContext.success(url);

        } else {

          mCallbackContext.error("File uri was null");

        }

      } else if (resultCode == Activity.RESULT_CANCELED) {

        // TODO NO_RESULT or error callback?
        PluginResult pluginResult = new PluginResult(PluginResult.Status.NO_RESULT);
        mCallbackContext.sendPluginResult(pluginResult);

      } else {

        mCallbackContext.error(resultCode);
      }
    }
  }
}

