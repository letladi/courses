const kThSmallestItem = require('./kThSmallestItem')

describe('kThSmallestItem', () => {
  describe('for array: [34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66]', () => {
    const array = [34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66]
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 0) = 5', () => {
      expect(kThSmallestItem(array, 0)).toEqual(5)
    })
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 1) = 12', () => {
      expect(kThSmallestItem(array, 1)).toEqual(12)
    })
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 2) = 23', () => {
      expect(kThSmallestItem(array, 2)).toEqual(23)
    })
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 3) = 32', () => {
      expect(kThSmallestItem(array, 3)).toEqual(32)
    })
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 4) = 34', () => {
      expect(kThSmallestItem(array, 4)).toEqual(34)
    })
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 5) = 36', () => {
      expect(kThSmallestItem(array, 5)).toEqual(36)
    })
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 6) = 56', () => {
      expect(kThSmallestItem(array, 6)).toEqual(56)
    })
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 7) = 66', () => {
      expect(kThSmallestItem(array, 7)).toEqual(66)
    })
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 8) = 67', () => {
      expect(kThSmallestItem(array, 8)).toEqual(67)
    })
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 9) = 78', () => {
      expect(kThSmallestItem(array, 9)).toEqual(78)
    })
    test('kThSmallestItem([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 10) = 79', () => {
      expect(kThSmallestItem(array, 10)).toEqual(79)
    })
  })
})
