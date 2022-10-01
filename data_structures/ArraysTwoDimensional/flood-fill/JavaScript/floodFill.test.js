const floodFill = require("./floodFill");

describe("FloodFill", () => {
	const TARGET_VALUE = 0;
	const REPLACEMENT_VALUE = 7;
	let mockArray;

	beforeEach(() => {
		mockArray = [
			[0, 0, 0, 1, 2, 0, 0, 0, 0, 0],
			[0, 0, 0, 1, 2, 0, 0, 0, 0, 0],
			[1, 1, 1, 0, 2, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
			[2, 2, 2, 2, 0, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 2, 2, 2, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
		];
	});

	test("fill valid area", () => {
		const expected = [
			[7, 7, 7, 1, 2, 0, 0, 0, 0, 0],
			[7, 7, 7, 1, 2, 0, 0, 0, 0, 0],
			[1, 1, 1, 0, 2, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
			[2, 2, 2, 2, 0, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 2, 2, 2, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
		];
		const startingCoords = { x: 0, y: 0 };

		expect(
			floodFill(mockArray, TARGET_VALUE, REPLACEMENT_VALUE, startingCoords)
		).toEqual(expected);

		const expectedSecondTour = [
			[7, 7, 7, 1, 2, 7, 7, 7, 7, 7],
			[7, 7, 7, 1, 2, 7, 7, 7, 7, 7],
			[1, 1, 1, 0, 2, 7, 7, 7, 7, 7],
			[0, 0, 0, 2, 7, 7, 7, 7, 7, 7],
			[2, 2, 2, 2, 7, 7, 7, 7, 7, 7],
			[0, 0, 0, 2, 7, 7, 7, 7, 7, 7],
			[0, 0, 0, 2, 2, 2, 2, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
		];
		const startingCoordsSecondTour = { x: 7, y: 2 };

		expect(
			floodFill(
				mockArray,
				TARGET_VALUE,
				REPLACEMENT_VALUE,
				startingCoordsSecondTour
			)
		).toEqual(expectedSecondTour);
	});

	test("fill on single value area", () => {
		const expected = [
			[0, 0, 0, 1, 2, 0, 0, 0, 0, 0],
			[0, 0, 0, 1, 2, 0, 0, 0, 0, 0],
			[1, 1, 1, 7, 2, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
			[2, 2, 2, 2, 0, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 2, 2, 2, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
		];
		const startingCoords = { x: 3, y: 2 };

		expect(
			floodFill(mockArray, TARGET_VALUE, REPLACEMENT_VALUE, startingCoords)
		).toEqual(expected);
	});

	test("fill invalid area", () => {
		const expected = [
			[0, 0, 0, 1, 2, 0, 0, 0, 0, 0],
			[0, 0, 0, 1, 2, 0, 0, 0, 0, 0],
			[1, 1, 1, 0, 2, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
			[2, 2, 2, 2, 0, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 0, 0, 0, 0, 0, 0],
			[0, 0, 0, 2, 2, 2, 2, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
			[0, 0, 0, 0, 0, 0, 0, 2, 2, 2],
		];
		const startingCoords = { x: 8, y: 8 };

		expect(
			floodFill(mockArray, TARGET_VALUE, REPLACEMENT_VALUE, startingCoords)
		).toEqual(expected);
	});

	test("Initial coord is out of bounds", () => {
		const startingCoords = { x: -10, y: -8 };

		expect(() =>
			floodFill(mockArray, TARGET_VALUE, REPLACEMENT_VALUE, startingCoords)
		).toThrow(RangeError);
	});

	test("Array is null", () => {
		const startingCoords = { x: 0, y: 0 };

		expect(() =>
			floodFill(null, TARGET_VALUE, REPLACEMENT_VALUE, startingCoords)
		).toThrow(TypeError);
	});
});
