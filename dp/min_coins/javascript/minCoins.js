(function(){
"use strict"

/**
 * minCoins calculates the minimum number of coins needed to make change
 * coins is an ordered array of coin denominations
 * change is the total amount required
 */
const minCoins = function(coins, change) {
    var table = [0];

    for (var i = 1; i <= change; i++) {
        table[i] = Number.MAX_VALUE;
    }

    for (var i = 1; i <= change; i++) {
        for (var j = 0; j < coins.length; j++) {
            if (coins[j] <= i)
            {
                var subResult = table[i-coins[j]];
                if (subResult != Number.MAX_VALUE && subResult +1 < table[i]) {
                    table[i] = subResult + 1;
                }
            }
        }
    }
    return table[change];
}

module.exports = minCoins;

})();  