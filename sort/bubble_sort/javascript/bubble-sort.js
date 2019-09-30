const swap = (array, first, second) => {
    
    const temp = array[first];
    
    array[first] = array[second];
    array[second] = temp;
    
    return array;
};

const bubbleSort = (array, nonDecreasing = true) => {
    
    let swapped = true;
    
    while (swapped) {
        
        swapped = false;
        
        for (let i = 0; i < array.length - 1; ++i) {
            
            if (nonDecreasing && (array[i] > array[i + 1]) ||
                !nonDecreasing && (array[i] < array[i + 1])) {

                swap(array, i, i + 1);
                
                swapped = true;
            }
        }
    }
    
    return array;
};

module.exports = bubbleSort;