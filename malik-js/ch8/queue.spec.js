const Queue = require('./queue')

describe('Queue', () => {
    let queue = null
    beforeEach(() => queue = new Queue())
    afterEach(() => queue = null)

    describe('#isEmpty', () => {
        test('should return true if the queue is empty', () => {
            expect(queue.isEmpty()).toEqual(true)
        })
        test('should return false if the queue is not empty', () => {
            queue.enqueue(1)
            expect(queue.isEmpty()).toEqual(false)
        })
    })
    describe('.length', () => {
        test('should return the number of elements added to the queue', () => {
            expect(queue.length).toEqual(0)
            queue.enqueue(1)
            expect(queue.length).toEqual(1)
            queue.enqueue(2)
            expect(queue.length).toEqual(2)
        })
    })
    describe('#enqueue', () => {
        test('should add an element to the queue', () => {
            queue.enqueue(1)
            queue.enqueue(2)
            expect(queue.length).toEqual(2)
        })
    })
    describe('#dequeue', () => {
        test('should return and remove elements from the front of the queue', () => {
            queue.enqueue(1)
            queue.enqueue(2)
            queue.enqueue(3)
            expect(queue.dequeue()).toEqual(1)
            expect(queue.dequeue()).toEqual(2)
            expect(queue.dequeue()).toEqual(3)
        })
        test('should throw an error if the list is empty', () => {
            expect(() => queue.dequeue()).toThrow()
        })
    })
    describe('.front', () => {
        test('should return the element at the front of the queue', () => {
            queue.enqueue(10)
            queue.enqueue(20)
            expect(queue.front).toEqual(10)
        })
    })
    describe('.back', () => {
        test('should return the element at the back of the queue', () => {
            queue.enqueue(10)
            queue.enqueue(20)
            expect(queue.back).toEqual(20)
        })
        test('should throw an error if the queue is empty', () => {
            expect(() => queue.back).toThrow()
        })
    })
    describe('#reset', () => {
        test('should reset the queue to an initial state', () => {
            queue.enqueue(10)
            queue.enqueue(20)
            queue.reset()
            expect(queue.isEmpty()).toEqual(true)
            expect(queue.length).toEqual(0)
        })
    })

    describe('#moveNthFront', () => {
        const numList = [5, 11, 34, 67, 43, 55]
        test('should move nth element to the front', () => {
            const queue = new Queue(6)
            numList.forEach((el) => queue.enqueue(el))
            expect(queue.front).toEqual(5)
            queue.moveNthFront(3)
            expect(queue.front).toEqual(34)
        })
        test('should throw if n overflows the queue', () => {
            const queue = new Queue(6)
            numList.forEach((el) => queue.enqueue(el))
            expect(() => queue.moveNthFront(8)).toThrow()
        })
    })
})