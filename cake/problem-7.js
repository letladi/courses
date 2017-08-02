class TempTracker {
	constructor() {
		this._temps = {}
		this._total = 0
		this._tempCount = 0

		this._max = Number.NEGATIVE_INFINITY
		this._min = Number.POSITIVE_INFINITY
		this._mean = 0

		this._modeCount = Number.NEGATIVE_INFINITY
		this._mode = null
	}

	insert(el) {
		this._total += el
		this._tempCount++
		this._mean = this._total / this._tempCount

		this._temps[el] = this._temps[el] || 0
		this._temps[el]++

		this._max = Math.max(el, this._max)
		this._min = Math.min(el, this._min)

		this._mode = (this._temps[el] > this._modeCount) ? el : this._mode
		this._modeCount = Math.max(this._temps[el], this._modeCount)
	}	

	getMax() {
		return this._max
	}

	getMin() {
		return this._min
	}

	getMean() {
		return this._mean
	}

	getMode() {
		return this._mode
	}
}

module.exports = TempTracker