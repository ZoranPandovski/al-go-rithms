// The only issue is that we need to know the max/min value in order to use counting sort
function countingSort(array, minimumValue, maximumValue) {
    var i;
    var z = 0;
    var count = [];

    // Count the instances of each element.
    for (i = minimumValue; i <= maximumValue; i++) {
        count[i] = 0;
    }
    for (i=0; i < array.length; i++) {
        count[array[i]]++;
    }
    // Modify array and move elements into their sorted location.
    for (i = minimumValue; i <= maximumValue; i++) {
        while (count[i]-- > 0) {
            array[z++] = i;
        }
    }
    return array;
}

module.exports = countingSort;
