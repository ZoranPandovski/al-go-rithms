const railFenceCipher = require("./railFenceCipher");

class TestCase {
    constructor(rawString, encryptedString, key) {
        this.rawString = rawString;
        this.encryptedString = encryptedString;
        this.key = key;
    }
}

describe("rail fence cipher", () => {
    const { encrypt, decrypt } = railFenceCipher;
    const testCases = [
        new TestCase(
            "WE ARE DISCOVERED FLEE AT ONCE",
            "WRIVDETCEAEDSOEE LEA NE  CRF O",
            3
        ),
        new TestCase("DEFEND THE EAST WALL", "D ALEDTESALFNH TWEE ", 4),
        new TestCase(
            "THEY ARE ATTACKING FROM THE NORTH",
            "T NTHHEAIG HTERTK MERYATCFO O ARN",
            5
        ),
    ];

    testCases.forEach((testCase) => {
        it(`encrypts '${testCase.rawString}' `, () => {
            expect(encrypt(testCase.rawString, testCase.key)).toEqual(
                testCase.encryptedString
            );
        });
    });

    testCases.forEach((testCase) => {
        it(`decrypts '${testCase.encryptedString}' `, () => {
            expect(decrypt(testCase.encryptedString, testCase.key)).toEqual(
                testCase.rawString
            );
        });
    });
});
