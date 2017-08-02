const expect = require('expect')

const Queue = require('../queue')

describe('Queue', () => {

	let queue = null
	const elementToAdd = 'element'
	beforeEach(() => {
		queue = new Queue()
	})
	afterEach(() => {
		queue = null
	})

	describe('#enqueue', () => {
		it('adds elements to the queue', () => {
			queue.enqueue(elementToAdd)
			expect(queue.size()).toEqual(1)
		})
	})

	describe('#dequeue', () => {
		beforeEach(() => {
			queue.enqueue(elementToAdd)
			queue.enqueue(2)
			queue.enqueue(3)
		})

		afterEach(() => {
			queue = null
		})

		it('returns the first element in the queue', () => {
			const el = queue.dequeue()
			expect(el).toEqual(elementToAdd)
		})
		it('removes the first element in the queue', () => {
			expect(queue.size()).toEqual(3)
			queue.dequeue()
			const el = queue.dequeue()
			expect(el).toNotEqual(elementToAdd)
		})

		it('returns null if the queue is empty', () => {
			queue = new Queue
			const el = queue.dequeue()
			expect(el).toBe(null)
		})
	})

	describe('#peek', () => {
		it('return the first element in the queue', () => {
			queue.enqueue(elementToAdd)

			const el = queue.peek()
			expect(el).toEqual(elementToAdd)
		})
		it('does not remove the first element in the queue', () => {
			queue.enqueue(elementToAdd)

			expect(queue.size()).toEqual(1)
			const el = queue.peek()
			expect(queue.size()).toEqual(1)
		})

		it('returns null if the queue is empty', () => {
			const el = queue.dequeue()
			expect(el).toBe(null)
		})
	})

	describe('#size', () => {
		it('should return the number of elements added to the queue', () => {
			expect(queue.size()).toEqual(0)
			queue.enqueue(elementToAdd)
			expect(queue.size()).toEqual(1)
		})
	})

	describe('#isEmpty', () => {
		it('should return true if the queue is empty', () => {
			expect(queue.isEmpty()).toBeTruthy()
		})
		it('should return false if the queue is not empty', () => {
			queue.enqueue(elementToAdd)
			expect(queue.isEmpty()).toBeFalsy()
		})
	})
})