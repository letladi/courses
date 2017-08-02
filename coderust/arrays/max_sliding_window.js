const maxSlidingWindow = (array, windowSize) => {
	let result = []

	if (windowSize > array.length) return

		let window_ = []
		// find max for first window
		for (let i = 0; i < windowSize; i++) {
			while (window_.length > 0 && array[i] >= array[window_[window_.length - 1]]) {
				window_.pop()
			}
			window_.push(i)
		}

		for (let i = windowSize; i < array.length; i++) {
			// remove all numbers smaller than current number
			// from the tail of list
			while (window_.length > 0 && array[i] >= array[window_[window_.length - 1]]) {
				window_.pop()
			}

			// remove first number if it doesn't fall in the window anymore
			if (window_.length > 0 && (window_[0] <= i - windowSize)) {
				window_.shift()
			}

			window_.push(i)
			result.push(array[window_[0]])
		}

		return result
}

module.exports = maxSlidingWindow