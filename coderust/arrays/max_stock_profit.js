const max_stock_profit = (array) => {
	if (array == void(0) ||  array.length < 2) {
		return
	}

	let current_buy = array[0]
	let global_sell = array[1]
	let global_profit = global_sell - current_buy

	let current_profit = 0

	for (let i = 1; i < array.length; i++) {
		current_profit = array[i] - current_buy

		if (current_profit > global_profit) {
			global_profit = current_profit
			global_sell = array[i]
		}

		if (current_buy > array[i]) {
			current_buy = array[i]
		}
	}

	return {
		buy: global_sell - global_profit,
		sell: global_sell
	}
}

module.exports = max_stock_profit