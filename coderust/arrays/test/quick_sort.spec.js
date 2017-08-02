const expect = require('expect')
const quick_sort = require('../quick_sort')

describe('quick-sort', () => {
	const array1 = [55, 23, 26, 2, 25]
	const array2 = [9, 7, 5, 11, 12, 2, 14, 3, 10, 6]

	it(`should transform ${array1.toString()} into [2, 23, 25, 26, 55]`, () => {
		expect(quick_sort(array1)).toEqual([2, 23, 25, 26, 55])
	})

	it(`should transform ${array2.toString()} into [2, 3, 5, 6, 7, 9, 10, 11, 12, 14]`, () => {
		expect(quick_sort(array2)).toEqual([2, 3, 5, 6, 7, 9, 10, 11, 12, 14])
	})
})