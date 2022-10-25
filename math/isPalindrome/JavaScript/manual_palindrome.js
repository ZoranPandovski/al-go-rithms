const isPalindrome = (value) =>{
    let stringValue = value.toString();

    let leftPointer = 0;
    let rightPointer = stringValue.length-1

    while (leftPointer<rightPointer){
        if (stringValue[leftPointer]!==stringValue[rightPointer]){
            return false;
        }
        leftPointer++;
        rightPointer--;
    }
    return true;
}