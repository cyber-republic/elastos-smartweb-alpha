## Elastos Wallet DApp

##### Installing ionic|cordova
> npm install -g ionic cordova
##### Install dependencies
> npm install
##### Install Android Build Tools
> Download SDK tools from https://developer.android.com/studio/#command-tools 
> Unzip and place the contents somewhere like your home directory. Maybe under ~/android-sdk 
> After unzipping, your directory structure should look like ~/android-sdk/tools
> cd ~/android-sdk/tools/bin
> ./sdkmanager --update
> ./sdkmanager "build-tools;28.0.2" "ndk-bundle"
> ./sdkmanager --licenses
> Set the following in your path. Eg. in your ~/.bash_profile
> export ANDROID_SDK_ROOT=/Users/kpwoods/android-sdk
> export PATH=$PATH:$ANDROID_SDK_ROOT/tools

### Project Structure

- src | webpage code
    - pages | website page
    - providers/WalletManager.ts | cordova plugin call
- www | packaged webpage code
- platforms | platform
    - android | Android project
        - assets | packaged website project
        - jniLibs | store so dynamic library
        - com.elastos.spvcore.WalletManager | java->c++ jni call
        - ElaWallet.Wallet | java-js jni call
        - io.ionic.starter.MainActivity | Mount the webview program entry
- plungin-src | Wallet plugin source code, automatically added to the main project by command
    - plugin.xml | configuration file
    - www | js code plugin js interface
    - src | java code plugin java interface
- plugins | cordova plugin
    - ElaWallet | Wallet Plugin
       
        - android is the same as anroid under platforms, automatically packaged into the project
        -
### c++ layer
> See https://github.com/elastos/Elastos.ELA.SPV.Cpp/tree/dev


### Basic commands
* Delete ElaJava2JSBridge plugin: `ionic cordova plugin remove ElaJava2JSBridge`
* Add ElaJava2JSBridge plugin: `cd plungin-src && ionic cordova plugin add ElaJava2JSBridge`

* Remove wallet plugin: `ionic cordova plugin remove ElaWallet`
* Add wallet plugin: `cd plungin-src && ionic cordova plugin add ElaWallet`
* Build for android with wallet: `cd .. && ionic cordova build android`
* One Liner for everything: `Ionic cordova plugin remove ElaJava2JSBridge && cd plungin-src && ionic cordova plugin add ElaJava2JSBridge && cd .. && ionic cordova plugin remove ElaWallet && cd plungin-src && ionic cordova plugin add ElaWallet && cd .. && ionic cordova run android - Device --prod
`

### NDK usage version
* android-ndk-r16b

### Playing the official package instruction
> ionic cordova build android --release --prod