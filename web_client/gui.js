
var mySocket = null
var currentRoom = ""
var currentNick = ""
window.onload = function() {
	mySocket = new WebSocket("ws://127.0.0.1:9002");
	mySocket.onmessage = function(event) {
		var msg = JSON.parse(event.data);
		console.log(event.data);
        switch(msg.type) {
            case "NickRequestSignal":
                console.log("nick request signal switch fine");
                if(msg.value == true) {
                    RoomsRequestSignal();
                    switchToRooms();
                }
            break;
            case "NewRoomRequestSignal":
                if(msg.value == true)
                    gameSwitch();
            break;
            case "EnterRoomSignal":
                if(msg.value == true)
                    gameSwitch();
            break;
            case "RoomsRequestSignal":
                genRooms(msg.value);
            break;
            case "OpponentEnteredTheRoomSignal":
                opponentArrived(msg.value);
            break;
            case "TextMessage":
                appendChat(msg.value);
            break;
        }
	}
    $("#submit_new_room").on("click",NewRoomRequestSignal);
	$("#submit_nick").on("click",NickRequestSignal);
    $("#chat_input").on("keyup",TextMessage);
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
    currentRoom = document.getElementById("new_room_value").value;
    var msg = {
        type: "NewRoomRequestSignal",
        value: parseInt(document.getElementById("new_room_value").value)
    };
    sendRequest(msg);
}
function EnterRoomSignal(room_name) {
    var msg = {
        type: "EnterRoomSignal",
        value: parseInt(room_name)
    };
    sendRequest(msg);
}
function RoomsRequestSignal() {
    console.log("room request");
    var msg = {
        type: "RoomsRequestSignal"
    };
    sendRequest(msg);
}
function TextMessage(event) {
    console.log(event.keyCode);
    if(event.keyCode != 13)
        return;
    var line = currentNick + ": " + document.getElementById("chat_input").value;
    var msg = {
        type: "TextMessage",
        value: line
    };
    appendChat(line);
    document.getElementById("chat_input").value = "";
    sendRequest(msg);
}


// game form

function appendChat(text) {
    var data = document.getElementById("chat");
    data.innerHTML = data.innerHTML + text + "<br>";
}

function opponentArrived(name) {
    document.getElementById("opponent_nick_output").innerHTML = name;
}

function gameSwitch() {
    hideAll();
    document.getElementById("nick_output").innerHTML = currentNick;
    document.getElementById("room_name_output").innerHTML = currentRoom;
    $("#game_form").show("slow");
}




// room form
// room_form  
function genRooms(data) {
    for(var i in data) {
        var myRoomId = "room_" + i;
        var ul_tag = document.createElement("li");
        var a_tag = document.createElement("a");
        a_tag.setAttribute("id",myRoomId);
        var node = document.createTextNode(i);
        a_tag.appendChild(node);
        ul_tag.appendChild(a_tag);
        var xyz = document.getElementById("list_of_rooms").appendChild(ul_tag);
        document.getElementById(myRoomId).addEventListener("click",roomClickHandler,false);
    }
}

function generateRooms() {
    var elements = document.getElementsByClassName("room");
    console.log("aww");
    for(var i=0;i<elements.length;i++) {
        console.log("aww");
        elements[i].addEventListener("click",roomClickHandler,false);
    }
    //genRooms();
}
function roomClickHandler() {
    console.log("room Click Handler");
    currentRoom = this.innerHTML;
    console.log(this.innerHTML);
    EnterRoomSignal(this.innerHTML);
    //gameSwitch();
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

