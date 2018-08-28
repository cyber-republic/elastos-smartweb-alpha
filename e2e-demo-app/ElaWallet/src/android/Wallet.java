package ElaWallet;

import android.util.JsonReader;

import com.elastos.spvcore.IMasterWallet;
import com.elastos.spvcore.ISubWallet;
import com.elastos.spvcore.IMainchainSubWallet;
import com.elastos.spvcore.IIdChainSubWallet;
import com.elastos.spvcore.ISubWalletCallback;
import com.elastos.spvcore.MasterWalletManager;
import com.elastos.spvcore.IdManagerFactory;
import com.elastos.spvcore.IDidManager;
import com.elastos.spvcore.IDid;
import com.elastos.spvcore.IIdManagerCallback;
import com.elastos.spvcore.WalletException;
import com.elastos.wallet.util.LogUtil;

import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaWebView;
import org.apache.cordova.PluginResult;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.Iterator;
import android.util.Log;

import io.ionic.starter.MyUtil;

/**
 * wallet webview jni
 */
public class Wallet extends CordovaPlugin {
    private static final String TAG = "Wallet.JNI";
    private IMasterWallet mCurrentMasterWallet;
    private MasterWalletManager mWalletManager;
    private ArrayList<IMasterWallet> mMasterWalletList;
    private IDidManager mDidManager = null;
    private Map<String, ISubWallet> mSubWalletMap = new HashMap<String, ISubWallet>();
    private String mRootPath = null;

    private final String ERRORCODE = "ERRORCODE";
    private final String ERRORCODE_NODATA = "NODATA";

    @Override
    public void initialize(CordovaInterface cordova, CordovaWebView webView) {
        super.initialize(cordova, webView);

        mRootPath = MyUtil.getRootPath();
        Log.d("JS-Wallet", "initialize=============mRootPath="+mRootPath);
        mWalletManager = new MasterWalletManager(mRootPath);
        MyUtil.SetCurrentMasterWalletManager(mWalletManager);
        mMasterWalletList = mWalletManager.GetAllMasterWallets();
        if (mMasterWalletList != null) {
            mCurrentMasterWallet = mMasterWalletList.get(0);
            if (mCurrentMasterWallet != null) {
                // mDidManager = IdManagerFactory.CreateIdManager(mCurrentMasterWallet, mRootPath);
            }
        }
        else {
            mMasterWalletList = new ArrayList<IMasterWallet>();
        }
    }

