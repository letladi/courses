const uniqueNumber = (numbers) => {
	const encountered = {}
	const notEncountered = {}

	numbers.forEach((num) => {
		if (encountered[num]) {
			delete notEncountered[num]
		} else {
			encountered[num] = true
			notEncountered[num] = true
		}
	})

	for (key in notEncountered) {
		if (notEncountered.hasOwnProperty(key)) {
			return +key
		}
	}
}

const uniqueNumberXOR = (numbers) => {
	let unique = 0

	numbers.forEach((num) => {
		unique ^= num 
	})

	return unique
}

module.exports = {
	uniqueNumber,
	uniqueNumberXOR,
}