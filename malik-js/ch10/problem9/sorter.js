const readline = require('linebyline')
const fs = require('fs')
rl = readline('./words.txt')

const wordList = []
let i = 0

rl.on('line', (line, lineCount, byteCount) => {
  wordList[i++] = line
})



rl.on('error', (e) => {
  console.log('an error occurred while reading "words.txt"')
})

rl.on('end', () => {
  wordList.sort()
  fs.writeFileSync('./sortedWords.txt', wordList.join('\n'))
})
