// DECLARING FUNCTIONS
    // Start the game by entering in the blank letter spaces
    function start (arrFrom, arrTo){
        blank = arrFrom.length
        for(i=0; i<blank; i++){
            arrTo[i] = "_";
        }
    }
    // Determine if an input (user) is in an array (arr)
    function inArray(user, arr){
        var count=arr.length;
        for(var i=0;i<count;i++){
            if(arr[i]===user){return true;}
        }
        return false;
    };

    // Reset the game after a win/loss
    function reset (){
        guessesLeft=10;
        guessedLetters=[];
        correctLetters=[];
        computerWord = computerChoices[Math.floor(Math.random() * computerChoices.length)];
        computerChar = computerWord.split("");
    };

    // Count the number of times a character is in an array
    function countInArray(arr){
        var count=arr.length;
        for (i=0, j=0; count>i; i++, j++){
            if(arr[i]==arr[j]){
                return "repeat"
            };
         };
    };

    // Replacing the "_" with the correctly guessed letters
    function correctArrayReplacement(arrKey, arrCorrect, guess){
        for(i=0; i<=arrKey.length; i++){
            if(arrKey[i]==guess){
            arrCorrect.splice(i, 1, guess)
            };
        }
        document.getElementById("current").innerHTML = arrCorrect;
    };
    
    // Adding a comparison array
    function comparison(arr1, arr2, newArr) {
        for(i=0; i<arr1.length; i++){
            newArr.splice(i, 1, (arr1[i]==arr2[i]));
        }
    
    };

// DEFINING VARIABLES 
    var wins = document.getElementById("wins");
    var losses = document.getElementById("losses");
    var guessesLeft = 9; 
    var guessedLetters = [];
    var correctLetters = [];
    var comparisonArray = [];

// ARRAYS
    computerChoices = ["koala", "giraffe", "squirrel", "moose", "alligator", "okapi", "zebra", "elephant", "otter", "penguin"];
    messages = ["You killed it", "You go Glen Coco", "Congrats!", "Ayyyyyyyy!"];

    userChoices = [];
    for (i=97;i<=122;i++){
        userChoices[userChoices.length] = String.fromCharCode(i);
    }
    
    
    var computerWord = computerChoices[Math.floor(Math.random() * computerChoices.length)];
    var winMessage = messages[Math.floor(Math.random()*messages.length)];
    var computerChar = computerWord.split("");

start(computerChar, correctLetters);

document.onkeyup = function (event) {
    var userGuess = event.key;
    var validLetter = inArray(userGuess, userChoices); 
    var correctLetterCheck = inArray(userGuess,computerChar);
    var repeatLetters = countInArray(computerChar);
    if(validLetter == true){
        if( correctLetterCheck==true){
            correctArrayReplacement(computerChar, correctLetters, userGuess);
        } else {
            guessesLeft--;
            guessedLetters.push(userGuess);
        };
        
        if(guessesLeft==0) {
            losses++;
            alert("Sorry, the correct answer was " +computerWord+ "!");
            reset ();
            start(computerChar, correctLetters);
        };
        
        comparison(computerChar, correctLetters, comparisonArray);

        if(comparisonArray.includes(false)){

        }else{
            wins++;
            alert("You got it! The answer was " +computerWord+ ". " +winMessage);
            reset ();
            start(computerChar, correctLetters); 
        };

        
    // If the user does not enter a letter, alert them. 
    } else {
        alert("Invalid input! Please use the alphabet :)")

    };  



    // Changing HTML text
    document.getElementById("wins").innerHTML = wins;
    document.getElementById("losses").innerHTML = losses;
    document.getElementById("remainingGuesses").innerHTML = guessesLeft;
    document.getElementById("guessedLetters").innerHTML = guessedLetters;
    document.getElementById("current").innerHTML = correctLetters;

};