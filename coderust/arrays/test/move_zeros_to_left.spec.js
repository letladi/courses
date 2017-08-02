const expect = require('expect')
const move_zeros_to_left = require('../move_zeros_to_left')

describe('move zeros to left problem', () => {
	const array1 = [1, 10, 20, 0, 59, 63, 0, 88, 0]
	const array2 = [-1, 4, 5, 6, 7, 8, 50]
	const array3 = [2]

	it(`should transform ${array1.toString()} into ${array1.toString()}`, () => {
		expect(move_zeros_to_left(array1)).toEqual([0, 0, 0, 1, 10, 20, 59, 63, 88])
	})
	it(`should leave ${array2.toString()}`, () => {
		expect(move_zeros_to_left(array2)).toEqual(array2)
	})
})