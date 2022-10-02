//Bubble sort
const bubbleSort = (arr) => {
	//Length of the array
	let n = arr.length;
  
	for (let i = 0; i < n - 1; i++) {
	  for (let j = 0; j <= n - i - 1; j++) {
		//Swap the numbers
		if (arr[j] > arr[j + 1]) {
		  [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
		}
	  }
	}
  
	return arr;
  };
  
  // Usage
  console.log(bubbleSort([10, 9, -1, -2, 0, 22]));