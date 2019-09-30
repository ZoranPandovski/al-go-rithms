const isAnagram = (word1, word2) => {
    if (!word1 || !word2) return false
    if (word1.length !== word2.length) return false

    word1 = word1.toLowerCase().split('').sort()
    word2 = word2.toLowerCase().split('').sort()
    for (let i=0; i < word1.length; i++){
      if (word1[i] !== word2[i]) return false
    }
    return true
}