const equilibrium_indices = (array) => {
	const accumulated_sum = {}
	let sum = 0
	
	array.forEach((num, i) => {
		accumulated_sum[i] = sum
		sum += num
	})

	sum = 0
	let result = []
	for (let len = array.length, i = len - 1; i > 0; i--) {	
		if (accumulated_sum[i] == sum) {
			result.push(i)
		}
		sum += array[i] || 0
	}

	return result[0]
}

module.exports = equilibrium_indices