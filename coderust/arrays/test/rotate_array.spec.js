const expect = require('expect')
const rotate_array = require('../rotate_array')

describe('rotate_array', () => {
	let array = null
	beforeEach(() => {
		array = [1, 10, 20, 0, 59, 86, 32, 11, 9, 40]
	})
	afterEach(() => array = null)
	it(`should return [10, 20, 0, 59, 86, 32, 11, 9, 40, 1] after -1 rotations of [1, 10, 20, 0, 59, 86, 32, 11, 9, 40]`, () => {
		expect(rotate_array(array, -1)).toEqual([10, 20, 0, 59, 86, 32, 11, 9, 40, 1])
	})

	it(`should return [9, 40, 1, 10, 20, 0, 59, 86, 32, 11] after 2 rotations of [1, 10, 20, 0, 59, 86, 32, 11, 9, 40]`, () => {
		expect(rotate_array(array, 2)).toEqual([9, 40, 1, 10, 20, 0, 59, 86, 32, 11])
	})

	it(`should return [] after =-3 rotations of [1, 10, 20, 0, 59, 86, 32, 11, 9, 40]`, () => {
		expect(rotate_array(array, -3)).toEqual([0, 59, 86, 32, 11, 9, 40, 1, 10, 20])
	})
})