const ReverseJS = (oldArray) => {
  let initPosition = 0
  let lastPosition = oldArray.length - 1
  let newArray = []
  while (lastPosition >= 0) {
    newArray[initPosition] = oldArray[lastPosition]
    initPosition++
    lastPosition--
  }
  return newArray
}

module.exports.ReverseJS = ReverseJS;