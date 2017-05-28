
var mySocket = null

window.onload = function() {
	mySocket = new WebSocket("ws://127.0.0.1:9002");
	mySocket.onmessage = function(event) {
		var msg = JSON.parse(event.data);
		console.log(event.data);
	}
	$("button").on("click",function(event) {
		console.log("button clicked");
		var msg = {
        	type: "nickRequest",
        	value: document.getElementById("nickname").value
        };
        if(mySocket.readyState === WebSocket.OPEN)
        	mySocket.send(JSON.stringify(msg));
	});
	InitGame();
}





function communication() {
    var mySocket = new WebSocket("ws://127.0.0.1:9002");
    mySocket.onerror = function(evt)
    {
        alert("123");
    }
    mySocket.onopen = function(event)
    {
        var msg = {
        	type: "nickRequest",
        	value: "mynick"
        };
        mySocket.send(JSON.stringify(msg));
    }
    mySocket.onmessage = function(event) {
    	console.log("got message from server");
    }
}

