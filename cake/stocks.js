function getMaxProfit(prices) {
	if (prices.length < 2) throw new Error('At least two prices are required')

	let minPrice = prices[0]
	let maxProfit = prices[1] - prices[0]


	for (let i = 1; i < prices.length; i++) {
		let currentPrice = prices[i]

		//console.log('HERE IS THE CURRENT PRICE', currentPrice)

		let potentialProfit = currentPrice - minPrice

		//console.log('HERE IS THE POTENTIAL PROFIT', potentialProfit)

		maxProfit = Math.max(potentialProfit, maxProfit)

		//console.log('HERE IS THE MAX PROFIT INSIDE THE FOR-LOOP', maxProfit)

		minPrice = Math.min(currentPrice, minPrice)

		//console.log('NOW HERE IS THE NEW MIN PRICE', minPrice)
	}

	return maxProfit
}

module.exports = getMaxProfit
