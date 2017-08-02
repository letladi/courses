const smallest_common_number = (a, b, c) => {
	let i = 0
	let j = 0
	let k = 0

	while (i < a.length && j < b.length && k < c.length) {

		if (a[i] == b[j] && b[j] == c[k]) {
			return a[i]
		}

		if (a[i] <= b[j] && a[i] <= c[k]) i++
		else if (b[j] <= a[i] && b[j] <= c[k]) j++
		else if (c[k] <= a[i] && c[k] <= b[j]) k++
	}

	return null
}

module.exports = smallest_common_number