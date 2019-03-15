function sortString(str) {
  return Array.from(str).sort().join('')
}

function isPermutationOf(str1, str2) {
  return sortString(str1) === sortString(str2)
}
