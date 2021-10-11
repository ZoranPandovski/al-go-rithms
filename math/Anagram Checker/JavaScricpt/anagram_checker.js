function orderLetters(word) {
  //change all letters to lowercase to address case sensitiveness
  //order all the letters and trim to address space problems 
  return word.toLowerCase().split('').sort().join('').trim();
}

function isAnagram(word1, word2) {

  //if ordered letters are equal on both words, there is your anagram!
  if (orderLetters(word1) == orderLetters(word2)) {
    return true;
  }
  else {
    return false;
  }
}

//making tests

console.log(isAnagram("listen","silent"));
//true

console.log(isAnagram("Dormitory","Dirty Room"));
//true

console.log(isAnagram("Room","Rome"));
//false

console.log(isAnagram("Aa","aa"));
//true

console.log(isAnagram("Aaaaaaaa","aa"));
//false
