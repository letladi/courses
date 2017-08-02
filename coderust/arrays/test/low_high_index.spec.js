const expect = require('expect')
const low_high_index = require('../low_high_index')

describe('low_high_index method', () => {
	const array = [1, 2, 5, 5, 5, 5, 5, 5, 5, 5, 20]

	describe(`given the array: ${array}`, () => {
		it('should return low=0, high=0, for key = 1', () => {
			expect(low_high_index(array, 1)).toEqual({ low: 0, high: 0 })
		})
		it('should return low=1, high=1, for key = 2', () => {
			expect(low_high_index(array, 2)).toEqual({ low: 1, high: 1 })
		})
		it('should return low=2, high=9, for key = 5', () => {
			expect(low_high_index(array, 5)).toEqual({ low: 2, high: 9})
		})
		it('should return low=10, high=10, for key = 20', () => {
			expect(low_high_index(array, 20)).toEqual({ low: 10, high: 10})
		})
		it('should return -1 if the element does not exist al all inside the array', () => {
			expect(low_high_index(array, 10)).toEqual(-1)
		})
	})
})