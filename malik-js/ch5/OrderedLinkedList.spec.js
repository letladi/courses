const OrderedLinkedList = require('./OrderedLinkedList')

describe('OrderedLinkedList', () => {
    let list = null
    beforeEach(() => list = new OrderedLinkedList())
    afterEach(() => list = null)

    describe('#insert', () => {
        test('should insert elements in sorted order', () => {
            const nums = [20, 15, 22, -5, 10]
            nums.forEach((el) => list.insert(el))
            expect(list.entries()).toEqual([-5, 10, 15, 20, 22])
        })
    })

    describe('#insertFirst', () => {
        test('should insert elements in sorted order', () => {
            const nums = [20, 15, 22, -5, 10]
            nums.forEach((el) => list.insertFirst(el))
            expect(list.entries()).toEqual([-5, 10, 15, 20, 22])
        })
    })

    describe('#insertLast', () => {
        test('should insert elements in sorted order', () => {
            const nums = [20, 15, 22, -5, 10]
            nums.forEach((el) => list.insertLast(el))
            expect(list.entries()).toEqual([-5, 10, 15, 20, 22])
        })
    })

    describe('#delete', () => {
        test('removes an item from the list', () => {
            const nums = [20, 15, 22, -5, 10]
            nums.forEach((el) => list.insertLast(el))
            expect(list.entries()).toEqual([-5, 10, 15, 20, 22])
            expect(list.delete(15)).toEqual(true)
            expect(list.entries()).toEqual([-5, 10, 20, 22])
        })
    })
})
