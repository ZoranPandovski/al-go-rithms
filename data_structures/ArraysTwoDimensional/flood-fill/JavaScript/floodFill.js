function floodFill(array, targetValue, replacementValue, initialCoord) {
	const arrayBoundaries = getArrayBoundaries(array);

	if (!isCoordInBoundaries(initialCoord, arrayBoundaries)) {
		throw new RangeError("Initial coord is out of array boundaries");
	}

	const queue = [initialCoord];

	while (!isEmpty(queue)) {
		const coord = queue[0];
		const { x, y } = coord;

		if (isFillable(array[y][x], targetValue)) {
			array[y][x] = replacementValue;
			floodAround(queue, coord, arrayBoundaries);
		}
		queue.shift();
	}

	return array;
}

function isEmpty(array) {
	return array.length === 0;
}

function isFillable(target, targetValue) {
	return target === targetValue;
}

function getArrayBoundaries(array) {
	const arrayBoundaries = {
		x: { min: 0, max: array[0].length },
		y: { min: 0, max: array.length },
	};

	return arrayBoundaries;
}

function getCoordsAround(coord) {
	const top = { x: coord.x, y: coord.y - 1 };
	const right = { x: coord.x + 1, y: coord.y };
	const bottom = { x: coord.x, y: coord.y + 1 };
	const left = { x: coord.x - 1, y: coord.y };

	return [top, right, bottom, left];
}

function isInRange(element, min, max) {
	return element >= min && element < max;
}

function isCoordInBoundaries(coord, arrayBoundaries) {
	const { x, y } = arrayBoundaries;

	return isInRange(coord.x, x.min, x.max) && isInRange(coord.y, y.min, y.max);
}

function isNotInQueue(queue, coord) {
	const findInQueue = queue.find(
		(element) => element.x === coord.x && element.y === coord.y
	);

	return findInQueue === undefined;
}

function floodAround(queue, initialCoord, arrayBoundaries) {
	const coordsAround = getCoordsAround(initialCoord);

	for (coord of coordsAround) {
		if (
			isCoordInBoundaries(coord, arrayBoundaries) &&
			isNotInQueue(queue, coord)
		) {
			queue.push(coord);
		}
	}
}

module.exports = floodFill;
