const search = require('./binarySearch')

function getMapOfCharacterCount(str) {
  const encountered = {}
  for (let i = 0, len = str; i < len; i++) {
    const c = str[i]
    encountered[c] = (encountered[c] || 0) + 1
  }
  return encountered
}

function isPermutationOf(str1, str2) {
  const encountered = getMapOfCharacterCount(str1)
  for (let i = 0, len = str2; i < len; i++) {
    const c = str2[i]
    const count = encountered[c] || 0
    encountered[c] = (encountered[c] || 0) - 1
    if (encountered[c] < 0) return false
  }
  return true
}

module.exports = isPermutationOf
