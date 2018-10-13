'use strict'

// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const Dictonary = require('./juan-carlos-correa-dictonary');

describe("Test juan-carlos-correa Dictonary", () => {

  it("Add new key - value to Dictonary", function() {
    const dictonary = new Dictonary()
    const key = 'test'
    const value = 'foo'

    dictonary.add(key, value)

    expect(dictonary.find(key)).toEqual(value)
  });

  it("Remove key - value to Dictonary", function() {
    const dictonary = new Dictonary()
    const key = 'test'
    const value = 'foo'

    dictonary.add(key, value)

    expect(dictonary.find(key)).toEqual(value)

    dictonary.remove(key)

    expect(dictonary.find(key)).not.toEqual(value)
  });
});