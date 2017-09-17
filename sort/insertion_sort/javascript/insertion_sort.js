(function(){
"use strict"

const insertionSort = function(arr){
    let len = arr.length;
    for(let i = 1; i < len; i++){
        for(let j=i; j >=0; j--){
            if(arr[j] < arr[j-1]){
             let temp = arr[j-1];
             arr[j-1]= arr[j];
             arr[j] = temp;
             } else {
             break;
             }
        }

    }return arr;
}

//test
const uns_arr = [5,3,21,1,4];
console.log(uns_arr + ' => ' + insertionSort([5,3,21,1,4]));
});