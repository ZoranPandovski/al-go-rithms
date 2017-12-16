/**
 * @param {Array} arr
 */
function mergeSort(arr)
{
    if (arr.length < 2)
        return arr;
 
    var mid = Math.floor(arr.length / 2);
    var left   = arr.slice(0, mid);
    var right  = arr.slice(mid, arr.length);
 
    return merge(mergeSort(left), mergeSort(right));
}
 
function merge(left, right)
{
    var result = [];
 
    while (left.length && right.length) {
        if (left[0] <= right[0]) {
            result.push(left.shift());
        } else {
            result.push(right.shift());
        }
    }
 
    while (left.length)
        result.push(left.shift());
 
    while (right.length)
        result.push(right.shift());
 
    return result;
}
 
module.exports = mergeSort;
