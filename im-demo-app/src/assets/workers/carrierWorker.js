
var carrier = null;

self.onmessage = function(event) {
    console.log("=== worker on message " + event.data.name);
    if (event.data.name === "start") {
        self.startCarrier();
    } else if (event.data.name === 'stop') {
        self.stopCarrier();
    }
};

self.startCarrier = function() {
  carrier = new Carrier();
  carrier.Start('/data/data/org.apache.cordova/files');
  self.postMessage({name: "started"});
};

self.stopCarrier = function() {
    carrier.Stop();
    carrier = null;
    self.postMessage({name: 'stoped'});
}
