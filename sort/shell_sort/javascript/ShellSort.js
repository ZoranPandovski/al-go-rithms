function shellSort (a) {
    for (var h = a.length; h > 0; h = parseInt(h / 2)) {
        for (var i = h; i < a.length; i++) {
            var k = a[i];
            for (var j = i; j >= h && k < a[j - h]; j -= h)
                a[j] = a[j - h];
            a[j] = k;
        }
    }
    return a;
}
var arrayToSort = [1,4,5,-4,2,56,345,23];
console.log('Not sorted array', arrayToSort);
shellSort(arrayToSort);
console.log('Sorted array', arrayToSort);