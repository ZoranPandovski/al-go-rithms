const isPalindrome = (str) => {
    str = str.trim();
    if (str === "") { return false; }
    return (str === str.split('').reverse().join(''));
} 