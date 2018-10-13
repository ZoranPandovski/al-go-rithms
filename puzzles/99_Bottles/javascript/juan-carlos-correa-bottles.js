'use strict'

class Bottles {
  constructor (number = 99) {
    this.number = number
  }

  execOne () {
    if (this.number) {
      return this.takeOne()
    }

    return this.lastVerse()
  }

  takeOne () {
    let verseOne = `${this.number} bottles of beer on the wall, ${this.number} bottles of beer.`
    --this.number
    let verseTwo = `Take one down and pass it around, ${this.number} bottles of beer on the wall.`
    return `${verseOne} \ ${verseTwo}`
  }

  lastVerse () {
    return `No more bottles of beer on the wall, no more bottles of beer. \ Go to the store and buy some more, 99 bottles of beer on the wall.`
  }
}

module.exports = Bottles
