const LucasSeries = require('./LucasSeries');

const arrays = [
    {
        n: 10,
        expected: [2, 1, 3, 4, 7, 11, 18, 29, 47, 76, 123]
    }
]

describe('Find lucas series', () => {

    arrays.forEach(array => {

        console.log(`First ${array.n} lucas numbers`);

        it('First n lucas numbers', () => {

            const lucas_series_list = LucasSeries(array.n);

            expect(lucas_series_list).toEqual(array.expected);
        });
    });
});