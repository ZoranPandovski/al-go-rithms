/*
    * Iterative version of Lucas Sequence

    * Lucas Numbers Formula
    L(n) = 2 (if n = 1) | 1 (if n = 2) | L(n-1) + L(n-2) (if n > 2)
*/


function LucasSeries(n) {
    // Declaring first term as 2 & second term as 1.
    var lucas_series_list = [], a1 = 2, a2 = 1;
    if (n >= 1) {
        lucas_series_list.push(a1);
    }
    if (n >= 2) {
        lucas_series_list.push(a2);
    }
    if (n > 2) {
        for (var i = 0; i < n - 2; i++) {
            var an = a1 + a2;
            a1 = a2;
            a2 = an;
            lucas_series_list.push(an);
        }
    }

    return lucas_series_list;
}

module.exports = LucasSeries;