const expect = require('expect')
const smallest_common_number = require('../smallest_common_number')

describe('smallest common number from 3 integer arrays', () => {
	const arr1 = [6, 7, 10, 25, 30, 63, 64]
	const arr2 = [-1, 4, 5, 6, 7, 8, 50]
	const arr3 = [1, 6, 10, 14]
	const arr4 = [-1, 5, 20, 8, 9]

	it(`should return 6 for arrays: ${arr1.toString()}, ${arr2.toString()}, ${arr3.toString()}`, () => {
		expect(smallest_common_number(arr1, arr2, arr3)).toEqual(6)
	})
	it('should return null if there is no least common number', () => {
		expect(smallest_common_number(arr1, arr2, arr4)).toEqual(null)
	})
})