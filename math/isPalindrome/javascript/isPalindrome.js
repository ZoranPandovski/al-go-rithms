const isPalindrome = (str) => {
  let lowRegStr = str.toLowerCase().replace(/[\W_]/gi, '')
  const reverseStr = lowRegStr.split('').reverse().join('')
  return reverseStr === lowRegStr
}