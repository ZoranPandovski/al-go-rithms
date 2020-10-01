// Code modified to work locally from https://github.com/evanchiu/alexa-anagram
const fs = require('fs');
const path = require('path');

exports.getAnagrams = function(target, callback) {
  getDictionary(function(err, dictionary) {
    if (err) {
      callback(err);
    } else {
      targetCountHash = getLetterCountHash(target);
      subanagrams = [];
      for (let i = 0; i < dictionary.length; i++) {
        if (isSubanagram(targetCountHash, getLetterCountHash(dictionary[i]))) {
          subanagrams.push(dictionary[i]);
        }
      }
      callback(null, subanagrams);
    }
  });
};

function getDictionary(callback) {
  let dictionaryFile = path.join(__dirname, 'data', '6of12.txt');
//  console.log(dictionaryFile);
  fs.readFile(dictionaryFile, function(err, data) {
    if (err) {
      callback(err);
    } else {
      callback(null, data.toString().split('\n'));
    }
  });
}

function isSubanagram(base, candidate) {
  for (let letter in candidate) {
    if (!base[letter] || base[letter] < candidate[letter]) {
      return false;
    }
  }
  return true;
}

function getLetterCountHash(word) {
  let letters = word.split('');
  let countHash = {};
  for (let i = 0; i < letters.length; i++) {
    if (countHash[letters[i]]) {
      countHash[letters[i]] += 1;
    } else {
      countHash[letters[i]] = 1;
    }
  }
  return countHash;
}

