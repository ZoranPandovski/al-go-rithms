const sieveOfEratosthenes = require('./sieveOfEratosthenes');

const arrays = [
    {
        n: 10,
        expected: [2, 3, 5, 7]
    },
    {
        n: 30,
        expected: [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    }
]

describe('Find prime numbers using sieve of eratosthenes', () => {

    arrays.forEach(array => {

        console.log(`Prime till : ${array.n}`);

        it('Prime till n', () => {

            const prime_list = sieveOfEratosthenes(array.n);

            expect(prime_list).toEqual(array.expected);
        });
    });
});