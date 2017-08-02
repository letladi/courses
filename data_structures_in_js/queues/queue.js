class Queue {
	constructor() {
		this._values = []
		this._head = 0
		this._GARBAGE_THRESHOLD = 100
	}

	enqueue(el) {
		this._values.push(el)
	}

	dequeue() {
		const el = this._values[this._head++] || null

		if (this._head == this._GARBAGE_THRESHOLD) {
			this._values.splice(0, this._GARBAGE_THRESHOLD)

			this._head = 0
		}

		return el
	}

	peek() {
		return this._values[this._head] || null
	}

	size() {
		return this._values.length
	}

	isEmpty() {
		return this.size() == 0
	}
}

module.exports = Queue