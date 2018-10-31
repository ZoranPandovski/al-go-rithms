// Main function

function toBinary (input) {
    input = parseInt(input); // Input gets parsed (converts strings into numbers)
    if (Number.isInteger(input)) { // Checks if input is an integer
        return input.toString(2); // Resulting binary gets returned as a string
    }
}

// Converts a decimal integer into binary