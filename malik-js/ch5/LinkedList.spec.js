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
                expect(i).toEqual(count++)
            })
        })
    })

    // describe('#rEach', () => {
    //     test('should iterate over each element in the list in reverse', () => {
    //         const nums = [1, 2, 3, 4, 5]
    //         const rnums = [5, 4, 3, 2, 1]
    //         nums.forEach((el) => list.insertLast(el))
    //         let count = 4
    //         list.rEach((el, i) => {
    //             console.log('here is a cb: ', count)
    //             //expect(el).toEqual(rnums[count])
    //             expect(i).toEqual(count--)
    //         })
    //     })
    // })

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
        test('should properly re-assign first element', () => {
            const nums = [1, 2, 3, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            list.delete(1)
            expect(list.front).toEqual(2)
        })
        test('should properly re-assign last element', () => {
            const nums = [1, 2, 3, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            list.delete(5)
            expect(list.back).toEqual(4)
        })
        test('should return true if element was deleted', () => {
            list.insertFirst(1)
            expect(list.delete(1)).toEqual(true)
        })
        test('should return false if element was not deleted', () => {
            list.insertFirst(1)
            expect(list.delete(11)).toEqual(false)
        })
        test('should decrement the length if succeeded', () => {
            const nums = [1, 2, 3, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            expect(list.length).toEqual(5)
            list.delete(1)
            expect(list.length).toEqual(4)
        })
        test('should not decrement length if failed', () => {
            const nums = [1, 2, 3, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            expect(list.length).toEqual(5)
            list.delete(6)
            expect(list.length).toEqual(5)
        })
    })

    describe('#deleteMin', () => {
        test('should delete node with smallest info', () => {
            const nums = [1, 2, 3, 0, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            list.deleteMin()
            expect(list.search(0)).toEqual(false)
            expect(list.entries()).toEqual([1, 2, 3, 4, 5])
        })
        test('should delete element if it is the only one in the list', () => {
            list.insertLast(-1)
            list.deleteMin()
            expect(list.search(0)).toEqual(false)
            expect(list.entries()).toEqual([])
        })
        test('should delete only the first occurrence of the min value', () => {
            const nums = [1, 2, 0, 3, 0, 4, 5, 0]
            nums.forEach((el) => list.insertLast(el))
            list.deleteMin()
            expect(list.search(0)).toEqual(true)
            expect(list.entries()).toEqual([1, 2, 3, 0, 4, 5, 0])
        })
        test('should return true if deletion succeeded', () => {
            const nums = [1, 2, 3, 0, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            list.deleteMin()
            expect(list.deleteMin()).toEqual(true)
        })
        test('should properly re-assign first element', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0]
            nums.forEach((el) => list.insertLast(el))
            list.deleteMin()
            expect(list.front).toEqual(1)
        })
        test('should properly re-assing last element', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            list.deleteMin()
            expect(list.back).toEqual(0)
        })
        test('should return false if deletion failed (i.e, when list is empty)', () => {
            expect(list.deleteMin()).toEqual(false)
        })
        test('should decrement the length if succeeded', () => {
            const nums = [1, 2, 3, 0, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            expect(list.length).toEqual(6)
            list.deleteMin()
            expect(list.length).toEqual(5)
        })
        test('should not decrement length is failed', () => {
            expect(list.length).toEqual(0)
            list.deleteMin()
            expect(list.length).toEqual(0)
        })
    })
    describe('#deleteAll', () => {
        test('should delete all occurrences of a given info value', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            list.deleteAll(0)
            expect(list.search(0)).toEqual(false)
            expect(list.entries()).toEqual([-1, 1, 2, 3, 4, 5, -22])
        })
        test('should return true if deletion occurred', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            expect(list.deleteAll(0)).toEqual(true)
        })
        test('should return false if deletion failed (i.e, element was not in list)', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            expect(list.deleteAll(10)).toEqual(false)
        })
        test('should return false if deletion failed (i.e, list is empty)', () => {
            expect(list.deleteAll(10)).toEqual(false)
        })
        test('should properly re-assign first value', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            list.deleteAll(-1)
            expect(list.front).toEqual(1)
        })
        test('should properly re-assign last value', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            list.deleteAll(-22)
            expect(list.back).toEqual(0)
        })
        test('should re-assign first and last value if there are only two items in the list', () => {
            list.insertLast(1)
            list.insertLast(2)
            list.deleteAll(1)
            expect(list.front).toEqual(2)
            expect(list.back).toEqual(2)
        })
        test('should decrement the length if succeeded', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            expect(list.length).toEqual(10)
            list.deleteAll(0)
            expect(list.length).toEqual(7)
        })
        test('should not decrement length is failed', () => {
            const nums = [1, 2, 3, 0, 4, 5]
            nums.forEach((el) => list.insertLast(el))
            expect(list.length).toEqual(6)
            list.deleteAll(7)
            expect(list.length).toEqual(6)
        })
    })

    describe('#at()', () => {
        test('should return the value at the specified index', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            expect(list.at(0)).toEqual(-1)
            expect(list.at(1)).toEqual(1)
            expect(list.at(2)).toEqual(2)
            expect(list.at(3)).toEqual(0)
            expect(list.at(4)).toEqual(3)
            expect(list.at(5)).toEqual(0)
            expect(list.at(6)).toEqual(4)
            expect(list.at(7)).toEqual(5)
            expect(list.at(8)).toEqual(0)
            expect(list.at(9)).toEqual(-22)
        })
        test('returns null if no such index exists', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            expect(list.at(10)).toEqual(null)
            expect(list.at(-1)).toEqual(null)
        })
        test('returns null if list is empty', () => {
            expect(list.at(0)).toEqual(null)
        })
    })

    describe('#deleteAt', () => {
        test('should delete element at the given index', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            list.deleteAt(5)
            expect(list.entries()).toEqual([-1, 1, 2, 0, 3, 4, 5, 0, -22])
        })
        test('should re-assign first element if it is deleted', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            list.deleteAt(0)
            expect(list.front).toEqual(1)
        })
        test('should re-assign last element if it is deleted', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            list.deleteAt(9)
            expect(list.back).toEqual(0)
        })
        test('should re-assign first and last value if there are only two items in the list', () => {
            list.insertLast(1)
            list.insertLast(2)
            list.deleteAt(0)
            expect(list.front).toEqual(2)
            expect(list.back).toEqual(2)
        })
        test('should return true if deletion is successful', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            expect(list.deleteAt(5)).toEqual(true)
        })
        test('should return false if deletion fails - if list is empty', () => {
            expect(list.deleteAt(0)).toEqual(false)
        })
        test('should return false if deletion fails - if index does not exist in list', () => {
            const nums = [-1, 1, 2, 0]
            nums.forEach((el) => list.insertLast(el))
            list.deleteAt(5)
            expect(list.deleteAt(-1)).toEqual(false)
            expect(list.deleteAt(6)).toEqual(false)
        })
        test('should decrement the length if succeeded', () => {
            const nums = [-1, 1, 2, 0]
            nums.forEach((el) => list.insertLast(el))
            expect(list.length).toEqual(4)
            list.deleteAt(0)
            expect(list.length).toEqual(3)
        })
        test('should not decrement length is failed', () => {
            const nums = [-1, 1, 2, 0]
            nums.forEach((el) => list.insertLast(el))
            expect(list.length).toEqual(4)
            list.deleteAt(5)
            expect(list.length).toEqual(4)
        })
    })

    describe('#divideMid', () => {
        test('split list with odd number of elements', () => {
            const nums = [34, 65, 27, 89, 12]
            nums.forEach((el) => list.insertLast(el))
            const list2 = list.divideMid()
            expect(list2.entries()).toEqual([89, 12])
        })
        test('split list with even number of elements', () => {
            const nums = [-1, 1, 2, 0, 3, 0, 4, 5, 0, -22]
            nums.forEach((el) => list.insertLast(el))
            const list2 = list.divideMid()
            expect(list2.entries()).toEqual([0, 4, 5, 0, -22])
        })
        test('should empty list if the list has only one element', () => {
            const nums = [-1]
            nums.forEach((el) => list.insertLast(el))
            const list2 = list.divideMid()
            expect(list2.isEmpty()).toEqual(true)
        })
        test('should return empty list if the list is empty', () => {
            const list2 = list.divideMid()
            expect(list2.isEmpty()).toEqual(true)
        })
    })
})
