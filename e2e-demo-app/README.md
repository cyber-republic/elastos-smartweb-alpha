# Elastos_e2e_demo

## Get Trinity app
* You can download and install "trinity.apk" file onto your android device

## Get E2E demo dapp
* You can import "E2E.epk" from Trinity browser app

## Run dapp in Trinity
* Open Trinity app
* click the meme icon on the top left.
* click **Import from Local file** on the top.
* locate the download **E2E.epk** file and confirm.
* you will find the **E2E DEMO** app in the app list.
* click the close icon on the top right.
* click **E2E DEMO** app icon to start the DApp.

## How to build E2E Demo epk file yourself
* make sure install node enviroment first.
* git clone or download this repo to local.
* run the following commands.
```
cd Elastos_e2e_demo
npm install ionic cordova -g
npm install
npm run build:epk
```
* you will find the **E2E.epk** file under the current folder.

## Dependent service info
* ditto server: You first need to run your own ditto server

## Running dependent service locally
* make sure to install docker and docker-compose first.
* run **npm run dep:start**
* there will be a new folder named **data** under ./docker
* follow the [./docker/readme.md](./docker/readme.md) to config docker instance.
* run **npm run dep:stop && npm run dep:start** to restart instance.

## Connect ditto server with carrier
* open local ditto box with http://127.0.0.1:8000 if you did not change ditto settings.
* open E2E app and click **Ditto**
* click **SCAN QR CODE** to and scan the qr code on page.
* when the address appear, click the *Confirm* button.
* you will need to wait a big longer the first time to connect ditto server due to the carrier node pairing.

### Help improve this documentation by providing your pull request with more elaborate README.md









