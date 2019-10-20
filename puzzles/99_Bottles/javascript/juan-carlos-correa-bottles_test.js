'use strict'

// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const Bottles = require('./juan-carlos-correa-bottles')

describe("Test juan-carlos-correa-bottles", () => {
  it("Check 99 bottles lyric", () => {
    let number = 99
    const bottles = new Bottles(number)

    expect(bottles.number).toEqual(number)

    while (number !== 0) {
      let verseOne = `${number} bottles of beer on the wall, ${number} bottles of beer.`
      number--
      let verseTwo = `Take one down and pass it around, ${number} bottles of beer on the wall.`

      expect(bottles.execOne()).toEqual(`${verseOne} \ ${verseTwo}`
      )
    }

    let lastVerse = `No more bottles of beer on the wall, no more bottles of beer. \ Go to the store and buy some more, 99 bottles of beer on the wall.`
    expect(bottles.execOne()).toEqual(lastVerse)
  })
})
