function hasAllUniqueCharacters(str) {
  const encountered = {}
  for (let i = 0, len = str.length; i < len; i++) {
    const c = str[i]
    if (encountered[c]) return false
    encountered[c] = true
  }
  return true
}

module.exports = hasAllUniqueCharacters
