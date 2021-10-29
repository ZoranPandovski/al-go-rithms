//Game Background 
var myVar = setInterval(setColor, 300);

function setColor() {
    var x = document.body;
    x.style.backgroundColor = x.style.backgroundColor == "coral" ? "royalblue" : "coral";
}




//Game variables
let inputDir = { x: 0, y: 0 };
let speed = 15;
let score = 0;
let lastPaintTime = 0;
const foodSound = new Audio("music/food.mp3")
const gameOverSound = new Audio("music/crash-sound.mp3")
const musicSound = new Audio("music/Don't Stop.mp3")


let snakeArr = [
    { x: 13, y: 15 }
];
food = { x: 3, y: 5 }





//Game functions
function main(ctime) {
    window.requestAnimationFrame(main);
    if ((ctime - lastPaintTime) / 1000 < 1 / speed) {
        return
    }
    lastPaintTime = ctime
    gameEngine()


}

function isCollide(snake) {
    //If snake bumps into itself
    for (let i = 1; i < snakeArr.length; i++) {
        if (snake[i].x === snake[0].x && snake[i].y === snake[0].y) {
            return true;
        }
    }
    //If the snake bumps into the wall
    if (snake[0].x >= 18 || snake[0].x <= 0 || snake[0].y >= 18 || snake[0].y <= 0) {
        return true;
    }
    return false;
}





function gameEngine() {
    //part 1: Updating the snake & food array
    if (isCollide(snakeArr)) {
        musicSound.pause()
        gameOverSound.play();
        inputDir = { x: 0, y: 0 }
        alert("Game Over! Press any key to continue,NOOB.")
        snakeArr = [{ x: 13, y: 15 }]
        musicSound.play()
        score = 0
    }




    //If snake has eaten the food  increment the score by 1 and regenerate the food
    if (snakeArr[0].y === food.y && snakeArr[0].x === food.x) {
        foodSound.play()
        score += 1

        if (score > hiscoreval) {
            hiscoreval = score
            localStorage.setItem("hiscore", JSON.stringify(hiscoreval))
            hiscoreBox.innerHTML = ' Hi Score : ' + hiscoreval
        }

        scoreBox.innerHTML = "Score: " + score;
        snakeArr.unshift({ x: snakeArr[0].x + inputDir.x, y: snakeArr[0].y + inputDir.y })
        let a = 9;
        let b = 15;

        food = { x: Math.round(a + (b - a) * Math.random()), y: Math.round(a + (b - a) * Math.random()) }
    }






    //Moving the snake
    for (let i = snakeArr.length - 2; i >= 0; i--) {
        snakeArr[i + 1] = {...snakeArr[i] };
    }

    snakeArr[0].x += inputDir.x
    snakeArr[0].y += inputDir.y






    //part 2 : Display the snake and food array
    //Displaying snake
    board.innerHTML = "";
    snakeArr.forEach((e, index) => {
        snakeElement = document.createElement("div");
        snakeElement.style.gridRowStart = e.y;
        snakeElement.style.gridColumnStart = e.x;
        if (index === 0) {
            snakeElement.classList.add('head');
        } else {
            snakeElement.classList.add('snake');
        }

        board.appendChild(snakeElement);
    })





    //Displaying food
    foodElement = document.createElement("div");
    foodElement.style.gridRowStart = food.y;
    foodElement.style.gridColumnStart = food.x;
    foodElement.classList.add('food');
    board.appendChild(foodElement);
}






//Game Logic

let hiscore = localStorage.getItem('hiscore')
if (hiscore === null) {
    hiscoreval = 0
    localStorage.setItem('hiscore', JSON.stringify(hiscoreval))
} else {
    hiscoreval = JSON.parse(localStorage.getItem(hiscore))
    hiscoreBox.innerHTML = ' Hi Score : ' + hiscore
}


window.requestAnimationFrame(main);
window.addEventListener('keydown', e => {
    inputDir = { x: 0, y: 1 } //Starts the game
    musicSound.play()

    switch (e.key) {
        case "ArrowUp":

            inputDir.x = 0;
            inputDir.y = -1;
            break;

        case "ArrowDown":

            inputDir.x = 0;
            inputDir.y = 1;
            break;

        case "ArrowLeft":

            inputDir.x = -1;
            inputDir.y = 0;
            break;

        case "ArrowRight":

            inputDir.x = 1;
            inputDir.y = 0;
            break;

        case "w":

            inputDir.x = 0;
            inputDir.y = -1;
            break;

        case "s":

            inputDir.x = 0;
            inputDir.y = 1;
            break;

        case "a":

            inputDir.x = -1;
            inputDir.y = 0;
            break;

        case "d":

            inputDir.x = 1;
            inputDir.y = 0;
            break;

        case "l":
            score += 1;
            break;

        default:
            break;
    }


})