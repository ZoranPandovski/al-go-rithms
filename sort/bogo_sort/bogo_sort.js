function check(arr) {
	for (var i = arr.length - 1; i >= 0; i--) {
		if (arr[i - 1] > arr[i]) {
			return false;
		}
	}

	return true;
}

function shuffle(arr) {
	var temp, index;

	for (var i = arr.length; i > 0;) {
		index = Math.floor(Math.random() * i);
		i--;

		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	return arr;
}

function bogoSort(arr) {
	var sorted = check(arr);

	while (!sorted) {
		arr = shuffle(arr);
		sorted = check(arr);
	}

	return arr;
}
