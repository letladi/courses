class Stack {
	constructor() {
		this._values = []
	}

	push(el) {
		this._values.push(el)
	}

	pop() {
		const el = this._values.pop()
		return el || null
	}

	peek() {
		const top_index = this.size() - 1
		const el = this._values[top_index]
		return el || null
	}

	size() {
		return this._values.length
	}

	isEmpty() {
		return this.size() == 0
	}
}

module.exports = Stack