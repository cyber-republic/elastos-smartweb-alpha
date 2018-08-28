# Elastos_e2e_demo
* [Video guide](https://www.youtube.com/watch?v=8cp_K4TF3ZM): This video showcases how you can build your very own end-to-end demo dapp. Great resource for any developer to quickly get started on writing an elastos dapp.

## Prerequisites
- Install JDK 1.8 and android sdk
- Install ionic and cordova using "npm install -g ionic cordova"
- This build uses cordova version 7.1.1

## How to build the app
- npm install
- mkdir www
- cordova platform add android
- ionic cordova plugin add ElaWallet
- npm run build:epk

## How to run the app
- Import E2E.epk into Trinity
- Click on the app to open it

## Dependent service info
* Ditto server: You first need to run your own ditto server

## Running dependent service locally
* Make sure to install docker and docker-compose first.
* Run **npm run dep:start**
* There will be a new folder named **data** under ./docker
* Set CORS for ditto-server by adding "header('Access-Control-Allow-Origin: *');" to the file  ./data/ditto/config/domains.config.php
* Run **npm run dep:stop && npm run dep:start** to restart instance.

## Connect ditto server with carrier
* Open local ditto box with http://127.0.0.1:8000 if you did not change ditto settings
* Login: admin/111111
* Open E2E app and click **Ditto**
* Click **SCAN QR CODE** to and scan the qr code on page.
* When the address appear, click the *Confirm* button.
* You will need to wait a big longer the first time to connect ditto server due to the carrier node pairing.









