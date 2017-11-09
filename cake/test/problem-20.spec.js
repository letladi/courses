const expect = require('expect')
const { MaxStack } = require('../problem-20')

describe('Stack', () => {
	describe('#push', () => {
		it('should add an element to the stack')
	})
	describe('#pop', () => {
		it('should remove and element from the stack')
	})
	describe('#peek', () => {
		it('should return the last added element without removing it')
	})
	describe('#size', () => {
		it('should return the size/number of elements on the stack')
	})
})
const times = (n, cb) => {
	for (let i = 0; i < n; i++) {
		cb(i)
	}
} 
describe('MaxStack', () => {
	describe('#getMax', () => {
		let values = [100, -110, 200, 500, 246, 501, 22, 566, 23, 12, 20]
		let stack = void(0)

		beforeEach(() => {
			stack = new MaxStack()
			values.forEach((el) => stack.push(el))
		})
		afterEach(() => {
			stack = void(0)
		})
		it('should return the maximum of all elements added to the stack', () => {
			const max = stack.getMax()

			expect(max).toEqual(566)
		})
		it('it shold return the next maximum after the previous max is popped from the stack', () => {
			// remove some items, that include the maximum
			times(5, () => stack.pop())

			expect(stack.getMax()).toEqual(501)
		})
	})
})