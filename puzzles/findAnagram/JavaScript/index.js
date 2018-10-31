const anagrams = require('./anagrams')
var target;
if (process.argv.length == 2) {
  target = "listen";
}
else if (process.argv.length == 3) {
   target = process.argv[2];
}
else {
  console.log("Usage node index.js <word>");
}

anagrams.getAnagrams(target, function (err, results) {
  console.log("Finding anagrams for "+target);
  console.log(results);
  console.log(target + ' has ' + results.length + ' subanagrams. ' + results.join(', '));
});

