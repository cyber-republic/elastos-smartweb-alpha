## Set CORS for ditto-server
* open **./data/ditto/config/domains.config.php**
* add following lines in bottom
```
header('Access-Control-Allow-Origin: *');
```

## Set CORS for ipfs
* open **./data/ipfs/config**
* add following lines behind **HTTPHeaders**
```
"Access-Control-Allow-Credentials": ["true"],
"Access-Control-Allow-Origin": ["*"],
```