var HammingDistance = {
  bit: function(x, y) {
    if(x.length != y.length)
      throw "Strings are not at equal length"
    var dist = 0
    for(var i = 0; i < x.length; i++) {
      dist += x.charCodeAt(i) ^ y.charCodeAt(i)
    }
    return dist
  },
  char: function(x, y) {
    if(x.length != y.length)
      throw "Strings are not at equal length"
    var dist = 0
    for(var i = 0; i < x.length; i++) {
      if(x[i] != y[i])
        dist += 1;
    }
    return dist
  }
}
