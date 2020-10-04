const checkValues = (arr: number[]) => {
    for (let i = arr.length -1; i >= 0; i--) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

const shuffleValues = (arr: number[]) => {
    let temp: number;
    let index: number;
    for (let i = arr.length; i > 0;) {
        index = Math.floor(Math.random() * i);
        i--;
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    return arr;
}

const bogoSortValues = (arr: number[]) => {
    let sorted: boolean = checkValues(arr);
    while(!sorted) {
        arr = shuffleValues(arr);
        sorted = checkValues(arr);
    }
    return arr;
}

// test case
let testArr: number[];
testArr = [2, 13 , 1, 4, 5, -1];
console.log(bogoSortValues(testArr));