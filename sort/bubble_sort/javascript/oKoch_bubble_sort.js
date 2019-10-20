module.exports = (arrayToSort) => {
   for(j = 0; j < arrayToSort.length - 1; j++) {
        for(i = 0; i < arrayToSort.length - 1; i++) {
            if( arrayToSort[i] > arrayToSort[i+1]) {
                let tmp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[i+1];
                arrayToSort[i+1] = tmp;
            }
        }
    }
    
    return arrayToSort;
} 