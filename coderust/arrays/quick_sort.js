// function quick_sort(array) {
// 	if (array.length < 2) return array

// 	const lastIndex = array.length - 1
	
// 	const pivot = array[lastIndex]
// 	const lessThan = []
// 	const greaterThan = []

// 	for (let i = 0; i < lastIndex; i++) {
// 		if (array[i] > pivot) {
// 			greaterThan.push(array[i])
// 		} else {
// 			lessThan.push(array[i])
// 		}
// 	}

// 	return [...quick_sort(lessThan), pivot, ...quick_sort(greaterThan)]
// }

function partition(array, low, high) {
	let pivot_value = array[low]
	let i = low
	let j = high

	while (i < j) {
		while (i <= high && array[i] <= pivot_value) {
			i++
		}

		while (array[j] > pivot_value) {
			j--
		}

		if (i < j) {
			let temp = array[i]
			array[i] = array[j]
			array[j] = temp
		} else {
			break
		}
	}

	array[low] = array[j]
	array[j] = pivot_value

	return j
}

function quick_sort_rec(a, l, h) {
	if (h > l) {
		let pivot_index = partition(a, l, h)
		quick_sort_rec(a, l, pivot_index - 1)
		quick_sort_rec(a, pivot_index + 1, h)
	}
	return a
}

function quick_sort(a) {
	return quick_sort_rec(a, 0, a.length - 1)
}

module.exports = quick_sort