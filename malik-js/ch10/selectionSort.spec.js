const sort = require('./selectionSort')
const LinkedList = require('../ch5/LinkedList')

describe('selectionSort', () => {
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
    test('sort([10, 18, 25, 30, 23, 17, 45, 35]) = [10, 17, 18, 23, 25, 30, 35, 45]', () => {
        const list = [10, 18, 25, 30, 23, 17, 45, 35]
        sort(list)
        expect(list).toEqual([10, 17, 18, 23, 25, 30, 35, 45])
    })

    describe('it should work for linked lists', () => {
      let list = null
      beforeEach(() => list = new LinkedList())
      afterEach(() => list = null)
      test('sort({ List: 34->67->23->12->78->56->36->79->5->32->66 }) = { List: 5->12->23->32->34->36->56->66->67->78->79 }', () => {
          const nums = [34, 67, 23, 12, 78, 56, 36, 79, 5, 32, 66]
          const sortedNums = [5, 12, 23, 32, 34, 36, 56, 66, 67, 78, 79]
          nums.forEach((el) => list.insertLast(el))
          expect(list.entries()).toEqual(nums)
          list.selectionSort()
          expect(list.entries()).toEqual(sortedNums)
      })
      test('sort({ List: 13->7->15->8->12->30->3->20}) = { List: 3->7->8->12->13->15->20->30 }', () => {
          const nums = [13, 7, 15, 8, 12, 30, 3, 20]
          const sortedNums = [3, 7, 8, 12, 13, 15, 20, 30]
          nums.forEach((el) => list.insertLast(el))
          expect(list.entries()).toEqual(nums)
          list.selectionSort()
          expect(list.entries()).toEqual(sortedNums)
      })
      test('sort({ List: 10->18->25->30->23->17->45->35 }) = { List: 10->17->18->23->25->30->35->45 }', () => {
          const nums = [10, 18, 25, 30, 23, 17, 45, 35]
          const sortedNums = [10, 17, 18, 23, 25, 30, 35, 45]
          nums.forEach((el) => list.insertLast(el))
          expect(list.entries()).toEqual(nums)
          list.selectionSort()
          expect(list.entries()).toEqual(sortedNums)
      })
    })
})
