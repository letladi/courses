const addEl = (head, data) => {

	if (head == void(0)) {
		return head = new Node(data)
	}

	let current = head 

	while (current.next) {
		current = current.next
	}
	current.next = new Node(data)
	return head
}

const buildList = (array) => {
	let head = void(0)

	array.forEach((el) => {
		head = addEl(head, el)
	})

	return head
}

class Node {
	constructor(data) {
		this.data = data 
		this.next = null
	}
}

function removeDuplicates(head) {
	if (head == void(0) || head.next == void(0)) {
		return head
	}

	const encountered = {
		[head.data]: true
	}

	let current = head.next
	let newList = null

	while (current) {
		if (encountered[current.data] == void(0)) {
			newList = addEl(newList, current.data)
			encountered[current.data] = true
		}
		current = current.next
	}

	head.next = newList
	return head
}

module.exports = {
	Node,
	removeDuplicates,
	addEl,
	buildList
}