function search(array, key, low = 0, high = array.length - 1) {
	while (low <= high) {
		let mid = Math.floor((low + high) / 2)

		if (array[mid] == key) {
			return mid
		} else if (key < array[mid]) {
			high = mid - 1
		} else if (key > array[mid]) {
			low = mid + 1
		}
	}
	return -1
}

function searchRecursive(array = [], key, low = 0, high = array.length - 1) {

	if (low > high) return -1

	const mid = Math.floor((low + high) / 2)

	if (array[mid] == key) {
		return mid
	} else if (key < array[mid]) {
		return searchRecursive(array, key, low, mid - 1)
	} else if (key > array[mid]) {
		return searchRecursive(array, key, mid + 1, high)
	}
}

module.exports = {
	search, 
	searchRecursive
}