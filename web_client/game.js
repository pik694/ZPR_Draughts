/**
 * Created by John on 3/23/2017.
 */

var BROWN = "#b16030";
var WHITE = "#f6eaba";
var BROWN_PAWN_COLOR = "#512800";
var BROWN_PAWN_MIDDLE_COLOR = "#3f1600";
var WHITE_PAWN_COLOR = "#dace8b";
var FIELDS_TO_MOVE = "#2768ea";
var PAWN_FOCUSED = "#010101";
var board = null;
var board_size = 1000;
// boards contants
var EMPTY_FIELD = 0;
var WHITE_PAWN = 2;
var BROWN_PAWN = 1;

var PLAYER_TEAM = 1; // 1 - BROWN, 2 - WHITE


var x1 = -1;
var y1 = -1;
var x2 = -1;
var y2 = -1;


function getMousePos(canvas, evt) {
    var rect = canvas.getBoundingClientRect();
    console.log(rect.right - rect.left);
    return {
        x: (evt.clientX - rect.left) * (1000/(rect.right - rect.left)),
        y: (evt.clientY - rect.top) * (1000/(rect.right - rect.left))
    };
}


function FocusOnPawn(x,y)
{
    DrawEverything();
    var myGame = document.getElementById("game");
    var size  = myGame.width/8;
    var context = myGame.getContext("2d");
    context.globalAlpha = 0.4;
    context.fillStyle = FIELDS_TO_MOVE;

    if(board[x][y] === PLAYER_TEAM)
        paintField(context,x,y,size);


    if(board[x][y] == EMPTY_FIELD) {
        x2 = x;
        y2 = y;
        BasicMoveSignal(x1,y1,x2,y2);
    }

    if(board[x][y] === PLAYER_TEAM) {
        x1 = x;
        y1 = y;
    }
    //context.fillStyle =
    //context.fillRect(x*size,y*size,size,size);


    context.globalAlpha = 1.0;
}

function paintField(context,x,y,size) {
    context.fillRect(x*size,y*size,size,size);
}

function paintFocus(context,x,y,size,direction) {
    if(x >= 1) {
        context.fillRect((x-1)*size,(y+direction)*size,size,size);
    }
    if(x < 7) {
        context.fillRect((x+1)*size,(y+direction)*size,size,size);
    }
}



function InitGame() {
    console.log("inting game");
    InitBoard();

    // add event listener
    var myGame = document.getElementById("game");
    myGame.width = 1000;
    myGame.height = 1000;
    board_size = 1000;
    myGame.addEventListener('click', function(evt) {
        var mousePos = getMousePos(myGame, evt);
        console.log('Mouse position: ' + mousePos.x + ',' + mousePos.y);
        FocusOnPawn(Math.floor(mousePos.x/125.0),Math.floor(mousePos.y/125.0));
    }, false);
    DrawEverything();
}
/*window.onload = function() {
    $("button").on("click",function(event) {
        alert("hey");
        console.log("button clicked");
    });
    communication();
    InitGame();

}
*/
function DrawEverything()
{
    var myGame = document.getElementById("game");
    var context = myGame.getContext("2d");
    context.clearRect(0, 0, myGame.width, myGame.height);
    context.fillStyle = "rgb(255,255,255)";
    context.rect(0,0,myGame.width,myGame.width);
    context.fill();
    DrawLines(context,myGame.width);
    DrawPawns(context,myGame.width);
}


function DrawLines(context,size) {
    var lineOffset = size/8;

    for(var i=0;i<8;i++)
        for(var j=0;j<8;j++)
        {
            if(i % 2 == 1)
            {
                if (j % 2 == 0)
                    context.fillStyle = BROWN;
                else
                    context.fillStyle = WHITE;
            }
            else
            {
                if (j % 2 == 1)
                    context.fillStyle = BROWN;
                else
                    context.fillStyle = WHITE;
            }
            context.fillRect(j*lineOffset,i*lineOffset,size,size);
        }
    context.strokeStyle = "rgb(0,0,0)";
    context.beginPath();
    context.moveTo(0,0);
    context.lineTo(size,0);
    context.lineTo(size,size);
    context.lineTo(0,size);
    context.lineTo(0,0);
    context.stroke();

}

function InitBoard()
{
    board = new Array(8);
    for(var i=0;i<8;i++)
    {
        board[i] = new Array(8);
    }

    for(var i=0;i<8;i++)
        for(var j=0;j<8;j++)
            board[i][j] = EMPTY_FIELD;
    for(var i=1;i<8;i+=2)
    {
        board[i][0] = BROWN_PAWN;
        board[i][6] = WHITE_PAWN;
    }
    for(var i=0;i<8;i+=2)
    {
        board[i][1] = BROWN_PAWN;
        board[i][7] = WHITE_PAWN;
    }
}

function DrawPawnsHelper() {
    var myGame = document.getElementById("game");
    var context = myGame.getContext("2d");
    DrawPawns(context,1000);
}

function DrawPawns(context, size)
{
    var lineOffset = size/8;
    for(var i=0;i<8;i++)
        for(var j=0;j<8;j++)
        {
            if(board[i][j] === BROWN_PAWN)
                context.fillStyle = BROWN_PAWN_COLOR;
            if(board[i][j] === WHITE_PAWN)
                context.fillStyle = WHITE_PAWN_COLOR;
            if(board[i][j] !== EMPTY_FIELD)
            {
                context.beginPath();
                context.arc((lineOffset / 2) + i*lineOffset, (lineOffset / 2) + j*lineOffset, lineOffset / 2.2, 0, 2 * Math.PI);
                context.fill();
            }
        }
}


