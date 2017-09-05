class Node {
	constructor(data) {
		this.next = this.prev = null
		this.data = data
	}
}

const sortedInsert = (list, data) => {
	if (list == void(0)) {
		list = new Node()
		let newNode = new Node(data)
		list.next = newNode

		delete list.data
		delete list.prev

		return list
	}

	let current = list.next 

	while (current) {

		if (data < current.data) {
			let newNode = new Node(data)

			let temp = current.prev

			newNode.next = current
			current.prev = newNode

			if (temp) {
				newNode.prev = temp
				temp.next = newNode	
			} else {
				delete newNode.prev
				list.next = newNode
			}
			
			return list
		}

		if (current.next == void(0)) {
			break
		}

		current = current.next
	}

	let temp = current.next

	if (temp) {
		let newNode = new Node(data)
		current.next = newNode
		newNode.prev = current

		newNode.next = temp
		temp.prev = newNode
	} else {
		let newNode = new Node(data)
		newNode.prev = current
		current.next = newNode
	}

	return list
}

const insert = (head, data) => {
	const newNode = new Node(data)

	if (head == void(0)) {
		return head = newNode
	} 

	let current = head 
	let prev = void(0)

	while (current) {
		prev = current 
		current = current.next
	}

	prev.next = newNode
	newNode.prev = prev

	return head
}

const insertFront = (head, data) => {
	const newNode = new Node(data)

	if (head == void(0)) {
		return head = newNode
	}

	newNode.next = head 
	head.prev = newNode

	return newNode
}

const sortedInsertRecursive = (head, data) => {
	const newNode = new Node(data)

	if (head == void(0)) {
		return head = newNode
	} else if (data <= head.data) {
		newNode.next = head 
		head.prev = newNode
		return newNode
	} else {
		const rest = sortedInsertRecursive(head.next, data)
		head.next = rest 
		rest.prev = head 
		return head
	}
}

const values = (list) => {
	const result = []

	if (list == void(0)) {
		return result
	}

	let current = list.next 

	while (current) {
		result.push(current.data)
		current = current.next 
	}

	return result
}

const valuesWithHead = (list) => {
	const result = []

	if (list == void(0)) return result

	let current = list

	while (current) {
		result.push(current.data)
		current = current.next
	}

	return result
}

const reverse = (head) => {
	if (head == void(0) || head.next == void(0)) {
		return head
	}

	let current = head
	let newHead = void(0)

	while (current) {
		newHead = insertFront(newHead, current.data)
		current = current.next
	}

	return newHead
}

module.exports = {
	sortedInsert,
	sortedInsertRecursive,
	valuesWithHead,
	values,
	reverse,
	insert, 
}