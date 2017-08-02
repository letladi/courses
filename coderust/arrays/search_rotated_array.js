const search_rotated = (array, key) => {
	let low = 0
	let high = array.length

	while (low <= high) {
		let mid = low + Math.floor((high - low) / 2)

		if (array[mid] == key) return mid

		if (array[low] < array[mid] && (array[low] <= key && key < array[mid])) {
			high = mid - 1
		} else if (array[high] > array[mid] && (array[mid] < key && key <= array[high])) {
			low = mid + 1
		} else if (array[low] > array[mid]) {
			high = mid - 1
		} else if (array[high] < array[mid]){
			low = mid + 1
		}
	}
	return -1
}

module.exports = search_rotated