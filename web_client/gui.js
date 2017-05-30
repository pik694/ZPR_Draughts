
var mySocket = null
var currentRoom = ""
var currentNick = ""
window.onload = function() {
    generateRooms();
	mySocket = new WebSocket("ws://127.0.0.1:9002");
	mySocket.onmessage = function(event) {
		var msg = JSON.parse(event.data);
		console.log(event.data);
	}
	$("button").on("click",nickButton);
	InitGame();
}

// game form

function gameSwitch() {
    hideAll();
    document.getElementById("nick_output").innerHTML = currentNick;
    document.getElementById("room_name_output").innerHTML = currentRoom;
    $("#game_form").show("slow");
}




// room form

function generateRooms() {
    var elements = document.getElementsByClassName("room");
    console.log("aww");
    for(var i=0;i<elements.length;i++) {
        console.log("aww");
        elements[i].addEventListener("click",roomClickHandler,false);
    }
}
function roomClickHandler() {
    currentRoom = this.innerHTML;
    gameSwitch();
}





// utility functions
function hideAll() {
    $("#room_form").hide();
    $("#game_form").hide();
    $("#nick_form").hide();
}



// nick form
function nickButton(event) {
    currentNick = document.getElementById("nickname").value;
    hideAll();
    $("#room_form").show("slow");
    console.log("button clicked");
    var msg = {
        type: "nickRequest",
        value: document.getElementById("nickname").value
    };
    if(mySocket.readyState === WebSocket.OPEN)
        mySocket.send(JSON.stringify(msg));
}





// network communication
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

