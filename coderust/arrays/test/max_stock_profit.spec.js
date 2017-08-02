const expect = require('expect')
const max_stock_profit = require('../max_stock_profit')

describe('max-stock-profit', () => {
	const prices1 = [8, 5, 12, 9, 19, 1]
	const prices2 = [21, 12, 11, 9, 6, 3]

	it(`should buy at 5 and sell at 19 for prices: ${prices1.toString()}`, () => {
		expect(max_stock_profit(prices1)).toEqual({ buy: 5, sell: 19})
	})
	it(`should be buy at 12 and sell at 11 for prices: ${prices2.toString()}`, () => {
		expect(max_stock_profit(prices2)).toEqual({ buy: 12, sell: 11})
	})
})