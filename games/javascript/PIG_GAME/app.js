/*
GAME RULES:

- The game has 2 players, playing in rounds
- In each turn, a player rolls a dice as many times as he whishes. Each result get added to his ROUND score
- BUT, if the player rolls a 1, all his ROUND score gets lost. After that, it's the next player's turn
- The player can choose to 'Hold', which means that his ROUND score gets added to his GLOBAL score. After that, it's the next player's turn
- The first player to reach 100 points on GLOBAL score wins the game

*/

var scores, roundScore, activePlayer, gamePlaying, winningScore;

//start the game
newGame();

function newGame() {
    scores = [0,0];
    roundScore = 0;
    activePlayer = 0;
    gamePlaying = true;


    document.getElementById('dice-1').style.display = 'none';
    document.getElementById('dice-2').style.display = 'none';
    document.getElementById('score-0').textContent = '0';
    document.getElementById('score-1').textContent = '0';
    document.getElementById('current-0').textContent = '0';
    document.getElementById('current-1').textContent = '0';
    document.getElementById('name-0').textContent = 'Player 1';
    document.getElementById('name-1').textContent = 'Player 2';
    document.querySelector('.player-0-panel').classList.remove('winner');
    document.querySelector('.player-1-panel').classList.remove('winner');
    document.querySelector('.player-0-panel').classList.remove('active');
    document.querySelector('.player-1-panel').classList.remove('active');
    document.querySelector('.player-0-panel').classList.add('active');


    winningScore = prompt('Enter your winning score');
}


function nextPlayer() {
    activePlayer === 0 ? activePlayer = 1 : activePlayer = 0;
    roundScore = 0;

    document.getElementById('current-0').textContent = '0';
    document.getElementById('current-1').textContent = '0';
    document.querySelector('.player-0-panel').classList.toggle('active');
    document.querySelector('.player-1-panel').classList.toggle('active');
    document.getElementById('dice-1').style.display = 'none';
    document.getElementById('dice-2').style.display = 'none';
}


var dice_num = 0;

document.querySelector('.btn-roll').addEventListener('click', function(){
    if(gamePlaying){
    //1. generate a random number
    var dice1 = Math.floor(Math.random() * 6) + 1;
    var dice2 = Math.floor(Math.random() * 6) + 1;

    if(dice1===6 && dice_num===6){
            scores[activePlayer] = 0;
            document.getElementById('score-'+activePlayer).textContent = '0';
            nextPlayer();
    }

    dice_num = dice1;



    //2. Display that number
    document.getElementById('dice-1').style.display = 'block';
    document.getElementById('dice-2').style.display = 'block';
    document.getElementById('dice-1').src = 'dice-'+ dice1 + '.png';
    document.getElementById('dice-2').src = 'dice-'+ dice2 + '.png';


    //3. Update the round score if the rolled number was not 1
    if(dice1 !== 1 && dice2 !== 1) {
        //Add score
        roundScore += dice1 + dice2;
        document.querySelector('#current-'+activePlayer).textContent = roundScore;
    }else {
        //Next Player
        nextPlayer();

    }
  }

});


document.querySelector('.btn-hold').addEventListener('click', function() {
    if(gamePlaying){
    //Add currentScore to player gloabalScore
    scores[activePlayer] += roundScore;

    //Update the UI
    document.getElementById('score-'+activePlayer).textContent = scores[activePlayer];

    //Check if the player won
    if(scores[activePlayer] >= winningScore) {
        document.getElementById('name-'+activePlayer).textContent = 'Winner!';
        document.getElementById('dice-1').style.display = 'none';
        document.getElementById('dice-2').style.display = 'none';
        document.querySelector('.player-'+activePlayer+'-panel').classList.remove('active');
        document.querySelector('.player-'+activePlayer+'-panel').classList.add('winner');
        gamePlaying = false;
    }else {
        //Next player
        nextPlayer();
    }
 }
});

//new game btn clicked
document.querySelector('.btn-new').addEventListener('click',newGame);