module.exports = (array, key) => {
	let low = 0, high = array.length - 1, index = -1

	while (low <= high) {
		mid = Math.floor((low + high) / 2)

		if (key < array[mid]) {
			high = mid - 1
		} else if (key > array[mid]) {
			low = mid + 1
		} else {
			index = mid
			break
		}
	}

	return index
}