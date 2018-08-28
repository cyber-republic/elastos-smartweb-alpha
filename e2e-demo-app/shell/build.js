console.log('Elastos epk build Start ' + process.argv[2] + '.epk');

var fs = require('fs');

if (process.argv.length > 2) {
	if(fs.existsSync(process.argv[2] + '.epk')){
		 fs.unlinkSync(process.argv[2] + '.epk');
		 console.log('Elastos epk build delete  ' + process.argv[2] + '.epk');
	}
	

	var archiver = require('archiver');

	var output = fs.createWriteStream(process.argv[2] + '.epk');
	var archive = archiver('zip');
	 
	 archive.on('error', function(err){
		 throw err;
	 });
	 
	 archive.pipe(output);
	 //archive.directory('platforms/android/app/src/main/assets/www/', process.argv[2] + '/www');
	 archive.directory('www/', process.argv[2] + '/www');
	 archive.directory('platforms/android/platform_www/', process.argv[2] + '/www');
	 if (!fs.existsSync('www/manifest.json'))  {
		 archive.file('src/manifest.json', { name: process.argv[2] + '/www/manifest.json'});
	 }
	 archive.finalize();
}
 
 console.log('Elastos epk build Finished');