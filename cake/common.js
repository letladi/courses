class LinkedListNode {
	constructor(value) {
		this.value = value 
		this.next = null
	}
}

const listValues = (list) => {
	const result = []
	let current = list 

	while (current) {
		result.push(current.value)
		current = current.next
	}

	return result
}

module.exports = {
	LinkedListNode,
	listValues,
}