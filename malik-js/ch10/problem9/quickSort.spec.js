const fs = require('fs')
const path = require('path')
const sort = require('./quickSort')
const words = readDataFromFile('./words.txt')
const sortedWords = readDataFromFile('./sortedWords.txt')

describe('problem-9', () => {
  test('test quickSort for problem 9', () => {
    sort(words)
    expect(words).toEqual(sortedWords)
  })
})

function readDataFromFile(fileName) {
  const data = fs.readFileSync(path.resolve(__dirname, fileName), 'utf8')
  if (data) return data.trim().split('\n')
  else throw new Error('reading file data')
}
