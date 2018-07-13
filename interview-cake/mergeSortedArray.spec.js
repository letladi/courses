const mergeArrays = require('./mergeSortedArray')

describe('mergeArrays', () => {
  let list1 = null,
  list2 = null,
  mergedArry = null,
  expectedMergedArray = null
  beforeEach(() => {
    list1 = [3, 4, 6, 10, 11, 15]
    list2 = [1, 5, 8, 12, 14, 19]
    expectedMergedArray = [1, 3, 4, 5, 6, 8, 10, 11, 12, 14, 15, 19]
    mergedArry = mergeArrays(list1, list2)

  })
  test('the merged list should equal the sum of lengths of the given lists', () => {
    expect(expectedMergedArray).toEqual(mergedArry)
  })
  test('should merge two sorted arrays', () => {
    const mergedArry = mergeArrays(list1, list2)
    expect(mergedArry.length).toEqual(list1.length + list2.length)
  })
})
