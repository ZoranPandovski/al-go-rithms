const bubbleSort = require('./Pl4nty_bubble_sort');

describe("ES2018 Bubble Sort", () => {
	[
		[5, 4, 3, 2, 1],
		[1, 2, 3, 4, 5, 6],
		[2, 5, 1, 3, 7, 6, 4]
	].forEach(unsorted => {
		it(`sorts an array of ${unsorted.length} elements`, () => {
			const sorted = unsorted.slice();
			sorted.sort((a,b) => a-b);

			const start = Date.now();
			const result = bubbleSort(unsorted);
			console.log(`Bubble sort on ${unsorted.length} elements took ${(Date.now()-start)}ms`);
			console.log(result);
			expect(result).toEqual(sorted);
		});
	});

	it(`Sorts an array of 500 random elements`, () => {
		const unsorted = [];
		for (let i = 0; i < 100; i++) {
			unsorted.push(Math.floor(Math.random()*100));
		}
		const sorted = unsorted.slice();
		sorted.sort((a,b) => a-b);

		const start = Date.now();
		const result = bubbleSort(unsorted);
		console.log(`Bubble sort on ${unsorted.length} elements took ${(Date.now()-start)}ms`);

		expect(result).toEqual(sorted);
	});

});
