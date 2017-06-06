/*<?

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

file_get_contents('http://vestlicht.lemio.nl/send?0=A&1=1&2=1', false, $context);
sleep(50);
file_get_contents('http://vestlicht.lemio.nl/send?0=A&1=2&2=1', false, $context);
sleep(4);
file_get_contents('http://vestlicht.lemio.nl/send?0=A&1=3&2=1', false, $context);
echo ("pikeurtje");
?>*/
