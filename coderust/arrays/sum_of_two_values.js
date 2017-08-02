const hasSomeOfTwo = (array, total) => {
	const encounteredNumbers = {}

	for (let i = 0; i < array.length; i++) {
		let currentNum = array[i]
		let matchingNumber = total - currentNum

		if (encounteredNumbers[matchingNumber]) return true

		encounteredNumbers[currentNum] = true
	}

	return false
}	

module.exports = hasSomeOfTwo