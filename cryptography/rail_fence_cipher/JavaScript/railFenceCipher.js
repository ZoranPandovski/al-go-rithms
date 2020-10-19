const railFenceCipher = {
    encrypt: (string, key) => {
        let isDirectionDown = true;
        let currentRow = 0;

        const splitString = string.split("");
        const result = [];

        for (let i = 0; i < key; i++) {
            result.push([]);
        }
        splitString.forEach((char) => {
            result[currentRow].push(char);
            currentRow += isDirectionDown ? 1 : -1;
            if (currentRow === key - 1) isDirectionDown = false;
            if (currentRow === 0) isDirectionDown = true;
        });
        return result
            .flatMap((char) => char)
            .reduce((accumulator, currentValue) => accumulator + currentValue);
    },
    decrypt: (string, key) => {
        let isDirectionDown = true;
        let currentRow = 0;

        const result = [];

        for (let i = 0; i < string.length; i++) {
            result.push(currentRow);
            currentRow += isDirectionDown ? 1 : -1;
            if (currentRow === key - 1) isDirectionDown = false;
            if (currentRow === 0) isDirectionDown = true;
        }
        currentRow = 0;
        for (let i = 0; i < string.length; i++) {
            let position = result.indexOf(currentRow);
            if (position < 0) {
                currentRow++;
                position = result.indexOf(currentRow);
            }
            result[position] = string[i];
        }
        return result.join("");
    },
};

module.exports = railFenceCipher;
