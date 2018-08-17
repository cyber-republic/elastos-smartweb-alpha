package ElaJava2JSBridge;


import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;

/**
 * Created by xxl
 */

public class Java2JSBridge extends CordovaPlugin {

    private static CallbackContext mCallbackContext;
    private static Java2JSBridgeInterface java2JSBridgeInterface;
    public static String deviceID = "";
    public static String getRegistrationID= "";

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (action.equals("callJSInit")) {
            mCallbackContext = callbackContext;    //拿到回调对象并保存
            return true;
        } else if (action.equals("getResult")){
            java2JSBridgeInterface.getJSEvalResult(args.toString());
        }  else if (action.equals("getDeviceID")){
            callbackContext.success(deviceID);
            return true;
        }else if (action.equals("getRegistrationID")){
            callbackContext.success(getRegistrationID);
            return true;
        }
        return true;
    }

    public static void callJS(String message,Java2JSBridgeInterface java2JSBridgeInterfaceArg) {
        if (mCallbackContext != null) {
            java2JSBridgeInterface = java2JSBridgeInterfaceArg;
            PluginResult dataResult = new PluginResult(PluginResult.Status.OK, message);
            dataResult.setKeepCallback(true);// 非常重要
            mCallbackContext.sendPluginResult(dataResult);
        }
    }
}
