'use strict'

class Dictonary {
  constructor () {
    this.dataStore = []
  }

  add (key, value) {
    this.dataStore[key] = value
  }

  find (key) {
    return this.dataStore[key]
  }

  remove (key) {
    delete this.dataStore[key]
  }
}

module.exports = Dictonary