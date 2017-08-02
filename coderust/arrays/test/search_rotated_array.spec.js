const expect = require('expect')
const search_rotated = require('../search_rotated_array')

describe('search rotated array', () => {
	const array = [176, 188, 199, 200, 210, 222, 1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133, 155, 162]
	it(`should return 5 when searching 222 in array: ${array.toString()}`, () => {
		expect(search_rotated(array, 222)).toEqual(5)
	})
	it(`should return 6 when searching 1 in array: ${array.toString()}`, () => {
		expect(search_rotated(array, 1)).toEqual(6)
	})
	it(`should return 0 when searching 176 in array: ${array.toString()}`, () => {
		expect(search_rotated(array, 176)).toEqual(0)
	})
	it (`should return -1 when searching 256 in array: ${array.toString()}`, () => {
		expect(search_rotated(array, 256)).toEqual(-1)
	})
})
