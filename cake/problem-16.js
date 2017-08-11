const maxDuffelBagValue = (cakeTypes, capacity) => {
	const cakes = cakeTypes.map((cake) => cake.ratio = cake.value / cake.weight)

	cakes.sort((cake) => cake.ratio)

	let max = 0
	let count = 0
	while (capacity >= 0) {
		let cake = cakes[count]
		if (capacity - cake.weight >= 0) {
			max += cake.value
			count++
		} else {
			// let val = 
		}
	}
}

module.exports = maxDuffelBagValue