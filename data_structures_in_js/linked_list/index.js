class Node {
	constructor(data) {
		this.data = data
		this.next = null
	}
}

class LinkedList {
	constructor() {
		this._length = 0
		this._head = {
			next: null
		}
	}

	push(data) {
		const node = new Node(data)

		let current = this._head

		while (current.next) {
			current = current.next
		}

		current.next = node

		this._length++
	}

	itemAt(index) {
		if (index < 0 || index >= this._length) return null

		let current = this._head
		let counter = -1

		while (counter < index) {
			current = current.next 
			counter++
		}

		return current.data
	}

	remove(index) {
		if (index < 0 || index >= this._length) return null

		let current = this._head
		let counter = 0

		while (counter < index) {
			current = current.next 
			counter++
		}

		const elementToBeRemoved = current.next
		current.next = current.next.next

		this._length--

		return elementToBeRemoved.data
	}

	search(val) {
		let current = this._head
		let counter = -1

		while (current.next) {
			current = current.next
			counter++

			if (val === current.data) return counter
		}

		return null
	}

	size() {
		return this._length
	}
}

module.exports = LinkedList