/* Flatten algorithm takes an array that potentially contains other arrays within.
The Flatten algorithm removes all inner arrays and places the values in the parent
array with the original order conserved. This solution doesn't utilize recursion which
could potentially speed up the process. ex. flatten([1,[2,3],[[4]]],[]) becomes [1,2,3,4]
- harshildp */

function flatten(arr) {
    if (!arr.length) {
        return arr
    }
    var i = 0
    while (i < arr.length) {
        if (Array.isArray(arr[i]) == true) {
            if (arr[i].length) {
                arr.length += arr[i].length - 1;
                for (var k = arr.length - 1; k > i; k--) {
                    arr[k] = arr[k - (arr[i].length - 1)];
                }
                var temp = arr[i]
                for (var j = 0; j < temp.length; j++) {
                    arr[i + j] = temp[j];
                }
            } else {
                for (var m = i; m < arr.length - 1; m++) {
                    arr[m] = arr[m + 1];
                }
                arr.length--;
            }
        } else {
            i++;
        }
    }
    return arr;
}


