
package com.elastos.spvcore;


public interface IIdManagerCallback {
    public void OnIdStatusChanged(String id, String path, /*const nlohmann::json*/ String value);
}
