class Change {
	constructor() {
		this.memo = {}
	}

	changePossibilities(amountLeft, denominations, currentIndex) {
		currentIndex = (typeof currentIndex != 'undefined') ? currentIndex : 0

		const memoKey = [amountLeft, currentIndex].join(', ')
		if (this.memo.hasOwnProperty(memoKey)) {
			console.log(`grabbing memo [${memoKey}]`)
			return this.memo[memoKey]
		}

		if (amountLeft == 0) return 1

		if (amountLeft < 0) return 0

		if (currentIndex == denominations.length) return 0

		console.log(`checking ways to make ${amountLeft} with [${denominations.slice(currentIndex).join(', ')}]`)

		const currentCoin = denominations[currentIndex]

		let numPossibilities = 0
		while (amountLeft >= 0) {
			numPossibilities += this.changePossibilities(amountLeft, denominations, currentIndex + 1)
			amountLeft -= currentCoin
		}

		this.memo[memoKey] = numPossibilities
		return numPossibilities
	}
}

module.exports = Change