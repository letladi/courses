const reverse = require('./in-place-string-reverse')

describe('reverse', () => {
  test('case 1', () => {
    const chList = 'letladi'.split('')
    reverse(chList)
    expect(chList).toEqual('idaltel'.split(''))
  })
  test('case 2', () => {
    const chList = 'sebesho'.split('')
    reverse(chList)
    expect(chList).toEqual('ohsebes'.split(''))
  })
  test('case 3', () => {
    const chList = ''.split('')
    reverse(chList)
    expect(chList).toEqual(''.split(''))
  })
  test('case 4', () => {
    const chList = 'at'.split('')
    reverse(chList)
    expect(chList).toEqual('ta'.split(''))
  })
})
