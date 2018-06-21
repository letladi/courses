  const sort = require('./quickSort')

describe('quickSort', () => {
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
    test('should be able to sort objects given a compare function', () => {
      const list = [{ name: 'Kim', age: 39 }, { name: 'Beyonce', age: 35 }, { name: 'Adele', age: 25 }, { name: 'Kanye', age: '42' }]
      sort(list, (a, b) => (a.name < b.name) ? -1 : 1)
      expect(list).toEqual([{ name: 'Adele', age: 25 }, { name: 'Beyonce', age: 35 }, { name: 'Kanye', age: '42' }, { name: 'Kim', age: 39 }])
    })
    test('should sort primitives according to the sort function', () => {
      const list = [10, 18, 25, 30, 23, 17, 45, 35]
      sort(list, (a, b) => (a < b) ? 1 : -1)
      expect(list).toEqual([45, 35, 30, 25, 23, 18, 17, 10])
    })
})
