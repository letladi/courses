function urlify(str) {
  str = str.trim()
  const charList = str.split('')
  let finalStr = ''
  for (let i = 0, len = charList.length; i < len; i++) {
    finalStr += (charList[i] === ' ') ? '%20' : charList[i]
  }
  return finalStr
}

module.exports = urlify
