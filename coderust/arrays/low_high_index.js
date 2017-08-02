const { search } = require('./binary_search')

const low_high_index = (array, key) => {
	const keyIndex = search(array, key)

	if (keyIndex == -1) return keyIndex

	let low = keyIndex
	let high = keyIndex
	const len = array.length

	let idx = low
	while (idx != -1 && idx != 0) {
		idx = search(array, key, 0, idx)
		if (idx != -1) {
			low = idx
			idx--
		}
	}

	idx = high
	while (idx != -1 && idx < len) {
		idx = search(array, key, idx, len - 1)
		if (idx != -1) {
			high = idx 
			idx++
		}
	}	

	return {
		low, high
	}
}

module.exports = low_high_index