const treeHeight = require('./')
const { expect } = require('chai')

describe('treeHeight method', () => {
	const input1 = [4, -1, 4, 1, 1]
	const input2 = [-1, 0, 4, 0, 3]

	it(`should return 3 for ${input1}`, () => {
		expect(treeHeight(input1)).to.eql(3)
	})

	it(`should return 4 for ${input2}`, () => {
		expect(treeHeight(input2)).to.eql(4)
	})
})