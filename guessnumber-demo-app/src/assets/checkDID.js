function check_DID(publicKey, Did, message, sign)
{
    let CDIDInspector = require("libElastos.DIDInspector.so", "CDIDInspector")
    let didInspector = new CDIDInspector()

    let Result=function() {
      this.io="CallerAllocOutput"
      this.type="Boolean"
    }
    matched = new Result()

    didInspector.CheckDID(publicKey,Did, matched)
    if(matched.data) {
		didInspector.CheckSign(publicKey, message, sign, matched)
		if(matched.data) {
			return true;
		}
	}
    retur false;
}