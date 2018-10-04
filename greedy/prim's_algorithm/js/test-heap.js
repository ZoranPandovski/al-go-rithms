
const Heap = require('./heap');


let heap = new Heap([
    {id: 0, w: 7},
    {id: 0, w: 13},
    {id: 0, w: 6},
    {id: 0, w: 3},
    {id: 0, w: 5}
]);

// heap.heapifyMin(0);

console.log(heap._heap);

heap.addValue({id: 0, w: 73});
console.log(heap._heap);
