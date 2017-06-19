'use strict'

const binary_search = function(arr, num, start = 0, end = (arr.length - 1)) {
    let middle = Math.floor((start + end) / 2);
    switch (true) {
        case arr[middle] === num:
            return arr[middle];
        case end - start === 0:
            return false;
        case arr[middle] < num:
            return binary_search(arr, num, middle + 1, end);
        case arr[middle] > num:
            return binary_search(arr, num, start, middle);
    }
    return middle;
}
