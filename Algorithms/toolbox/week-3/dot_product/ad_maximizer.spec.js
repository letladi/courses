const { expect } = require('chai')
const { maxAdProfit } = require('./ad_maximizer.js')

describe('ad maximizer', () => {
	it('should return 897 for ads [23] and slots [39]', () => {
		const adProfits = [23]
		const slotClicks = [39]

		const maxProfit = maxAdProfit(adProfits, slotClicks)

		expect(maxProfit).to.eql(897)
	})

	it('should return 23 for ads [1, 3, -5] and slots [-2, 4, 1]', () => {
		const adProfits = [1, 3, -5]
		const slotClicks = [-2, 4, 1]

		const maxProfit = maxAdProfit(adProfits, slotClicks)

		expect(maxProfit).to.eql(23)
	})
})