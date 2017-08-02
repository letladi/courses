module.exports = function binarySearch(array = [], key, low = 0, high = array.length - 1) {
	const mid = Math.floor((low + high) / 2)
	
	// base case
	if (low > high) {
		return -1
	}
	

	if (key > array[mid]) {
		low = mid + 1
		return binarySearch(array, key, low, high)
	} else if (key < array[mid]) {
		high = mid - 1
		return binarySearch(array, key, low, high)
	} else {
		return mid
	}
}
