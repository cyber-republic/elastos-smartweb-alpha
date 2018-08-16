var fs = require('fs');
var archiver = require('archiver');

var pwd = __dirname+'/../';

var C = {
  target : pwd + 'E2E.epk',
  zip_pkg : pwd + 'EPK',
  pkg : pwd+'EPK/E2E/www',
  src : pwd+'www'
};

var F = {
  removeFolder(path){
    var files = [];
    if(fs.existsSync(path)){
      files = fs.readdirSync(path);
      files.forEach(function(file,index){
        var curPath = path + "/" + file;
        if(fs.statSync(curPath).isDirectory()) { // recurse
          F.removeFolder(curPath);
        } 
        else { // delete file
          fs.unlinkSync(curPath);
        }
      });
      fs.rmdirSync(path);
    }
  },
  removeTarget(){
    try{
      F.unlinkSync(C.target);
    }catch(e){}
  },

  removeBuildFiles(){
    try{
      F.removeFolder(C.pkg+'/assets');
      F.removeFolder(C.pkg+'/build');
    }catch(e){
      console.log(e);
    }
  },

  copyFolder(folder){
    var src = C.src + '/' + folder;
    var files = [];
    if(fs.existsSync(src)){
      files = fs.readdirSync(src);
      files.forEach(function(file, index){
        var curPath = src + "/" + file;
        if(fs.statSync(curPath).isDirectory()) { 
      
          fs.mkdirSync(C.pkg +'/' + folder+'/'+file);
          F.copyFolder(folder+'/'+file);
        } 
        else { 
          fs.createReadStream(curPath).pipe(fs.createWriteStream(C.pkg+'/'+folder+'/'+file));
        }
      });
    }
  },
  copyToTarget(){
    fs.mkdirSync(C.pkg+'/assets');
    fs.mkdirSync(C.pkg+'/build');
    F.copyFolder('assets');
    F.copyFolder('build');
  },

  zipFolder(srcFolder, zipFilePath, callback){
    var output = fs.createWriteStream(zipFilePath);
    var zipArchive = archiver('zip');

    output.on('close', function(){
      callback(true);
    });
    zipArchive.pipe(output);
    zipArchive.bulk([
      { 
        cwd: srcFolder, 
        src: ['**/*'], 
        expand: true 
      }
    ]);
    zipArchive.finalize(function(err, bytes) {
      if(err){
        callback(false, err);
      }
    });
  },

  zipTarget(){
    F.zipFolder(C.zip_pkg, C.target, function(f, err){
      if(!f){
        throw err;
      }

      console.log('build finish');
    })
  }
};

F.removeTarget();
F.removeBuildFiles();
F.copyToTarget();
F.zipTarget();


