const OPEN = 0;
const CLOSE = 1;
const numberOfDoors = 101; // since index going to be starting with 1
let door = Array(numberOfDoors).fill(CLOSE, 1, numberOfDoors); // fill initla state with CLOSE
for(walk = 1; walk < numberOfDoors; walk++) {
    door.map((value, index) => {
        if(walk === 1) { // first walk
            door[index] === OPEN ? door[index] = CLOSE: door[index] = OPEN;
        } else if ((index) % walk === 0) {
            door[index] === OPEN ? door[index] = CLOSE: door[index] = OPEN;
        }
    });
}

let openedDoors = [];

door.map((value, index) => {
    if (door[index] === OPEN) {
        openedDoors.push(`Door ${index}`);
    }
});

console.log(`Doors opened in the end are: ${openedDoors}`);
