const { expect } = require('chai')
const binary_gaps = require('../binary-gaps')

describe('binary gaps problem', () => {
	it('should return 4 for 529', () => {
		expect(binary_gaps(529)).to.eql(4)
	})
	it('should return 2 for 9', () => {
		expect(binary_gaps(9)).to.eql(2)
	})
	it('should return 1 for 20', () => {
		expect(binary_gaps(20)).to.eql(1)
	})
	it('should return 0 for 15', () => {
		expect(binary_gaps(15)).to.eql(0)
	})
	it('should 5 for 1041', () => {
		expect(binary_gaps(1041)).to.eql(5)
	})
})