var getDigit = function(num,nth){
    var ret = 0;
    while(nth--){
        ret = num % 10
        num = Math.floor((num - ret) / 10)
    }
    return ret
};
function radixSort(list){
    var max = Math.floor(Math.log10(Math.max.apply(Math,list))),
        digitBuckets = [],
        idx = 0;

    for(var i = 0;i<max+1;i++){

        digitBuckets = []
        for(var j = 0;j<list.length;j++){
            var digit = getDigit(list[j],i+1);

            digitBuckets[digit] = digitBuckets[digit] || [];
            digitBuckets[digit].push(list[j]);
        }

        idx = 0
        for(var t = 0; t< digitBuckets.length;t++){
            if(digitBuckets[t] && digitBuckets[t].length > 0){
                for(j = 0;j<digitBuckets[t].length;j++){
                    list[idx++] = digitBuckets[t][j];
                }
            }
        }
    }
    return list
}

module.exports = radixSort;
