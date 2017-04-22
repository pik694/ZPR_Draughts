/**
 * Created by John on 3/23/2017.
 */

var BROWN = "#b16030";
var WHITE = "#f6eaba";
var BROWN_PAWN_COLOR = "#512800";
var BROWN_PAWN_MIDDLE_COLOR = "#3f1600";
var WHITE_PAWN_COLOR = "#dace8b";
var PAWN_FOCUSED = "#2768ea";
var board = null;
var board_size = 500;
// boards contants
var EMPTY_FIELD = 0;
var WHITE_PAWN = 1;
var BROWN_PAWN = 2;

function HandleClicks(event)
{
    var rel_X = event.layerX - this.offsetLeft;
    var rel_Y = event.layerY - this.offsetTop;
    var myGame = document.getElementById("game");
    console.log(Math.floor(rel_X/(myGame.offsetWidth/8)) + " " + rel_Y/(myGame.offsetWidth/8));
    //console.log(Math.floor(1.1));
    var x_ingame = Math.floor(rel_X/(myGame.offsetWidth/8));
    var y_ingame = Math.floor(rel_Y/(myGame.offsetWidth/8));
    FocusOnPawn(x_ingame,y_ingame);
}

function FocusOnPawn(x,y)
{
    DrawEverything();
    var myGame = document.getElementById("game");
    var size  = myGame.width/8;
    var context = myGame.getContext("2d");
    context.globalAlpha = 0.4;
    context.fillStyle = PAWN_FOCUSED;
    context.fillRect(x*size,y*size,size,size);
    
    
    context.globalAlpha = 1.0;
}


window.onload = function() {
    InitBoard();

    // add event listener
    var myGame = document.getElementById("game");
    game.addEventListener("click",HandleClicks);
    DrawEverything();

}

function DrawEverything()
{
    var myGame = document.getElementById("game");
    var context = myGame.getContext("2d");
    context.fillStyle = "rgb(255,255,255)";
    context.rect(0,0,myGame.width,myGame.width);
    context.fill();
    DrawLines(context,myGame.width);
    GeneratePawns(context,myGame.width);
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


function GeneratePawns(context,size)
{
    var lineOffset = size/8;
    for(var i=0;i<8;i++)
        for(var j=0;j<8;j++)
        {
            if(board[i][j] == BROWN_PAWN)
                context.fillStyle = BROWN_PAWN_COLOR;
            if(board[i][j] == WHITE_PAWN)
                context.fillStyle = WHITE_PAWN_COLOR;
            if(board[i][j] != EMPTY_FIELD)
            {
                context.beginPath();
                context.arc((lineOffset / 2) + i*lineOffset, (lineOffset / 2) + j*lineOffset, lineOffset / 2.2, 0, 2 * Math.PI);
                context.fill();
            }
        }
}


