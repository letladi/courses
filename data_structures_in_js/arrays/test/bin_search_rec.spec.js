const expect = require('chai').expect
const {list, listMissing, key} = require('./lists')
const binarySearch = require('../bin_search_rec')

describe('binary search (recursive version)', () => {
	it('should return -1 for a missing key', () => {
		expect(binarySearch(listMissing, key)).to.equal(-1)
	})
	it('should return the index of the given key', () => {
		expect(binarySearch(list, key)).to.equal(3)
	})
}) 