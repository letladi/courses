const Stack = require('../stack')
const expect = require('expect')

describe('Stack', () => {

	let stack = null
	const elementToAdd = 10
	beforeEach(() => {
		stack = new Stack()
	})
	afterEach(() => {
		stack = null
	})

	describe('#push', () => {
		it('should add/increase number of elements on the stack', () => {
			expect(stack.size()).toEqual(0)
			stack.push(1)
			expect(stack.size()).toEqual(1)
			stack.push(2)
			expect(stack.size()).toEqual(2)
		})
	})

	describe('#pop', () => {
		it('should return the topmost (recently element) element', () => {
			
			stack.push(elementToAdd)
			expect(stack.pop()).toEqual(elementToAdd)
		})
		it('should return null if the stack is empty', () => {
			expect(stack.pop()).toEqual(null)
		})
		it('should remove the topmost (recently added) element', () => {
			stack.push(elementToAdd)
			expect(stack.size()).toEqual(1)
			const el = stack.pop()
			expect(el).toEqual(elementToAdd)
			expect(stack.size()).toEqual(0)
		})
	})

	describe('#peek', () => {
		it('should return the topmost (recently added) element', () => {
			stack.push(elementToAdd)
			expect(stack.peek()).toEqual(elementToAdd)
		})
		it('should return null if the stack is empty', () => {
			expect(stack.peek()).toEqual(null)
		})
		it('should not remove the topmost (recently added) element', () => {
			stack.push(elementToAdd)
			expect(stack.size()).toEqual(1)
			stack.peek()
			expect(stack.size()).toEqual(1)
		})
	})

	describe('#size', () => {
		it('should return the number of elements in the stack', () => {
			expect(stack.size()).toEqual(0)
			stack.push(1)
			expect(stack.size()).toEqual(1)
			stack.push(2)
			expect(stack.size()).toEqual(2)
		})
	})
	describe('#isEmpty', () => {
		it('should return true if the stack is empty', () => {
			expect(stack.isEmpty()).toBeTruthy()
		})
		it('shold return false if the stack is not empty', () => {
			stack.push(1)
			expect(stack.isEmpty()).toBeFalsy()
		})
	})

})