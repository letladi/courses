const expect = require('expect')
const { uniqueNumber, uniqueNumberXOR } = require('../problem-21')

describe('problem-21', () => {
		const numbers = [22, 112, 2, 22, 5, 20, 112, 23, 5, 2, 20]
		const uniqueNum = 23

	it('should return the unique number among all the numbers in the array', () => {
		expect(uniqueNumber(numbers)).toEqual(uniqueNum)
	})

	it('the XOR version should give the same result', () => {
		expect(uniqueNumber(numbers)).toEqual(uniqueNum)
	})
	
})

