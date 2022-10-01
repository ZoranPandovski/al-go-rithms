function gnomeSort(array) {
    var index = 0;
    var length = array.length;

    while (index < length) {
        if (index == 0 || array[index] >= array[index - 1]) {
            index++;
        } else {
            var temp = array[index];
            array[index] = array[index - 1];
            array[--index] = temp;
        }
    }

    return array;
}

gnomeSort([2, 9, 4, 3, 0.1, 0.4, 1, 2, -0.8])