const char page[] PROGMEM = R"=====(
  <body>
<svg style=" z-index: -100;position:fixed; top:0; left:0; height:100%; width:100%" version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
   width="480px" height="800px" viewBox="0 0 480 800" style="enable-background:new 0 0 480 800;" xml:space="preserve">
<rect x="70.688" y="21.011" style="fill:#666666;" width="340.861" height="758.065"/>
<circle style="fill:red;" cx="240" cy="160.24" r="102.151" id="red_circle"/>
<circle style="fill:orange;" cx="240" cy="400" r="102.151" id="orange_circle"/>
<circle style="fill:green;" cx="240" cy="639.76" r="102.151" id="green_circle"/>
<g>
  <path style="fill:none;stroke:#000000;stroke-width:14;stroke-linecap:round;stroke-linejoin:round;" d="M342.151,160.24
    c0-56.417-45.734-102.151-102.151-102.151c-56.416,0-102.15,45.734-102.15,102.151"/>
</g>
<g>
  <path style="fill:none;stroke:#000000;stroke-width:14;stroke-linecap:round;stroke-linejoin:round;" d="M342.151,400
    c0-56.417-45.734-102.151-102.151-102.151c-56.416,0-102.15,45.734-102.15,102.151"/>
</g>
<g>
  <path style="fill:none;stroke:#000000;stroke-width:14;stroke-linecap:round;stroke-linejoin:round;" d="M342.151,639.76
    c0-56.416-45.734-102.15-102.151-102.15c-56.416,0-102.15,45.734-102.15,102.15"/>
</g>
</svg>
<div style="height: 33%; width: 100%; z-index: -1;" onclick="changeRed();" id="red_area"></div>
<div style="height: 33%; width: 100%; z-index: -1;" onclick="changeOrange();" id="orange_area"></div>
<div style="height: 33%; width: 100%; z-index: -1;" onclick="changeGreen();" id="green_area"></div>
<script type="text/javascript">
  window.onload = function() {
    refresh();
    setInterval(refresh, 3000);
    }
  function refresh(){
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
    console.log("state change")
  if (xhttp.readyState == 4 && xhttp.status == 200) {
    console.log(xhttp.responseText.charAt(1));
    document.getElementById("red_circle").style.fill = (xhttp.responseText.charAt(1) == "1") ? "red" : "black";
    document.getElementById("orange_circle").style.fill = (xhttp.responseText.charAt(2) == "1") ? "orange" : "black";
    document.getElementById("green_circle").style.fill = (xhttp.responseText.charAt(3) == "1") ? "green" : "black";
  }
  };
    xhttp.open("GET", "get",true);
    xhttp.send();
    
    }
function changeRed (){
  var xhttp = new XMLHttpRequest();
  if (document.getElementById("red_circle").style.fill == 'red'){
    xhttp.open("GET", "send?a=A&port=1&state=0",true);
    document.getElementById("red_circle").style.fill = "black";
  }else{
    xhttp.open("GET", "send?a=A&port=1&state=1",true);
    document.getElementById("red_circle").style.fill = "red";
    }
    xhttp.send();
  }
function changeGreen (){
  var xhttp = new XMLHttpRequest();
  if (document.getElementById("green_circle").style.fill == 'green'){
    document.getElementById("green_circle").style.fill = "black";
    xhttp.open("GET", "send?a=A&port=3&state=0",true);
  }else{
    document.getElementById("green_circle").style.fill = "green";
    xhttp.open("GET", "send?a=A&port=3&state=1",true);
    }
    xhttp.send();
  }
function changeOrange (){
  var xhttp = new XMLHttpRequest();
  if (document.getElementById("orange_circle").style.fill == 'orange'){
    document.getElementById("orange_circle").style.fill = "black";
    xhttp.open("GET", "send?a=A&port=2&state=0",true);
  }else{
    document.getElementById("orange_circle").style.fill = "orange";
    xhttp.open("GET", "send?a=A&port=2&state=1",true);
    }
    xhttp.send();
}
  </script>
</body>
)=====";
