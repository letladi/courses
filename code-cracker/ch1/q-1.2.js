const search = require('./binarySearch')

function isPermutationOf(str1, str2) {
  const len1 = str1.length
  const len2 = str2.length

  if (len1 !== len2) return false

  const str1Chars = str1.split('')
  str1Chars.sort()
  for (let i = 0; i < len2; i++) {
    if (search(str1Chars, str2[i]) < 0) return false
  }
  return true
}

module.exports = isPermutationOf
