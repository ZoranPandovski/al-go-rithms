function encrypt (text) {
  const { width, height } = determineGridSize(text)
  let characters = text.split('')
  const grid = new Array(height)
  let isGoingUp = true
  for (let column = width - 1; column >= 0; column--) {
    const startingRow = isGoingUp ? height - 1 : 0
    const increment = isGoingUp ? -1 : 1
    for (let row = startingRow; row >= 0 && row < height; row += increment) {
      grid[row] = grid[row] || new Array(width)
      grid[row][column] = characters.length ? characters.shift() : ' '
    }
    isGoingUp = !isGoingUp
  }
  return grid.map(row => row.join('')).join('\r\n')
}

function decrypt (text) {
  const grid = text.split('\r\n').map(row => row.split(''))
  const height = grid.length
  const width = grid[0].length
  let characters = ''
  let isGoingUp = true
  for (let column = width - 1; column >= 0; column--) {
    const startingRow = isGoingUp ? height - 1 : 0
    const increment = isGoingUp ? -1 : 1
    for (let row = startingRow; row >= 0 && row < height; row += increment) {
      characters += grid[row][column]
    }
    isGoingUp = !isGoingUp
  }
  return characters.trim()
}

function determineGridSize (text) {
  const height = Math.floor(Math.sqrt(text.length))
  let width = Math.ceil(Math.sqrt(text.length))
  while (width * height < text.length) {
    width++
  }
  return { width, height }
}

module.exports = { encrypt, decrypt }
