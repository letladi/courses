const { expect } = require('chai')
const change = require('./change')

describe('change algorithm', () => {
	it('should take 2 coins to change R2', () => {
		const m = 2

		const numCoins = change(m)

		expect(numCoins).to.be.eql(2)
	})
	it('should take 6 coins to change R28', () => {
		const m = 28

		const numCoins = change(m)

		expect(numCoins).to.be.eql(6)
	})

	it('should take 5 coins to change R23', () => {
		const m = 23

		const numCoins = change(m)

		expect(numCoins).to.be.eql(5)
	})
})