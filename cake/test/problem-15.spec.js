const expect = require('expect')
const fib = require('../problem-15')

describe('fib function', () => {
	it('should return 3 for fib(4)', () => {
		expect(fib(4)).toEqual(3)
	})
	it('should return 2 for fib(3)', () => {
		expect(fib(3)).toEqual(2)
	})
	it('should return 1 for fib(2)', () => {
		expect(fib(2)).toEqual(1)
	})
	it('should return 1 for fib(1)', () => {
		expect(fib(1)).toEqual(1)
	})
	it('should return 0 for fib(0)', () => {
		expect(fib(0)).toEqual(0)
	})
	it('should return 21 for fib(8)', () => {
		expect(fib(8)).toEqual(21)
	})
	it('should return 13 for fib(7)', () => {
		expect(fib(7)).toEqual(13)
	})
	it('should return 8 for fib(6)', () => {
		expect(fib(6)).toEqual(8)
	})
	it('should throw an error for negative indexes', () => {
		expect(() => fib(-5)).toThrow()
	})
})