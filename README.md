Vestlicht
=====
# Endpoints

## 'send' 
server.endpoint.com/send?a=A&port=1&state=1
Changes one specific relay's state, this state is also saved on the hardware
|GET argument|function|
|---|---|
|a     | deprecated|
|port  | the number of the port (0-3)|
|state | the state of the relay (on=1,off=0)|

## 'get'

server.endpoint.com/get
Will return the values in this format [XXXX] where the X is (1=on) or (0=off)

## php example to create sequences of light (pikeurtijd)

```php
<?php
$opts = array(
  'http'=>array(
    'method'=>"GET",
    'header'=>"Accept-language: en\r\n" .
              "Cookie: foo=bar\r\n".
	      "User-Agent: Mozilla/5.0 (X11; Linux i686) AppleWebKit/535.19 (KHTML, like Gecko) Ubuntu/12.04 Chromium/18.0.1025.168 Chrome/18.0.1025.168 Safari/535.19\r\n"
  )
);

$context = stream_context_create($opts);

// Open the file using the HTTP headers set above

file_get_contents('http://server.endpoint.com/send?0=A&1=1&2=1', false, $context);
sleep(54);
file_get_contents('http://server.endpoint.com/send?0=A&1=2&2=1', false, $context);
sleep(4);
file_get_contents('http://server.endpoint.com/send?0=A&1=3&2=1', false, $context);
echo ("pikeurtje");
?>
```
