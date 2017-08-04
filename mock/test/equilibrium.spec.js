const { expect } = require('chai')
const equilibrium_indices = require('./equilibrium')

describe('sample problem', () => {
	const array = [-1, 3, -4, 5, 1, -6, 2, 1]
	it(`should be either 1, 3 or 7 for array: ${array.toString()}`, () => {
		expect(equilibrium_indices(array)).to.be.oneOf([1, 3, 7])
	})
})