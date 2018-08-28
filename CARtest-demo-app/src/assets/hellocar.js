function require_test(path)
{
    //let path = document.getElementById("path_id").value;
	//alert(path);
    let CTest = require(path, "CTest")
    let test = new CTest()

    test.TestInt32(3245);

    test.TestInt64(372036);

    test.TestByte(56);

    test.TestFloat(363762.76);

    test.TestDouble(10246440);

    test.TestChar32('h');

    test.TestString('hello elastos.');

    test.TestBoolean(1);

    let emuid = function() {
      this.io="Input"
      this.type="EMuid"
      this.data= new function() {
          this.mData1=10;
          this.mData2=20;
          this.mData3=30;
          this.mData4=[
            6,
            43,
            12,
            15,
            32,
            12,
            34,
            66
          ]
      }
    }
    
    let _emuid = new emuid();
    alert('io:'+_emuid.io + ' type: ' + _emuid.type + ' data: ' + _emuid.data.mData1)
    test.TestEMuid(_emuid);

    let Result=function() {
      this.io="CallerAllocOutput"
      this.type="String"
    }
    let result2 = new Result()
    test.TestStringOut(result2);
    alert(result2.data);
}