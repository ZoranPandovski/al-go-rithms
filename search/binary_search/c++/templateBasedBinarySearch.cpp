template<typename T>
int binarySearch(T array[], int numelems, T value)
{
	int first = 0, last = numelems - 1, middle, position = -1;
	bool found = false;
	while (!found && first <= last) {
		middle = (first + last) / 2; // Calculate mid point
		if (array[middle] == value) { // If value is found at mid
			found = true;
			position = middle;
		}
		else if (array[middle] > value) //If value is in lower half
			last = middle - 1;
		else
			first = middle + 1; // If value is in upper half
	}
	return position;
}
