function minimax(newBoard, player){
    //available spots
    var free = available(newBoard);

    // checks for the terminal states such as win, lose, and tie and returning a value accordingly
    if (winning(newBoard, human))   return {score:-10};
    else if (winning(newBoard, ai)) return {score:10};
    else if (free.length === 0)     return {score:0};

    // an array to collect all the objects
    var moves = [];

    // loop through available spots
    for (var i = 0; i < free.length; i++){
        var move = {};
        move.index = newBoard[free[i]];

        // set the empty spot to the current player
        newBoard[free[i]] = player;

        //if collect the score resulted from calling minimax on the opponent of the current player
        if (player === ai){
            var result = minimax(newBoard, human);
            move.score = result.score;
        }
        else{
            var result = minimax(newBoard, ai);
            move.score = result.score;
        }

        //reset the spot to empty
        newBoard[free[i]] = move.index;

        // push the object to the array
        moves.push(move);
    }

    // if it is the computer's turn loop over the moves and choose the move with the highest score
    var bestMove;
    if(player === ai){
        var bestScore = -10000;
        for(var i = 0; i < moves.length; i++){
            if(moves[i].score > bestScore){
                bestScore = moves[i].score;
                bestMove = i;
            }
        }
    }
    else{
        // else loop over the moves and choose the move with the lowest score
        var bestScore = 10000;
        for(var i = 0; i < moves.length; i++){
            if(moves[i].score < bestScore){
                bestScore = moves[i].score;
                bestMove = i;
            }
        }
    }

    // return the chosen move (object) from the array to the higher depth
    return moves[bestMove];
}function minimax(newBoard, player){
    //available spots
    var free = available(newBoard);

    // checks for the terminal states such as win, lose, and tie and returning a value accordingly
    if (winning(newBoard, human))   return {score:-10};
    else if (winning(newBoard, ai)) return {score:10};
    else if (free.length === 0)     return {score:0};

    // an array to collect all the objects
    var moves = [];

    // loop through available spots
    for (var i = 0; i < free.length; i++){
        var move = {};
        move.index = newBoard[free[i]];

        // set the empty spot to the current player
        newBoard[free[i]] = player;

        //if collect the score resulted from calling minimax on the opponent of the current player
        if (player === ai){
            var result = minimax(newBoard, human);
            move.score = result.score;
        }
        else{
            var result = minimax(newBoard, ai);
            move.score = result.score;
        }

        //reset the spot to empty
        newBoard[free[i]] = move.index;

        // push the object to the array
        moves.push(move);
    }

    // if it is the computer's turn loop over the moves and choose the move with the highest score
    var bestMove;
    if(player === ai){
        var bestScore = -10000;
        for(var i = 0; i < moves.length; i++){
            if(moves[i].score > bestScore){
                bestScore = moves[i].score;
                bestMove = i;
            }
        }
    }
    else{
        // else loop over the moves and choose the move with the lowest score
        var bestScore = 10000;
        for(var i = 0; i < moves.length; i++){
            if(moves[i].score < bestScore){
                bestScore = moves[i].score;
                bestMove = i;
            }
        }
    }

    // return the chosen move (object) from the array to the higher depth
    return moves[bestMove];
}