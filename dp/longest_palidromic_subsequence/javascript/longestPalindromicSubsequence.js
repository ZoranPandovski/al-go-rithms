(function(){
"use strict"

const max = function(x,y) {

}

const lps = function(seq, i, j) {
    if (i > j) {
        return 0;
    }

    if (i === j) {
        return 1;
    }

    //compare first and last character
    if (seq[i] === seq[j]) {
        //if the same then recurse for seq[1+1,j-1]
        return lps(seq, i+1, j-1) + 2;
    } else {
    //return max of seq[i,j-1] or seq[i+1,j]
        return Math.max(lps(seq, i, j-1), lps(seq, i+1, j));
    }

}

module.exports = lps;

})();  