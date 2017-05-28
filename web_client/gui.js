


window.onload = function() {
	$("button").on("click",function(event) {
		alert("hey");
		console.log("button clicked");
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
        example.send("off");
    }
    mySocket.onmessage = function(event) {
    	console.log("got message from server");
    }
}