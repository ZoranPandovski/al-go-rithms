const bubbleSort = require('./bubble-sort');

const arrays = [
    {
        unsorted: [4, 1, 8, 5, 1, 9, 5, 3, 5, 7, 1],
        nonDecreasing: [1, 1, 1, 3, 4, 5, 5, 5, 7, 8, 9],
        nonIncreasing: [9, 8, 7, 5, 5, 5, 4, 3, 1, 1, 1]
    },
    {
        unsorted: [3, 5, 4, 1, 0],
        nonDecreasing: [0, 1, 3, 4, 5],
        nonIncreasing: [5, 4, 3, 1, 0]
    },
    {
        unsorted: [5, -1, -6, 7, 5, -9, 0],
        nonDecreasing: [-9, -6, -1, 0, 5, 5, 7],
        nonIncreasing: [7, 5, 5, 0, -1, -6, -9]
    },
]

describe('Sort the arrays using Bubble Sort', () => {
    
    arrays.forEach(array => {
        
        console.log(`Sorting the array: [${array.unsorted}]`);
    
        it('Sort in non-decreasing order', () => {

            const sorted = bubbleSort(array.unsorted);

            expect(sorted).toEqual(array.nonDecreasing);
        });

        it('Sort in non-increasing order', () => {

            const sorted = bubbleSort(array.unsorted, false);

            expect(sorted).toEqual(array.nonIncreasing);
        });
    });
});