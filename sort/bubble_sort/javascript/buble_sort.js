(function(){
"use strict"

const bubleSort = function(arr)
{
    let swapped = true;
    do {
        swapped = false;
        for (let i=0; i < arr.length-1; i++) {
            if (arr[i] > arr[i+1]) {
                let temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = true;
            }
        }
    } while (swapped);

    return arr;
}

//test
const uns_arr = [5,3,21,1,4];
console.log(uns_arr + ' => ' + bubleSort([5,3,21,1,4]));
})();