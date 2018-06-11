const sort = require('./insertionSort')

describe('insertionSort', () => {
    test('sort([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66]) = [5, 12, 23, 32, 34, 36, 56, 66, 67, 78, 79]', () => {
        const list = [34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66]
        sort(list)
        expect(list).toEqual([5, 12, 23, 32, 34, 36, 56, 66, 67, 78, 79])
    })
    test('sort([13, 7, 15, 8, 12, 30, 3, 20]) = [3, 7, 8, 12, 13, 15, 20, 30]', () => {
        const list = [13, 7, 15, 8, 12, 30, 3, 20]
        sort(list)
        expect(list).toEqual([3, 7, 8, 12, 13, 15, 20, 30])
    })
    test('sort([10, 18, 25, 30, 23, 17, 45, 35])', () => {
        const list = [10, 18, 25, 30, 23, 17, 45, 35]
        sort(list)
        expect(list).toEqual([10, 17, 18, 23, 25, 30, 35, 45])
    })

    describe('intervalInsertionSort', () => {
      test('sort([34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66], 2, 7) = [34, 67, 12, 23, 36, 56, 78, 79, 5, 32, 66', () => {
          const list = [34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66]
          sort(list, 2, 7)
          expect(list).toEqual([34, 67, 12, 23, 36, 56, 78, 79, 5, 32, 66])
      })
      test('sort([13, 7, 15, 8, 12, 30, 3, 20], 3) = [3, 7, 8, 12, 13, 15, 20, 30]', () => {
          const list = [13, 7, 15, 8, 12, 30, 3, 20]
          sort(list, 3)
          expect(list).toEqual([13, 7, 15, 3, 8, 12, 20, 30])
      })
      test('sort([10, 18, 25, 30, 23, 17, 45, 35], 0) = [10, 17, 18, 23, 25, 30, 35, 45]', () => {
          const list = [10, 18, 25, 30, 23, 17, 45, 35]
          sort(list, 0)
          expect(list).toEqual([10, 17, 18, 23, 25, 30, 35, 45])
      })
      test('sort([10, 18, 25, 30, 23, 17, 45, 35], 5, 2) = 🙅‍ (interval must be valid)', () => {
          const list = [10, 18, 25, 30, 23, 17, 45, 35]
          expect(() => sort(list, 5, 2)).toThrow()
      })
      test('sort([10, 18, 25, 30, 23, 17, 45, 35], -5) = [10, 17, 18, 23, 25, 30, 35, 45] (negative opening value goes to beginning of the list)', () => {
        const list = [10, 18, 25, 30, 23, 17, 45, 35]
        sort(list, -5)
        expect(list).toEqual([10, 17, 18, 23, 25, 30, 35, 45])
      })
      test('sort([13, 7, 15, 8, 12, 30, 3, 20], 3, 20) = [3, 7, 8, 12, 13, 15, 20, 30]  (values greater than the length of the list go to the end of the list)', () => {
          const list = [13, 7, 15, 8, 12, 30, 3, 20]
          sort(list, 3, 20)
          expect(list).toEqual([13, 7, 15, 3, 8, 12, 20, 30])
      })
    })
})
