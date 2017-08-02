const expect = require('expect')
const {search, searchRecursive} = require('../binary_search')

describe('binarySearch', () => {
	testBinarySearchMethod('binary search (iterative version)', search)
	testBinarySearchMethod('bianry search (recursive version)', searchRecursive)
})

function testBinarySearchMethod(suiteName, search) {

	const list = [1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133, 155, 162, 176, 188, 199, 200, 210, 222]
	const listKey = 47
	const listMissingKey = 55

	describe(suiteName, () => {
		it('should return -1 if the element does not exist in the array', () => {
			expect(search(list, listMissingKey)).toEqual(-1)
		})
		it('should return the index of the given key', () => {
			expect(search(list, listKey)).toEqual(3)
		})
	})
}