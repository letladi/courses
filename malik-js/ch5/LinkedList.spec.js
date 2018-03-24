const LinkedList = require('./LinkedList')

describe('LinkedList Iterator', () => {
    list = new LinkedList()
    list.insertLast(1)
    list.insertLast(2)
    list.insertLast(3)

    test('should iterate the list elements', () => {
        const iterator = list.iterator()
        expect(iterator.next()).toEqual({ value: 1, done: false })
        expect(iterator.next()).toEqual({ value: 2, done: false })
        expect(iterator.next()).toEqual({ value: 3, done: false })
        expect(iterator.next()).toEqual({ done: true })
    })
})

describe('UnorderedLinkedList', () => {
    let list = null
    beforeEach(() => list = new LinkedList())
    afterEach(() => list = null)

    describe('#insertFirst', () => {
        test('inserts element in front of the list', () => {
            list.insertFirst(10)
            list.insertFirst(20)
            expect(list.front).toEqual(20)
        })
    })

    describe('#insertLast', () => {
        test('inserts element in the back of the list', () => {
            list.insertLast(10)
            list.insertLast(20)
            expect(list.back).toEqual(20)
        })
    })

    describe('#isEmpty', () => {
        test('returns true if empty', () => {
            expect(list.isEmpty()).toEqual(true)
        })
        test('returns false if not empty', () => {
            list.insertLast(22)
            expect(list.isEmpty()).toEqual(false)
        })
    })
    describe('.length', () => {
        test('returns the length of the list', () => {
            expect(list.length).toEqual(0)
            list.insertLast(10)
            expect(list.length).toEqual(1)
            list.insertFirst(22)
            expect(list.length).toEqual(2)
        })
    })

    describe('.front', () => {
        test('returns the first element', () => {
            list.insertFirst(1)
            list.insertFirst(2)
            expect(list.front).toEqual(2)
        })
        test('throws exception if list is empty', () => {
            expect(() => list.front).toThrow(Error)
        })
    })

    describe('.back', () => {
        test('returns the last element', () => {
            list.insertLast(1)
            list.insertLast(2)
            expect(list.back).toEqual(2)
        })
        test('throws exception if list is empty', () => {
            expect(() => list.back).toThrow(Error)
        })
    })

    describe('#each', () => {
        test('should iterate over each element in the list', () => {
            const nums = [1, 2, 3, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            let count = 0
            list.each((el, i) => {
                expect(el).toEqual(nums[count])
                expect(i).toEqual(count)
                count++
            })
        })
    })

    describe('#entries', () => {
        test('should return an array containing all list elements', () => {
            const nums = [1, 2, 3, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            expect(list.entries()).toEqual(nums)
        })
    })

    describe('#search', () => {
        test('returns true if element is in list', () => {
            const nums = [1, 2, 3, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            expect(list.search(4)).toEqual(true)
        })
        test('returns false if element if not in list', () => {
            const nums = [1, 2, 3, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            expect(list.search(44)).toEqual(false)
        })
    })

    describe('#destroy', () => {
        test('resets list to initial state', () => {
            const nums = [1, 2, 3, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            list.destroy();
            expect(list.isEmpty()).toEqual(true)
        })
    })

    describe('#delete', () => {
        test('should remove element from the list', () => {
            const nums = [1, 2, 3, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            expect(list.search(3)).toEqual(true)
            list.delete(3)
            expect(list.search(3)).toEqual(false)
        })
        test('should return true if element was deleted', () => {
            list.insertFirst(1)
            expect(list.delete(1)).toEqual(true)
        })
        test('should return false if element was not deleted', () => {
            list.insertFirst(1)
            expect(list.delete(11)).toEqual(false)
        })
    })
})
