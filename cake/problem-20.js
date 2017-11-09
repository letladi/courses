class Stack {
	constructor() {
		this.__items = []
	}

	push(item) {
		this.__items.push(item)
	}

	pop() {
		return this.__items.length ? this.__items.pop() : null
	}

	peek() {
		const len = this.__items.length
		return len ? this.__items[len - 1] : null
	}
}

class MaxStack  {
	constructor() {
		this.stack = new Stack()
		this.maxesStack = new Stack()
	}

	push(item) {
		if (this.maxesStack.length == 0 || item > this.maxesStack.peek()) {
			this.maxesStack.push(item)
		}

		this.stack.push(item)
	}

	pop() {
		const item = this.stack.pop()

		if (item === this.maxesStack.peek()) {
			this.maxesStack.pop()
		}
		return item
	}

	getMax() {
		return this.maxesStack.peek()
	}

	peek() {
		return this.stack.peek()
	}
}

module.exports = {
	Stack,
	MaxStack,
}