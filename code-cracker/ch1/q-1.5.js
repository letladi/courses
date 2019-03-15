function lengthDifference(str1, str2) {
  return Math.abs(str1.length - str2.length)
}

function isEditOf(str1, str2) {
  if (lengthDifference(str1, str2) > 1) return false

  let differenceCount = 0
  for (let i = 0, len = str1.length; i < len; i++) {
    const c1 = str1[i]
    const c2 = str2[i]
    if (c1 === c2) continue
    else differenceCount++
    if (differenceCount > 1) return false
  }
  return true
}
