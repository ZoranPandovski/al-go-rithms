var tableId = document.getElementById("table");
var resultstatus=document.getElementById("result");
var notifacationStatus = document.getElementById("notification");
var jcell;
var player=0;
var number;
var gameOver = 0;
var opponent = "X";		//human
var Ai_player = "O";		//AI
//var flag=0;

function generateFields() 
{
	var input = document.getElementById("input").value;
	number = Number(input);    
	//  if(flag!=number) {
	//  	flag=number;

	jcell = new Array(number);

	for (var i = 0; i < number; i++) 
	{
		jcell[i] = new Array(number);
		var newTR = document.createElement('tr');
		
		for(var j=0;j<number;j++) 
		{
			var newTD = document.createElement('td');
			jcell[i][j] = newTD;
			newTD.classList.add('cell');
			newTD.style.width="50px";
			newTD.style.height="50px";
			//newTD.innerHTML = i + " " + j;
			newTD.innerHTML="";
			newTD.dataset.row = i;
			newTD.dataset.col = j;
			newTD.addEventListener('click',handleClick);
			newTR.appendChild(newTD);

		}
		tableId.appendChild(newTR);
	}
}
//  }



function handleClick(e)
{
	var i=e.target.dataset.row;
	var j=e.target.dataset.col;
	if(is_valid_move(i,j))
	{
		make_move(i,j);
		checkwinner();
		if(resultstatus.innerHTML == "X won" || resultstatus.innerHTML == "O won" || resultstatus.innerHTML == "It's Tie")
			return;
		var AI_move = AI_turn();
		//console.log("AI_MOVE : " + AI_move);
		make_move(Math.floor(AI_move/number),Math.floor(AI_move%number));
		checkwinner();
	}
}

function is_valid_move(i,j)
{
	if(jcell[i][j].innerHTML == "")
	{
		return true;
	}
	else
	{
		notifacationStatus.innerHTML = "You can't take this move!! as it's already taken...";
		return false;
	}
}

function make_move(i,j)
{
	if(player%2==0)	
	{
		jcell[i][j].innerHTML = "X";		
	}		
	else
	{   		
		jcell[i][j].innerHTML = "O";	
	}
	player++;
}

function checkwinner()
{
	var ld=0;
	var rd=0;
	var scr;
	//For rows check
	for(var i=0;i<number;i++)
	{
		var cnt=0
		for(var j=0;j<number;j++)
		{
			if(jcell[i][j].innerHTML=="X")
				cnt++;
			else if(jcell[i][j].innerHTML=="O")
				cnt--;

		}
		scr = declarresult(cnt);
		if(scr == 1 || scr == -1)
		{
			return;
		}
	}

	// For columns check
	for(var j=0;j<number;j++)
	{
		var cnt=0
		for(var i=0;i<number;i++)
		{
			if(jcell[i][j].innerHTML=="X")
			{
				cnt++;
			}
			else if(jcell[i][j].innerHTML=="O")
			{
				cnt--;
			}
		}
		scr = declarresult(cnt);
		if(scr == 1 || scr == -1)
		{
			return;
		}
	}

	//For main-digonal check
	for(var i=0;i<number;i++){
		if(jcell[i][i].innerHTML=="X")
		{
			ld++;
		}
		else if(jcell[i][i].innerHTML=="O")
		{
			ld--;
		}
	}
		
	//For other digonal check
	for(var i=0;i<number;i++){
		if(jcell[number-1-i][i].innerHTML=="X")
		{
			rd++;
		}
		else if(jcell[number-1-i][i].innerHTML=="O")
		{
			rd--;
		}
	}	

	scr = declarresult(ld);
	if(scr == 1 || scr == -1){	return;	}
	scr = declarresult(rd);
	if(scr == 1 || scr == -1){	return;	}

	if(player == number*number)
	{
		resultstatus.innerHTML="It's Tie";
		gameOver = 1;
	}
}

function declarresult(cnt)
{
	if(cnt==number)
	{
		resultstatus.innerHTML="X won";
		gameOver = 1;
		return 1;
	}
	if(cnt==(-number))
	{
		resultstatus.innerHTML="O won";
		gameOver = 1;
		return -1;
	}
	return 0;
}

