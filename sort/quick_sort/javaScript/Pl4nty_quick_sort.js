const swap = (arr, i, j) => {
   [arr[i], arr[j]] = [arr[j], arr[i]];
}

const partition = (arr, pivot, left, right) => {
    let pivotValue = arr[pivot];
    let partitionIndex = left;

    for (let i = left; i < right; i++) {
        if (arr[i] < pivotValue){
            swap(arr, i, partitionIndex);
            partitionIndex++;
        }
    }
    swap(arr, right, partitionIndex);
    return partitionIndex;
}

module.exports = (arr, left, right) => {
    let pivot;
    let partitionIndex;

    if (left < right){
        pivot = right;
        partitionIndex = partition(arr, pivot, left, right);
        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
    return arr;
}
