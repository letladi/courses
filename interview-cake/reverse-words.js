const reverseCharList = require('./in-place-string-reverse')

const reverseWords = chList => {
  reverseCharList(chList)
  let index = 0
  for (let i = 0, len = chList.length; i <= len; i++) {
    if (i === len || chList[i] === ' ') {
      reverseCharList(chList, index, i - 1)
      index = i + 1
    }
  }
}

module.exports = reverseWords
