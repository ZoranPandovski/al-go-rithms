(function() {
    const binarySearch = function (array, findValue, min = 0, max = (array.length - 1)) { 
        array = array.sort((a, b) => a - b);
        let mid = Math.floor((min+(max-min)/2);

        while( array[mid] !== findValue && min < max){
            if(array[mid] > findValue){
                max = mid-1;
            }else {
                min = mid+1;
            }
            mid = Math.floor((min+max)/2);
        }

        return (array[mid] == findValue) ? mid : -1;
    };

    module.exports = binarySearch;
})();