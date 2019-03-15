const isSpace = c => c === ' '
const isEmptyStr = str => str === ''
function urlify(str) {
  let ret = ''
  let isStillSpace = false
  for (let i = str.length - 1; i >= 0; i--) {
    const c = str[i]
    const prevCharIsSpace = isStillSpace
    isStillSpace = isSpace(c)
    const shouldIncludeSpaceReplacementChar = (
      !isStillSpace &&
      prevCharIsSpace &&
      !isEmptyStr(ret)
    )
    if (isStillSpace) continue
    if (shouldIncludeSpaceReplacementChar) ret = '%20' + ret
    ret = c + ret
  }
  return ret
}

module.exports = urlify
