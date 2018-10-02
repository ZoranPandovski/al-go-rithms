Task -
------
Write a program that randomly chooses and displays four digits, each from 1 ──► 9 (inclusive) with repetitions allowed.

The program should prompt for the player to enter an arithmetic expression using just those, and all of those four digits, used exactly once each. The program should check then evaluate the expression.

The goal is for the player to enter an expression that (numerically) evaluates to 24.

    * Only the following operators/functions are allowed: multiplication, division, addition, subtraction
    * Division should use floating point or rational arithmetic, etc, to preserve remainders.
    * Brackets are allowed, if using an infix expression evaluator.
    * Forming multiple digit numbers from the supplied digits is disallowed. (So an answer of 12+12 when given 1, 2, 2, and 1 is wrong).
    * The order of the digits when given does not have to be preserved.


Source: http://rosettacode.org/wiki/24_game


function twentyfour(numbers, input) {
    var invalidChars = /[^\d\+\*\/\s-\(\)]/;

    var validNums = function(str) {
        // Create a duplicate of our input numbers, so that
        // both lists will be sorted.
        var mnums = numbers.slice();
        mnums.sort();

        // Sort after mapping to numbers, to make comparisons valid.
        return str.replace(/[^\d\s]/g, " ")
            .trim()
            .split(/\s+/)
            .map(function(n) { return parseInt(n, 10); })
            .sort()
            .every(function(v, i) { return v === mnums[i]; });
    };

    var validEval = function(input) {
        try {
            return eval(input);
        } catch (e) {
            return {error: e.toString()};
        }
    };

    if (input.trim() === "") return "You must enter a value.";
    if (input.match(invalidChars)) return "Invalid chars used, try again. Use only:\n + - * / ( )";
    if (!validNums(input)) return "Wrong numbers used, try again.";
    var calc = validEval(input);
    if (typeof calc !== 'number') return "That is not a valid input; please try again.";
    if (calc !== 24) return "Wrong answer: " + String(calc) + "; please try again.";
    return input + " == 24.  Congratulations!";
};

// I/O below.

while (true) {
    var numbers = [1, 2, 3, 4].map(function() {
        return Math.floor(Math.random() * 8 + 1);
    });

    var input = prompt(
        "Your numbers are:\n" + numbers.join(" ") +
        "\nEnter expression. (use only + - * / and parens).\n", +"'x' to exit.", "");

    if (input === 'x') {
        break;
    }
    alert(twentyfour(numbers, input));
}
