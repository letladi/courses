const expect = require('expect')
const getProductsOfAllIntsExceptAtIndex = require('../problem-2')

describe('getProductsOfAllIntsExceptAtIndex', () => {
	it('should return the product of all the numbers in the array, excluding the current number', () => {
		expect(getProductsOfAllIntsExceptAtIndex([1, 7, 3, 4])).toEqual([84, 12, 28, 21])
	})
	it('should work even if the input contains zeroes', () => {
		expect(getProductsOfAllIntsExceptAtIndex([1, 0, -5, 20, 6, 4])).toEqual([0,-2400,0,0,0,0])
	})
	it('should throw an exception is the array length is less than 2', () => {
		expect(() => getProductsOfAllIntsExceptAtIndex([200])).toThrow('An array with at least two elements is required')
	})
})