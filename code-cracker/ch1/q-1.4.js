function buildCharFrequencyTable(str) {
  const ret = {}
  for (let i = 0, len = str.length; i < len; i++) {
    const c = str[i]
    ret[c] = (ret[c] || 0) + 1
  }
  return ret
}

const isOdd = x => x % 2 === 1

const charactersWithOddCount(charTable) {
  const count = 0
  for (const c in charTable) {
    if (isOdd(charTable[c])) count++
  }
  return count
}

function isPermutationOfPalindrome(str) {
  const table = buildCharFrequencyTable(str)
  return charactersWithOddCount(table) <= 1
}
