const isIsogram = (word) => {
    if (word.length === 0) return true
    word = word.toLowerCase()
    let letters = {}
    for (let i = 0; i < word.length; i++) {
      if (!letters[word[i]]) {
        letters[word[i]] = 1 
      }
      else return false
    }
    return true
  }