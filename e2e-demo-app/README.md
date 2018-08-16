# Elastos_e2e_demo

## Get Trinity app
* You can download and install "pkg/trinity.apk" file onto your android device

## Get E2E demo dapp
* You can import "pkg/E2E.epk" from Trinity browser app

## Run dapp in Trinity
* Open Trinity app
* Click the meme icon on the top left.
* Click **Import from Local file** on the top.
* Locate the download **E2E.epk** file and confirm.
* You will find the **E2E DEMO** app in the app list.
* Click the close icon on the top right.
* Click **E2E DEMO** app icon to start the DApp.

## How to build E2E Demo epk file yourself
* Make sure install node enviroment first.
* Git clone or download this repo to local.
* Run the following commands.
```
cd Elastos_e2e_demo
npm install ionic cordova -g
npm install
npm run build:epk
```
* You will find the **E2E.epk** file under the current folder.

## Dependent service info
* Ditto server: You first need to run your own ditto server

## Running dependent service locally
* Make sure to install docker and docker-compose first.
* Run **npm run dep:start**
* There will be a new folder named **data** under ./docker
* Follow the [./docker/readme.md](./docker/readme.md) to config docker instance.
* Run **npm run dep:stop && npm run dep:start** to restart instance.

## Connect ditto server with carrier
* Open local ditto box with http://127.0.0.1:8000 if you did not change ditto settings.
* Open E2E app and click **Ditto**
* Click **SCAN QR CODE** to and scan the qr code on page.
* When the address appear, click the *Confirm* button.
* You will need to wait a big longer the first time to connect ditto server due to the carrier node pairing.

### Help improve this documentation by providing your pull request with more elaborate README.md









