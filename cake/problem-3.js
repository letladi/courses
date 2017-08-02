function maxProductOf3(array) {
	if (array.length < 3) throw new Error('Array must have at least three elements')

	let highest = Math.max(array[0], array[1])
	let lowest = Math.min(array[0], array[1])

	let highestProductOf2 = array[0] * array[1]
	let lowestProductOf2 = array[0] * array[1]

	let highestProductOf3 = array[0] * array[1] * array[2]

	let current = null
	for (let i = 2; i < array.length; i++) {
		current = array[i]

		highestProductOf3 = Math.max(
			highestProductOf3, 
			highestProductOf2 * current, 
			lowestProductOf2 * current
		)

		highestProductOf2 = Math.max(
			highest * current, 
			highestProductOf2, 
			lowest * current
		)
		
		lowestProductOf2 = Math.min(
			lowest * current, 
			lowestProductOf2, 
			highest * current
		)

		
		highest = Math.max(highest, current)

		lowest = Math.min(lowest, current)
	}

	return highestProductOf3
}

module.exports = maxProductOf3