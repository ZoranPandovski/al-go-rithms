// Given an input string, permuteString will log all possible permutations of that string.

const swapCharacters = (string, i, j) => {
	let temp = '';
	let characterArray = string.split('');
	temp = characterArray[i];
	characterArray[i] = characterArray[j];
	characterArray[j] = temp;
	return characterArray.join('');
};

const permuteString = (string, startIndex, endIndex) => {
	if (startIndex == endIndex) {
		console.log(string);
		return;
	} else {
		for (let i = startIndex; i <= endIndex; i++) {
			string = swapCharacters(string, startIndex, i);
			permuteString(string, startIndex + 1, endIndex);
			string = swapCharacters(string, startIndex, i);
		}
	}
};

// Example
const exampleString = 'abc';
return console.log(permuteString(exampleString, 0, exampleString.length - 1));