    private void initDidManager() {
      Log.d("JS-Wallet", "initDidManager=========1====mRootPath="+mRootPath);
        if (mDidManager == null && mCurrentMasterWallet != null) {
            Log.d("JS-Wallet", "initDidManager=========2====mRootPath="+mRootPath);
            // mDidManager = IdManagerFactory.CreateIdManager(mCurrentMasterWallet, mRootPath);
        }
    }

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) {
        Log.i("JS-Wallet", "execute=============action="+action);
        try {
          switch (action) {
              case "coolMethod":
                  String message = args.getString(0);
                  this.coolMethod(message, callbackContext);
                  return true;
              case "print":
                  this.print(args.getString(0), callbackContext);
                  return true;
              case "createSubWallet":
                  this.createSubWallet(args, callbackContext);
                  return true;
              case "getPublicKey":
                  this.getPublicKey(args, callbackContext);
                  return true;
              case "createMasterWallet":
                  this.createMasterWallet(args, callbackContext);
                  return true;
              case "recoverSubWallet":
                  this.recoverSubWallet(args, callbackContext);
                  return true;
              case "importWalletWithKeystore":
                  this.importWalletWithKeystore(args, callbackContext);
                  return true;
              case "getAllCreatedSubWallets":
                  this.getAllCreatedSubWallets(args, callbackContext);
                  return true;
              case "importWalletWithMnemonic":
                  this.importWalletWithMnemonic(args, callbackContext);
                  return true;
              case "exportWalletWithKeystore":
                  this.exportWalletWithKeystore(args, callbackContext);
                  return true;
              case "exportWalletWithMnemonic":
                  this.exportWalletWithMnemonic(args, callbackContext);
                  return true;
              case "getBalanceInfo":
                  this.getBalanceInfo(args, callbackContext);
                  return true;
              case "getBalance":
                  this.getBalance(args, callbackContext);
                  return true;
              case "createAddress":
                  this.createAddress(args, callbackContext);
                  return true;
              case "getAllAddress":
                  this.getAllAddress(args, callbackContext);
                  return true;
              case "getBalanceWithAddress":
                  this.getBalanceWithAddress(args, callbackContext);
                  return true;
              case "createTransaction":
                  this.createTransaction(args, callbackContext);
                  return true;
              case "createMultiSignTransaction":
                  this.createMultiSignTransaction(args, callbackContext);
                  return true;
              case "createMultiSignAddress":
                  this.createMultiSignAddress(args, callbackContext);
                  return true;
              case "getAllTransaction":
                  this.getAllTransaction(args, callbackContext);
                  return true;
              case "sign":
                  this.sign(args, callbackContext);
                  return true;
              case "checkSign":
                  this.checkSign(args, callbackContext);
                  return true;
              case "registerWalletListener":
                  this.registerWalletListener(args, callbackContext);
                  return true;
              case "getAllMasterWallets":
                  this.getAllMasterWallets(args, callbackContext);
                  return true;
              case "getAllSubWallets":
                  this.getAllSubWallets(args, callbackContext);
                  return true;
              case "getAllChainIds":
                  this.getAllChainIds(args, callbackContext);
                  return true;
              case "getWalletId":
                  this.getWalletId(args, callbackContext);
                  return true;
              case "saveConfigs":
                  this.saveConfigs(args, callbackContext);
                  return true;
              case "isAddressValid":
                  this.isAddressValid(args, callbackContext);
                  return true;
              case "generateMnemonic":
                  this.generateMnemonic(args, callbackContext);
                  return true;
              case "destroyWallet":
                  this.destroyWallet(args, callbackContext);
                  return true;
              case "getSupportedChains":
                  this.getSupportedChains(args, callbackContext);
                  return true;
              case "changePassword":
                  this.changePassword(args, callbackContext);
                  return true;
              case "resetAddressCache":
                  this.resetAddressCache(args, callbackContext);
                  return true;
              case "sendRawTransaction":
                  this.sendRawTransaction(args, callbackContext);
                  return true;
              case "calculateTransactionFee":
                  this.calculateTransactionFee(args, callbackContext);
                  return true;
              case "createIdTransaction":
                  this.createIdTransaction(args, callbackContext);
                  return true;
              case "createDepositTransaction":
                  this.createDepositTransaction(args, callbackContext);
                  return true;

              //did
              case "createDID":
                  this.createDID(args, callbackContext);
                  return true;
              case "didGenerateProgram":
                  this.didGenerateProgram(args, callbackContext);
                  return true;
              case "getDIDList":
                  this.getDIDList(args, callbackContext);
                  return true;
              case "destoryDID":
                  this.destoryDID(args, callbackContext);
                  return true;
              case "didSetValue":
                  this.didSetValue(args, callbackContext);
                  return true;
              case "didGetValue":
                  this.didGetValue(args, callbackContext);
                  return true;
              case "didGetHistoryValue":
                  this.didGetHistoryValue(args, callbackContext);
                  return true;
              case "didGetAllKeys":
                  this.didGetAllKeys(args, callbackContext);
                  return true;
              case "didSign":
                  this.didSign(args, callbackContext);
                  return true;
              case "didCheckSign":
                  this.didCheckSign(args, callbackContext);
                  return true;
              case "didGetPublicKey":
                  this.didGetPublicKey(args, callbackContext);
                  return true;
              case "registerIdListener":
                  this.registerIdListener(args, callbackContext);
                  return true;
              case "createWithdrawTransaction":
                  this.createWithdrawTransaction(args, callbackContext);
                  return true;
              case "getGenesisAddress":
                  this.getGenesisAddress(args, callbackContext);
                  return true;
          }
        } catch (JSONException e) {
            e.printStackTrace();
            callbackContext.error("json parse error");
            return false;
        }

        return false;
    }


    //CreateSubWallet(String chainID, String payPassword, boolean singleAddress, long feePerKb)
    public void createSubWallet(JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            Log.i("JS-Wallet", "createSubWallet==============1, id="+args.getString(0));
            ISubWallet subWallet = mCurrentMasterWallet.CreateSubWallet(args.getString(0), args.getString(1), args.getBoolean(2), args.getLong(3));
            if (subWallet != null) {
                mSubWalletMap.put(args.getString(0), subWallet);
                callbackContext.success(args.getString(0));
                Log.i("JS-Wallet", "createSubWallet==============2, subWallet============["+subWallet+"]");
            }
            else {
                callbackContext.error("CreateSubWallet failed.");
            }
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    //RecoverSubWallet(String chainID, String payPassword, boolean singleAddress, int limitGap, long feePerKb)
    public void recoverSubWallet(JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            ISubWallet subWallet = mCurrentMasterWallet.RecoverSubWallet(args.getString(0), args.getString(1), args.getBoolean(2), args.getInt(3), args.getLong(4));
            if (subWallet != null) {
                mSubWalletMap.put(args.getString(0), subWallet);
                callbackContext.success(parseOneParam(args.getString(0), subWallet));
            }
            else {
                callbackContext.error("RecoverSubWallet failed.");
            }
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    public void getAllMasterWallets(JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            mMasterWalletList = mWalletManager.GetAllMasterWallets();
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
            return;
        }

        if (mMasterWalletList != null && mMasterWalletList.size() > 0) {
            //TODO: Now, the first masterWallet is the default.
            mCurrentMasterWallet = mMasterWalletList.get(0);
            initDidManager();
            callbackContext.success(parseOneParam("walletid",mCurrentMasterWallet.GetId()));
        }
        else {
            // callbackContext.error("Don't have masterWallet, please create a new one.");
            callbackContext.success(parseOneParam("walletid",""));
        }
    }

    //CreateSubWallet(String chainID, String payPassword, boolean singleAddress, long feePerKb)
    public void getAllSubWallets(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mCurrentMasterWallet != null) {
            JSONObject jsonObject = new JSONObject();

            mSubWalletMap.clear();
            ArrayList<ISubWallet> list = mCurrentMasterWallet.GetAllSubWallets();
            Log.i("JS-Wallet", "getAllSubWallets==============1, list.size="+list.size());
            for (int i = 0; i < list.size(); i++) {
                ISubWallet subWallet = list.get(i);
                if (subWallet != null) {
                    mSubWalletMap.put(subWallet.GetChainId(), subWallet);
                    jsonObject.put(subWallet.GetChainId(), subWallet.GetChainId());
                }
            }

            callbackContext.success(jsonObject);
        }
        else {
            // callbackContext.error("Don't have any subWallet, please create a new one.");
            callbackContext.success(parseOneParam(ERRORCODE, ERRORCODE_NODATA));
        }
    }

    public void getWalletId(JSONArray args, CallbackContext callbackContext) throws JSONException {
        String walletID = mCurrentMasterWallet.GetId();
        if (walletID != null) {
            callbackContext.success(parseOneParam("walletID", walletID));
        }
        else {
            callbackContext.error("Get masterWallet's id failed.");
        }
    }

    public void saveConfigs(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mWalletManager != null) {
            mWalletManager.SaveConfigs();
        }
        callbackContext.success();
    }

    // GenerateMnemonic(String language)
    public void generateMnemonic(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mWalletManager == null) {
            callbackContext.success(parseOneParam(ERRORCODE, "The WalletManager is null"));
            return;
        }

        try {
            String mnemonic = mWalletManager.GenerateMnemonic(args.getString(0));
            callbackContext.success(parseOneParam("mnemonic", mnemonic));
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
            return;
        }
    }

    public void isAddressValid(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mCurrentMasterWallet == null) {
            callbackContext.success(parseOneParam(ERRORCODE, "The masterWallet is null"));
        }
        boolean valid = mCurrentMasterWallet.IsAddressValid(args.getString(0));
        callbackContext.success(parseOneParam("valid", valid));
    }

    public void getPublicKey(JSONArray args, CallbackContext callbackContext) throws JSONException {
        String publickey = mCurrentMasterWallet.GetPublicKey();
        if (publickey != null) {
            callbackContext.success(parseOneParam("publickey", publickey));
        }
        else {
            callbackContext.error("getPublicKey failed.");
        }
    }

    //IMasterWallet CreateMasterWallet(String masterWalletId, String mnemonic, String phrasePassword, String payPassword, String language)
    public void createMasterWallet(JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            mCurrentMasterWallet = mWalletManager.CreateMasterWallet(args.getString(0), args.getString(1), args.getString(2)
                    , args.getString(3), args.getString(4));
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
            return;
        }

        if (mCurrentMasterWallet != null) {
            mMasterWalletList.add(mCurrentMasterWallet);
            initDidManager();
            callbackContext.success();
        }
        else {
            callbackContext.error("CreateMasterWallet failed.");
        }
    }

    //DestroyWallet(String masterWalletId)
    public void destroyWallet(JSONArray args, CallbackContext callbackContext) throws JSONException {
        Log.i("JS-Wallet", "destroyWallet==================1, walletid="+args.getString(0));
        try {
            mWalletManager.DestroyWallet(args.getString(0));
            callbackContext.success();
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
            return;
        }
    }

    //ImportWalletWithKeystore(String masterWalletId, String keystoreContent, String backupPassWord ,String payPassWord, String phrasePassword)
    public void importWalletWithKeystore(JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            mCurrentMasterWallet = mWalletManager.ImportWalletWithKeystore(args.getString(0), args.getString(1), args.getString(2)
                      , args.getString(3), args.getString(4));
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
            return;
        }

        if (mCurrentMasterWallet != null) {
            mMasterWalletList.add(mCurrentMasterWallet);

            mSubWalletMap.clear();
            ArrayList<ISubWallet> list = mCurrentMasterWallet.GetAllSubWallets();
            Log.i("JS-Wallet", "importWalletWithKeystore==============1, subwallet.list.size="+list.size());
            for (int i = 0; i < list.size(); i++) {
                ISubWallet subWallet = list.get(i);
                if (subWallet != null) {
                    mSubWalletMap.put(subWallet.GetChainId(), subWallet);
                }
            }

            initDidManager();
            callbackContext.success();
        }
        else {
            callbackContext.error("ImportWalletWithKeystore failed.");
        }
    }

    public void getAllCreatedSubWallets(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mCurrentMasterWallet != null) {
            Set<String> keys = mSubWalletMap.keySet();
            Iterator<String> iter = keys.iterator();

            JSONObject jsonObject = new JSONObject();
            while(iter.hasNext()){
                String chainID = iter.next();
                Log.i("JS-Wallet", "getAllCreatedSubWallets=========================chainID=["+chainID+"]");
                jsonObject.put(chainID, chainID);
            }

            callbackContext.success(jsonObject);
            return;
        }

        callbackContext.success(parseOneParam("createdSubWallets", null));
    }

    //ImportWalletWithMnemonic(String masterWalletId, String mnemonic, String phrasePassword ,String payPassWord, String language)
    public void importWalletWithMnemonic(JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            Log.i("JS-Wallet", "importWalletWithMnemonic======================================1");
            mCurrentMasterWallet = mWalletManager.ImportWalletWithMnemonic(args.getString(0), args.getString(1), args.getString(2)
                    , args.getString(3), args.getString(4));
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
            return;
        }

        Log.i("JS-Wallet", "importWalletWithMnemonic======================================2");
        if (mCurrentMasterWallet != null) {
            Log.i("JS-Wallet", "importWalletWithMnemonic======================================3");
            mMasterWalletList.add(mCurrentMasterWallet);

            mSubWalletMap.clear();
            ArrayList<ISubWallet> list = mCurrentMasterWallet.GetAllSubWallets();
            Log.i("JS-Wallet", "importWalletWithMnemonic==============1, subwallet.list.size="+list.size());
            for (int i = 0; i < list.size(); i++) {
                ISubWallet subWallet = list.get(i);
                if (subWallet != null) {
                    mSubWalletMap.put(subWallet.GetChainId(), subWallet);
                }
            }

            initDidManager();
            callbackContext.success();
        }
        else {
            callbackContext.error("ImportWalletWithMnemonic failed.");
        }
    }

    //ExportWalletWithKeystore(IMasterWallet masterWallet, String backupPassWord, String payPassword, String keystorePath)
    public void exportWalletWithKeystore(JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            String keystoreContent = mWalletManager.ExportWalletWithKeystore(mCurrentMasterWallet, args.getString(0), args.getString(1));
            callbackContext.success(parseOneParam("keystoreContent", keystoreContent));
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
            return;
        }
    }

    //ExportWalletWithMnemonic(IMasterWallet masterWallet,String backupPassWord)
    public void exportWalletWithMnemonic(JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            String mnemonic = mWalletManager.ExportWalletWithMnemonic(mCurrentMasterWallet, args.getString(0));
            if (mnemonic != null) {
                callbackContext.success(parseOneParam("mnemonic", mnemonic));
            }
            else {
                callbackContext.error("ExportWalletWithMnemonic failed.");
            }
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
            return;
        }
    }

    // String CreateTransaction(String fromAddress, String toAddress, long amount, long fee, String memo)
    public void createTransaction(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        String transactionId = null;
        try {
            transactionId = subWallet.CreateTransaction(args.getString(1), args.getString(2), args.getLong(3),
                                    args.getLong(4), args.getString(5), args.getString(6));
            if (transactionId != null) {
                callbackContext.success(parseOneParam("transactionId", transactionId));
            }
            else {
                callbackContext.error("CreateTransaction failed.");
            }
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    public void createMultiSignAddress(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        String address = subWallet.CreateMultiSignAddress(args.getString(1), args.getInt(2), args.getInt(3));
        if (address != null) {
            callbackContext.success(parseOneParam("address", address));
        }
        else {
            callbackContext.error("CreateMultiSignAddress failed.");
        }
    }

    public void createMultiSignTransaction(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        try {
            String result = subWallet.CreateMultiSignTransaction(args.getString(1), args.getString(2), args.getLong(3),
                        args.getLong(4), args.getString(5));

            if (result != null) {
                callbackContext.success(parseOneParam("result", result));
            }
            else {
                callbackContext.error("createMultiSignTransaction failed.");
            }
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    public void getAllTransaction(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        Log.i("JS-Wallet", "getAllTransaction======id="+args.getString(0)+", a1="+args.getInt(1)+", a2="+args.getInt(2)+", a3="+args.getString(3));
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        String allTransaction = subWallet.GetAllTransaction(args.getInt(1), args.getInt(2), args.getString(3));
        callbackContext.success(parseOneParam("allTransaction", allTransaction));
    }

    public void registerWalletListener(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        Log.i("JS-Wallet", "registerWalletListener==================1");
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        subWallet.AddCallback(new ISubWalletCallback() {
            @Override
            public void OnTransactionStatusChanged(String txId, String status, String desc, int confirms) {
                JSONObject jsonObject = new JSONObject();
                Log.i("JS-Wallet", "registerWalletListener==================2");
                try {
                    jsonObject.put("txId", txId);
                    jsonObject.put("status", status);
                    jsonObject.put("desc", desc);
                    jsonObject.put("confirms", confirms);
                }
                catch (JSONException e) {
                    e.printStackTrace();;
                }

                PluginResult pluginResult = new PluginResult(PluginResult.Status.OK,jsonObject);
                pluginResult.setKeepCallback(true);
                callbackContext.sendPluginResult(pluginResult);
            }
        });
    }

    public void getBalanceInfo(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        callbackContext.success(parseOneParam("balance", subWallet.GetBalanceInfo()));
    }

    public void getBalance(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        Log.i("JS-Wallet", "getBalance==============1, id="+args.getString(0));
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        callbackContext.success(parseOneParam("balance", subWallet.GetBalance()));
    }

    public void createAddress(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        String address = subWallet.CreateAddress();
        if (address != null) {
            callbackContext.success(parseOneParam("address", address));
        }
        else {
            callbackContext.error("CreateAddress failed.");
        }
    }

    public void getAllAddress(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        callbackContext.success(subWallet.GetAllAddress(args.getInt(1), args.getInt(2)));
    }

    public void getBalanceWithAddress(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        callbackContext.success(parseOneParam("balance", subWallet.GetBalanceWithAddress(args.getString(1))));
    }

    public void sign(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        String result = subWallet.Sign(args.getString(1), args.getString(2));
        if (result != null) {
            callbackContext.success(parseOneParam("signData", result));
        }
        else {
            callbackContext.error("Sign failed.");
        }
    }

    //CheckSign(String address, String message, String signature)
    public void checkSign(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        boolean status = subWallet.CheckSign(args.getString(1), args.getString(2), args.getString(3));
        callbackContext.success(parseOneParam("status", status));
    }

    //String SendRawTransaction(String transactionJson, long fee, String payPassword)
    public void sendRawTransaction(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        Log.i("JS-Wallet", "sendRawTransaction==============1, id="+args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        try {
            String json = subWallet.SendRawTransaction(args.getString(1), args.getLong(2), args.getString(3));
            callbackContext.success(parseOneParam("json", json));
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    //long CalculateTransactionFee(String rawTransaction, uint64_t feePerKb)
    public void calculateTransactionFee(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        ISubWallet subWallet = mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        long fee = 0;
        try {
            fee = subWallet.CalculateTransactionFee(args.getString(1), args.getLong(2));
            callbackContext.success(parseOneParam("fee", fee));
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    //String CreateIdTransaction(fromAddress, toAddress, long amount, payloadJson, programJson, long fee, memo, remark)
    public void createIdTransaction(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        Log.i("JS-Wallet", "createIdTransaction==================1, id="+args.getString(0));
        if (!IMasterWallet.CHAINID.ID.equals(args.getString(0))) {
            callbackContext.success(parseOneParam(ERRORCODE, "The chainID must be IdChain."));
            return;
        }
        ISubWallet baseWallet = mSubWalletMap.get(args.getString(0));
        IIdChainSubWallet subWallet;
        if(baseWallet instanceof IIdChainSubWallet){
            subWallet = (IIdChainSubWallet)baseWallet;
            Log.i("JS-Wallet", "createIdTransaction instanceof IIdChainSubWallet 1, id="+args.getString(0));
        }else{
            Log.i("JS-Wallet", "createIdTransaction not instanceof IIdChainSubWallet 1, id="+args.getString(0));
            return ;
        }
       // IIdChainSubWallet subWallet = (IIdChainSubWallet)mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        String json = null;
        try {
            json = subWallet.CreateIdTransaction(args.getString(1), args.getString(2), args.getLong(3),
                     args.getString(4), args.getString(5), args.getLong(6), args.getString(7), args.getString(8));
            if (json != null) {
                callbackContext.success(parseOneParam("json", json));
            }
            else {
                callbackContext.error("CreateIdTransaction failed.");
            }
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    public void createDepositTransaction(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        Log.i("JS-Wallet", "createDepositTransaction==================1, id="+args.getString(0));
        if (!IMasterWallet.CHAINID.MAIN.equals(args.getString(0))) {
            callbackContext.success(parseOneParam(ERRORCODE, "The chainID must be ELA."));
            return;
        }

        IMainchainSubWallet subWallet = (IMainchainSubWallet)mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        String json = null;
        try {
            json = subWallet.CreateDepositTransaction(args.getString(1), args.getString(2), args.getLong(3)
                    , args.getString(4), args.getString(5), args.getString(6)
                    , args.getLong(7), args.getString(8), args.getString(9));
            if (json != null) {
                callbackContext.success(parseOneParam("json", json));
            }
            else {
                callbackContext.error("CreateDepositTransaction failed.");
            }
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    public void getAllChainIds(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mSubWalletMap.size() < 1) {
            callbackContext.success(parseOneParam("chainId", null));
            return;
        }
        JSONObject jsonObject = new JSONObject();
        for (String key : mSubWalletMap.keySet()) {
            jsonObject.put(key, key);
        }
        callbackContext.success(jsonObject);
    }

    public void getSupportedChains(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mCurrentMasterWallet != null) {
            String[] supportedChains = mCurrentMasterWallet.GetSupportedChains();
            JSONObject jsonObject = new JSONObject();
            if (supportedChains != null) {
                for (int i = 0; i < supportedChains.length; i++) {
                    jsonObject.put(supportedChains[i], supportedChains[i]);
                }
            }

            callbackContext.success(jsonObject);
            return;
        }

        callbackContext.success(parseOneParam("supportedChains", null));
    }

    public void changePassword(JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            if (mCurrentMasterWallet != null) {
                mCurrentMasterWallet.ChangePassword(args.getString(0), args.getString(1));
                callbackContext.success();
                return;
            }

            callbackContext.success(parseOneParam("changePassword", null));
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    public void resetAddressCache(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mCurrentMasterWallet != null) {
            mCurrentMasterWallet.ResetAddressCache(args.getString(0));
            callbackContext.success();
            return;
        }

        callbackContext.success(parseOneParam("changePassword", null));
    }

    private JSONObject parseOneParam(String key, Object value) throws JSONException {
        JSONObject jsonObject = new JSONObject();
        jsonObject.put(key, value);
        return jsonObject;
    }

    private void coolMethod(String message, CallbackContext callbackContext) {
        if (message != null && message.length() > 0) {
            callbackContext.success(message);
        } else {
            callbackContext.error("Expected one non-empty string argument.");
        }
    }

    public void print(String text, CallbackContext callbackContext) throws JSONException {
        if (text == null) {
            callbackContext.error("text not can null");
        } else {
            LogUtil.i(TAG, text);
            callbackContext.success(parseOneParam("text", text));
        }
    }


    //IDIDManager
    //CreateDID(String password)
    public void createDID(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            IDid did = mDidManager.CreateDID(args.getString(0));
            callbackContext.success(parseOneParam("didname", did.GetDIDName()));
            return;
        }

        callbackContext.success(parseOneParam("didname", null));
    }

    //String GetDIDList()
    public void getDIDList(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            String list = mDidManager.GetDIDList();
            callbackContext.success(parseOneParam("list", list));
            return;
        }

        callbackContext.success(parseOneParam("list", null));
    }

    //void DestoryDID(String didName)
    public void destoryDID(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            mDidManager.DestoryDID(args.getString(0));
            callbackContext.success();
            return;
        }

        callbackContext.error("DidManager is null");
    }

    //IDID
    //SetValue(String keyPath, /*const nlohmann::json*/String valueJson)
    public void didSetValue(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            IDid did = mDidManager.GetDID(args.getString(0));
            if (did != null) {
                did.SetValue(args.getString(1), args.getString(2));
                callbackContext.success();
                return;
            }
        }

        callbackContext.error("didSetValue error.");
    }

    //String GetValue(String path)
    public void didGetValue(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            IDid did = mDidManager.GetDID(args.getString(0));
            if (did != null) {
                String value = did.GetValue(args.getString(1));
                callbackContext.success(parseOneParam("value", value));
                return;
            }
        }

        callbackContext.error("didGetValue error.");
    }

    //String GetHistoryValue(String keyPath)
    public void didGetHistoryValue(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            IDid did = mDidManager.GetDID(args.getString(0));
            if (did != null) {
                String value = did.GetHistoryValue(args.getString(1));
                callbackContext.success(parseOneParam("value", value));
                return;
            }
        }

        callbackContext.error("didGetHistoryValue error.");
    }

    //String GetAllKeys(int start, int count)
    public void didGetAllKeys(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            IDid did = mDidManager.GetDID(args.getString(0));
            if (did != null) {
                String value = did.GetAllKeys(args.getInt(1), args.getInt(2));
                callbackContext.success(parseOneParam("value", value));
                return;
            }
        }

        callbackContext.error("didGetAllKeys error.");
    }

    //String Sign(String message, String password)
    public void didSign(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            IDid did = mDidManager.GetDID(args.getString(0));
            if (did != null) {
                try {
                    String value = did.Sign(args.getString(1), args.getString(2));
                    callbackContext.success(parseOneParam("value", value));
                }
                catch (WalletException e) {
                    e.printStackTrace();
                    callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
                }
                return;
            }
        }

        callbackContext.error("didSign error.");
    }

    //String Sign(String message, String password)
    public void didGenerateProgram(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            IDid did = mDidManager.GetDID(args.getString(0));
            if (did != null) {
                String value = did.GenerateProgram(args.getString(1), args.getString(2));
                callbackContext.success(parseOneParam("value", value));
                return;
            }
        }

        callbackContext.error("didGenerateProgram error.");
    }

    //String CheckSign(String message, String signature)
    public void didCheckSign(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            IDid did = mDidManager.GetDID(args.getString(0));
            if (did != null) {
                try {
                    String value = did.CheckSign(args.getString(1), args.getString(2));
                    callbackContext.success(parseOneParam("value", value));
                }
                catch (WalletException e) {
                    e.printStackTrace();
                    callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
                }
                return;
            }
        }

        callbackContext.error("didSign error.");
    }

    public void didGetPublicKey(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager != null) {
            IDid did = mDidManager.GetDID(args.getString(0));
            if (did != null) {
                String value = did.GetPublicKey();
                callbackContext.success(parseOneParam("value", value));
                return;
            }
        }

        callbackContext.error("didGetPublicKey error.");
    }

    public void registerIdListener(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (mDidManager == null) {
            callbackContext.error("registerIdListener error.");
            return;
        }

        mDidManager.RegisterCallback(args.getString(0), new IIdManagerCallback() {
            @Override
            public void OnIdStatusChanged(String id, String path, /*const nlohmann::json*/ String value) {
                JSONObject jsonObject = new JSONObject();
                Log.i("JS-Wallet", "registerIdListener==================2");
                try {
                    jsonObject.put("id", id);
                    jsonObject.put("path", path);
                    jsonObject.put("value", value);
                }
                catch (JSONException e) {
                    e.printStackTrace();;
                }

                PluginResult pluginResult = new PluginResult(PluginResult.Status.OK,jsonObject);
                pluginResult.setKeepCallback(true);
                callbackContext.sendPluginResult(pluginResult);
            }
        });
    }

    // SidechainSubWallet

    // String CreateWithdrawTransaction(String fromAddress, String toAddress, long amount, String mainchainAccounts,
    //             String mainchainAmounts, String mainchainIndexs, long fee, String memo, String remark)
    public void createWithdrawTransaction(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        Log.i("JS-Wallet", "createWithdrawTransaction==================1, id="+args.getString(0));
        if (!IMasterWallet.CHAINID.ID.equals(args.getString(0))) {
            callbackContext.success(parseOneParam(ERRORCODE, "The chainID must be IdChain."));
            return;
        }

        IIdChainSubWallet subWallet = (IIdChainSubWallet)mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        String json = null;
        try {
            json = subWallet.CreateWithdrawTransaction(args.getString(1), args.getString(2), args.getLong(3),
                     args.getString(4), args.getString(5), args.getString(6)
                     , args.getLong(7), args.getString(8), args.getString(9));
            if (json != null) {
                callbackContext.success(parseOneParam("json", json));
            }
            else {
                callbackContext.error("CreateWithdrawTransaction failed.");
            }
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    public void getGenesisAddress(JSONArray args, CallbackContext callbackContext) throws JSONException {
        //The first parameter is [chainID]
        Log.i("JS-Wallet", "getGenesisAddress==================1, id="+args.getString(0));
        if (!IMasterWallet.CHAINID.ID.equals(args.getString(0))) {
            callbackContext.success(parseOneParam(ERRORCODE, "The chainID must be IdChain."));
            return;
        }

        IIdChainSubWallet subWallet = (IIdChainSubWallet)mSubWalletMap.get(args.getString(0));
        if (subWallet == null) {
            callbackContext.error("Don't have the subWallet: ["+args.getString(0)+"], please check.");
            return;
        }

        String address = null;
        try {
            address = subWallet.GetGenesisAddress();
            if (address != null) {
                callbackContext.success(parseOneParam("address", address));
            }
            else {
                callbackContext.error("GetGenesisAddress failed.");
            }
        }
        catch (WalletException e) {
            e.printStackTrace();
            callbackContext.success(parseOneParam(ERRORCODE, e.GetErrorInfo()));
        }
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }
}
