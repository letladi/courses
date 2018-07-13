const reverseWords = require('./reverse-words')

describe('reverseWords', () => {
  test('case 1', () => {
    const message = [ 'c', 'a', 'k', 'e', ' ',
              'p', 'o', 'u', 'n', 'd', ' ',
              's', 't', 'e', 'a', 'l' ]

    reverseWords(message)
    expect(message.join('')).toEqual('steal pound cake')
  })
  test('should not change length of array', () => {
    const message = [ 'c', 'a', 'k', 'e', ' ',
              'p', 'o', 'u', 'n', 'd', ' ',
              's', 't', 'e', 'a', 'l' ]

    const initLength = message.length
    reverseWords(message)
    expect(message.length).toEqual(initLength)
  })
})
