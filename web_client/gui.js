
var mySocket = null
var currentRoom = ""
var currentNick = ""
window.onload = function() {
    generateRooms();
	mySocket = new WebSocket("ws://127.0.0.1:9002");
	mySocket.onmessage = function(event) {
		var msg = JSON.parse(event.data);
		console.log(event.data);
        switch(msg.type) {
            case "NickRequestSignal":
                console.log("nick request signal switch fine");
                if(msg.value == true)
                    switchToRooms();
            break;
            case "NewRoomRequestSignal":
                if(msg.value == true)
                    EnterRoomSignal();
            break;
            case "EnterRoomSignal":
                if(msg.value == true)
                    gameSwitch();
            break;
        }
	}
    $("#submit_new_room").on("click",NewRoomRequestSignal);
	$("#submit_nick").on("click",NickRequestSignal);
	InitGame();
}


// messages
function sendRequest(msg) {
    if(mySocket.readyState === WebSocket.OPEN)
        mySocket.send(JSON.stringify(msg));
}
function NickRequestSignal(event) {
    var msg = {
        type: "NickRequestSignal",
        value: document.getElementById("nickname").value
    };
    sendRequest(msg);
}
function NewRoomRequestSignal(event) {
    var msg = {
        type: "NewRoomRequestSignal",
        value: parseInt(document.getElementById("new_room_value").value)
    };
    sendRequest(msg);
}
function EnterRoomSignal() {
    var msg = {
        type: "EnterRoomSignal",
        value: parseInt(document.getElementById("new_room_value").value)
    };
    sendRequest(msg);
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

function switchToRooms(event) {
    currentNick = document.getElementById("nickname").value;
    hideAll();
    $("#room_form").show("slow");
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

