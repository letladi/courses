const getMaxProfit = require('../stocks')
const expect = require('expect')

describe('stocks problem', () => {
	it('should return the maximum amount of money that can be made from a purchase over time', () => {
		const stockPricesYesterday = [15, 10, 7, 5, 8, 11, 9]
		expect(getMaxProfit(stockPricesYesterday)).toEqual(6)
	})
	it('should return the least negative amount of profit if the price was decreasing all day', () => {
		const stockPricesYesterday = [5, 4, 3, 2, 1]
		expect(getMaxProfit(stockPricesYesterday)).toEqual(-1)
	})
	it('should throw an exception if there are less than two prices', () => {
		const stockPricesYesterday = [200]
		expect(() => getMaxProfit(stockPricesYesterday)).toThrow()
	})
})