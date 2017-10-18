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

module.exports = insertionSort;
})();
