

window.onload = function () {
	//alert("fuck");
	var example = new WebSocket("ws://127.0.0.1:8080");
	example.onerror = function(evt)
	{
		alert("123");
	}
	example.onopen = function(event)
	{
		example.send("off");
	}
	//example.send("urgent");
	//example.close();
}