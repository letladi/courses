const rotate_array = (array, numRotation) => {
	const arrayLen = array.length
	// normalize rotation count
	numRotation = numRotation % arrayLen
	
	const result = []
	let idx = (numRotation < 0) ? -1 * numRotation : arrayLen - numRotation

	while (result.length != arrayLen) {
		result.push(array[idx])
		idx++
		if (idx == arrayLen) idx = 0
	}
	
	result.forEach((num, i) => {
		array[i] = num
	})

	return array
}

module.exports = rotate_array