function rotationPoint(array = []) {
	let low = 0
	let high = array.length - 1

	let i = low
	while (low < high) {
		let mid = low + Math.floor((high - low) / 2)

		if (array[mid - 1] > array[mid] && array[mid] < array[mid + 1]) {
			return mid
		}

		if (array[mid] > array[low]) {
			low = mid + 1
		} else if (array[mid] < array[low]) {
			high = mid - 1
		}
	}

	return 0
}

module.exports = rotationPoint