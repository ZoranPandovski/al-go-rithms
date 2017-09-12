'use strict';

const russian_peasant = function(a, b) {
    let x = a,
        y = b,
        sum = 0;
    while (x > 0) {
        if (x % 2 == 1) {
            sum += y;
        }
        x = x >> 1
        y = y << 1
    }
    return sum;
}
