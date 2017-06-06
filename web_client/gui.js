
var mySocket = null
var currentRoom = ""
var currentNick = ""
window.onload = function() {
    InitGame();
	mySocket = new WebSocket("ws://" + location.hostname + ":9002");
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
                else {
                    nickOccupied();
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
            case "BoardSignal":
                gameController(msg);
            break;
            case "OpponentLeftRoomSignal":
                opponentLeft();
            break;
            case "GameEndSignal":
                gameEnded(msg.value);
            break;
        }
	}
    $("#submit_new_room").on("click",NewRoomRequestSignal);
	$("#submit_nick").on("click",NickRequestSignal);
    $("#start_game").on("click",NewGameSignal);
    $("#chat_input").on("keyup",TextMessage);
    $("#leave_room").on("click",LeaveRoomSignal);
    $("#refresh_rooms").on("click",RoomsRequestSignal);

	//InitGame();
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
    //currentRoom = document.getElementById("new_room_value").value;
    var msg = {
        type: "NewRoomRequestSignal"
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

function NewGameSignal() {
    console.log("new game signal");
    var msg = {
        type: "NewGameSignal"
    };
    sendRequest(msg);
}
function BasicMoveSignal(x1,y1,x2,y2) {
    console.log("new move signal");
    points = new Array(4);
    points[0] = x1;
    points[1] = 7 - y1;
    points[2] = x2;
    points[3] = 7 - y2;
    var msg = {
        type: "MoveSignal",
        value: points
    };
    sendRequest(msg);
}
function PathMoveSignal(data,size) {
    var moves = new Array(size);
    for(var i=0;i<size;i++) {
        moves[i] = data[i];
        if(i % 2 === 1)
            moves[i] = 7 - moves[i];
    }
    var msg = {
        type: "MoveSignal",
        value: moves
    };
    sendRequest(msg);
}
function LeaveRoomSignal() {
    var msg = {
        type: "LeaveRoomSignal"
    }
    sendRequest(msg);
    switchToRooms();
    RoomsRequestSignal();
}

// game form

function gameEnded(value) {
    if(value) {
        $("#you_won").show("slow");
    }
    else {
        $("#you_lost").show("slow");
    }
}


function opponentLeft() {
    document.getElementById("whose_turn").innerHTML = "Opponent Left";
}

function gameController(message) {
    if(message.team === "white") {
        PLAYER_TEAM = WHITE_PAWN;
        PLAYER_KING = WHITE_KING;
    }
    else {
        PLAYER_TEAM = BROWN_PAWN;
        PLAYER_KING = BLACK_KING;
    }
    if(message.move) {
        document.getElementById("whose_turn").innerHTML = "Your turn";
    }
    else {
        document.getElementById("whose_turn").innerHTML = "Opponent turn";
    }
    console.log(board[0][0]);
    var i = 0;
    var j = 0;
    var counter = 0;
    for(var k=0;k<message.value.length;k++) {
        console.log(message.value[k]);
        board[i][j] = message.value[k];
        i++;
        if(i == 8) {
            i = 0;
            j++;
        }
    }
    DrawEverything();
}

function appendChat(text) {
    var data = document.getElementById("chat");
    data.innerHTML = data.innerHTML + text + "<br>";
}

function opponentArrived(name) {
    document.getElementById("opponent_nick_output").innerHTML = name;
    document.getElementById("whose_turn").innerHTML = "Game not started";
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
    document.getElementById("list_of_rooms").innerHTML = "";
    for(var i=0;i<data.length;++i) {
        var myRoomId = "room_" + data[i];
        var ul_tag = document.createElement("li");
        var a_tag = document.createElement("a");
        a_tag.setAttribute("id",myRoomId);
        var node = document.createTextNode(data[i]);
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

function nickOccupied(event) {
    $("#nick_occupied_alert").hide();
    $("#nick_occupied_alert").show("slow");
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

