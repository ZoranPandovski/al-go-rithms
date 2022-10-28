//You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.
//Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

class FindSmallestLetterGreaterThanTarget {
    public char nextGreatestLetter(char[] letters, char target) {
        int start = 0; //starting index of an array
        int end = letters.length-1; //ending index of an array
        while(start <= end){ //if start is less than or equal to end
             int mid = start + (end - start)/2; //find middle index so it becomes easy to find target element.
            if(target < letters[mid]){ //if tareget is less than middle elemant than we will find in left side of array
                end = mid - 1;
            }else{ //if tareget is greater than middle elemant than we will find in right side of array
                start = mid + 1;
            }
        } 
        return letters[start % letters.length];      
    }
}
