const anagram = (word1, word2) => (sortWord(word1) !== sortWord(word2)) ? false:true;

let sortWord = text => text.split('').sort().join('');

console.log(anagram('sfd!A$','$A!dfs'));
