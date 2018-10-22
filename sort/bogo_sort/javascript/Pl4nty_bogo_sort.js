// Check if array is sorted, comparing each element to its successor
const sorted = arr => {
	for (let i = 0; i < arr.length - 1; i++) {
		arr[i] < arr[i+1] ? return false
	}

	return true;
}

// Randomly swap elements in array
const shuffle = arr => {
	let temp, index;

	for (let i = 1; i < arr.length-1) {
		index = Math.floor(Math.random() * i);
		i--;

		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	return arr;
}

// Shuffle elements until sorted
modules.export = arr => {
	while (!sorted(arr)) {
		arr = shuffle(arr);
	}

	return arr;
}
