function jumpSearch(array, needle) {
    var n = array.length;
    var step = Math.floor(Math.sqrt(n));
    var prev = 0;

    while (array[Math.min(step, n) - 1] < needle) {
        prev = step;
        step += Math.floor(Math.sqrt(n));

        if (prev >= n) {
            return false;
        }
    }

    while (array[prev] < needle) {
        prev++;

        if (prev == Math.min(step, n)) {
            return false
        }
    }

    if (array[prev] == needle) {
        return prev;
    }

    return false;
}

var arr = [1, 4, 6, 10, 12, 16, 21, 22, 38, 41, 44, 45];
var search = 6;

var index = jumpSearch(arr, search);

if (index === false) {
    console.log('Number not found');
} else {
    console.log('Number found at index ' + index);
}