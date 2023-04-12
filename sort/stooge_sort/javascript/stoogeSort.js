function stoogeSort(arr) {
    if (arr.length <= 1) {
        return arr;
    }

    if (arr[0] > arr[arr.length - 1]) {
        [arr[0], arr[arr.length - 1]] = [arr[arr.length - 1], arr[0]];
    }

    if (arr.length > 2) {
        const oneThird = Math.floor(arr.length / 3);
        const firstTwoThirds = arr.slice(0, arr.length - oneThird);
        const lastTwoThirds = arr.slice(oneThird);
        return stoogeSort(firstTwoThirds).concat(stoogeSort(lastTwoThirds)).concat(stoogeSort(firstTwoThirds));
    }

    return arr;
}
