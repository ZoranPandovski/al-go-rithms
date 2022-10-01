function combSort(array) {

    var gap = array.length;
    var shrink = 1.3;
    var sorted = false;

    while (!sorted) {

        gap = Math.floor(gap / shrink);

        if (gap > 1) {
            sorted = false;
        } else {
            gap = 1;
            sorted = true;
        }

        var i = 0;
        while (i + gap < array.length) {
            if (array[i] > array[i + gap]) {
                var temp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = temp;
                sorted = false;
            }
            i++;
        }

    }

    return array;
}