function AI_turn()
{
 	var board = [];
	for(var i=0;i<number;i++)
	{
		for(var j=0;j<number;j++)
		{
			if(jcell[i][j].innerHTML=="X")
				board.push("X");
			else if(jcell[i][j].innerHTML=="O")
				board.push("O");
			else
				board.push("_");
		}
	}
	var bestMove = -1;
	var bestVal = -1000;
	for(var i=0;i<number;i++)
	{
		for(var j=0;j<number;j++)
		{
			if(board[i*number + j] == "_")
			{
				board[i*number + j] = "O";
				var moveVal = MiniMax(board,0,0);		//0 for human and 1 for AI(computer)...
				board[i*number + j] = "_";
				if (moveVal > bestVal)
                {
					bestMove = i*number + j;
                    bestVal = moveVal;
                }
			}
		}
	}
	return bestMove;
}

function MiniMax(board,depth,pid)
{
	var score = Evaluate(board);
	if (score == 100)
		return score;

	if (score == -100)
		return score;

	if (isMovesLeft(board)==false)
		return 0;
	

	if (pid == 1)
	{
		var best = -1000;
	
		for (var i = 0; i<number; i++)
		{
			for (var j = 0; j<number; j++)
			{
				if (board[number*i + j]=="_")
				{
					if(pid == 0)
						board[number*i + j] = "X";
					else
						board[number*i + j] = "O";
					best = Math.max( best , MiniMax(board, depth+1,  (pid+1)%2));
					board[number*i + j] = "_";
				}
			}
		}
		return best;
	}
	else
	{
		var best = 1000;
	
		for(var i = 0; i<number; i++)
		{
			for(var j = 0; j<number; j++)
			{
				if (board[number*i + j]=="_")
				{
					if(pid == 0)
						board[number*i + j] = "X";
					else
						board[number*i + j] = "O";
					best = Math.min(best , MiniMax(board, depth+1, (pid+1)%2));
					board[number*i+j] = "_";
				}
			}
		}
		return best;
	}
}

function Evaluate(board)
{
	var ld=0;
	var rd=0;
	var scr;

	//For rows check
	for(var i=0;i<number;i++)
	{
		var cnt=0
		for(var j=0;j<number;j++)
		{
			if(board[i*number + j]=="X")
				cnt--;
			else if(board[i*number + j]=="O")
				cnt++;
		}
		scr = evalResult(cnt);
		if(scr == 1 || scr == -1)
		{
			return (100*scr);
		}
	}

	// For columns check
	for(var j=0;j<number;j++)
	{
		var cnt=0
		for(var i=0;i<number;i++)
		{
			if(board[i*number + j]=="X")
			{
				cnt--;
			}
			else if(board[i*number + j]=="O")
			{
				cnt++;
			}
		}
		scr = evalResult(cnt);
		if(scr == 1 || scr == -1)
		{
			return (100*scr);
		}
	}

	//For main-digonal check
	for(var i=0;i<number;i++){
		if(board[i*number + i]=="X")
		{
			ld--;
		}
		else if(board[i*number + i]=="O")
		{
			ld++;
		}
	}
		
	//For other digonal check
	for(var i=0;i<number;i++){
		if(board[(number-1-i)*(number) + i] == "X")
		{
			rd--;
		}
		else if(board[(number-1-i)*(number) + i] == "O")
		{
			rd++;
		}
	}	
	
	scr = evalResult(ld);
	if(scr == 1 || scr == -1){	return	(100*scr);	}
	scr = evalResult(rd);
	if(scr == 1 || scr == -1){	return (100*scr);	}

	return 0;

}

function evalResult(cnt)
{
	if(cnt==number)	{	return 1;	}
	if(cnt==(-number)){	return -1;	}
	return 0;
}

function isMovesLeft(board)
{
    for (var i = 0; i<number; i++)
        for (var j = 0; j<number; j++)
			if (board[number*i + j]=="_")
                return true;
    return false;
}