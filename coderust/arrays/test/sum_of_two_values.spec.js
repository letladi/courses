const expect = require('expect')
const hasSomeOfTwo = require('../sum_of_two_values')

describe('sum of two values problem', () => {
	const array = [5, 7, 1, 2, 8, 4, 3]

	it(`should return true when given 10 and array: ${array.toString()}`, () => {
		expect(hasSomeOfTwo(array, 10)).toEqual(true)
	})
	it(`should return false when given 19 and array: ${array.toString()}`, () => {
		expect(hasSomeOfTwo(array, 19)).toEqual(false)
	})
})