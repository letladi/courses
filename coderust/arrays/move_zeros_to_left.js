const move_zeros_to_left = (array) => {
	const len = array.length

	if (len < 1) return void(0)

	let read = len - 1
	let write = len - 1

	while (read >= 0) {
		if (array[read] != 0) {
			array[write] = array[read]
			write--
		}
		read--
	}

	while (write >= 0) {
		array[write] = 0
		write--
	}

	return array
}

module.exports = move_zeros_to_left