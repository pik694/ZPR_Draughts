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
var square_size = 125.0;
var path = null;
var path_size = 0;
// boards contants
var EMPTY_FIELD = 0;
var WHITE_PAWN = 2;
var BROWN_PAWN = 1;

var BLACK_KING = 3;
var WHITE_KING = 4;

var PLAYER_TEAM = 1; // 1 - BROWN, 2 - WHITE
var PLAYER_KING = 3;


var x1 = -1;
var y1 = -1;
var x2 = -1;
var y2 = -1;


function getMousePos(canvas, evt) {
    var rect = canvas.getBoundingClientRect();
    console.log(rect.right - rect.left);
    return {
        x: (evt.clientX - rect.left) * (board_size/(rect.right - rect.left)),
        y: (evt.clientY - rect.top) * (board_size/(rect.right - rect.left))
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

    if(board[x][y] === PLAYER_TEAM || board[x][y] === PLAYER_KING)
        paintField(context,x,y,size);


    if(board[x][y] == EMPTY_FIELD && x1 != -1 && y1 !=-1) {
        x2 = x;
        y2 = y;
        BasicMoveSignal(x1,y1,x2,y2);
    }

    if(board[x][y] === PLAYER_TEAM || board[x][y] === PLAYER_KING) {
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
    path = new Array(128);
    // add event listener
    var myGame = document.getElementById("game");
    myGame.oncontextmenu = function (e) {
        e.preventDefault();
        var mousePos = getMousePos(myGame,e);
        mousePos.x = Math.floor(mousePos.x/square_size);
        mousePos.y = Math.floor(mousePos.y/square_size);
        if(x1 != -1 && y1 != -1) {
            if(board[x1][y1] === PLAYER_TEAM || board[x][y] === PLAYER_KING) {
                if(path_size == 0) {
                    path[path_size] = x1;
                    path[path_size+1] = y1;
                    path_size = path_size + 2;
                }
                path[path_size] = mousePos.x;
                path[path_size+1] = mousePos.y;
                path_size = path_size + 2;
            }
        }
    };
    myGame.width = board_size;
    myGame.height = board_size;
    myGame.addEventListener('click', function(evt) {
        console.log(path.length);
        if(path_size != 0) {
            PathMoveSignal(path,path_size);
            path_size = 0;
            return;
        }
        var mousePos = getMousePos(myGame, evt);
        FocusOnPawn(Math.floor(mousePos.x/125.0),Math.floor(mousePos.y/125.0));
    }, false);
    DrawEverything();
}

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
            if(board[i][j] === BROWN_PAWN || board[i][j] === BLACK_KING) {
                context.fillStyle = BROWN_PAWN_COLOR;
            }
            if(board[i][j] === WHITE_PAWN || board[i][j] === WHITE_KING) {
                context.fillStyle = WHITE_PAWN_COLOR;
            }
            if(board[i][j] !== EMPTY_FIELD)
            {
                context.beginPath();
                context.arc((lineOffset / 2) + i*lineOffset, (lineOffset / 2) + j*lineOffset, lineOffset / 2.2, 0, 2 * Math.PI);
                context.fill();
            }
            if(board[i][j] === BLACK_KING || board[i][j] === WHITE_KING) {
                context.fillStyle = "red";
                context.textAlign = "center";
                context.font ="40px Georgia";
                context.fillText("D",(lineOffset / 2) + i*lineOffset, (lineOffset / 2) + j*lineOffset);
            }
        }
}


