## Set CORS for ditto-server
* open **./data/ditto/config/domains.config.php**
* add following lines in bottom if not present
```
header('Access-Control-Allow-Origin: *');
```