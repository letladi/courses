const { expect } = require('chai')
const getOptimalValue = require('./loot')

describe('fractional knapsack problem', () => {
	it('should return 180.00 for v:w; 60:20, 100:50, 120:30', () => {
		const items = [
			{ weight: 20, value: 60 },
			{ weight: 50, value: 100 },
			{ weight: 30, value: 120 }
		]
		const capacity = 50

		const result = getOptimalValue(capacity, items)

		expect(result).to.eql(180.00)
	})

	it('should return 166.6667 for v:w; 500:30', () => {
		const items = [
			{ weight: 30, value: 500 }
		]
		const capacity = 10

		const result = getOptimalValue(capacity, items)

		expect(result).to.eql(166.66666666666667)
	})
})