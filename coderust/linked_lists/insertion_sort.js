const sorted_insert = (head, node) => {
	if (node == void(0)) return head 

	if (head == void(0) || node.value <= head.value) {
		node.next = head 
		return node
	}

	let curr = head 
	while (curr.next && (curr.next.value < node.value)) {
		curr = curr.next
	}

	node.next = curr.next 
	curr.next = node

	return head
}

const insertion_sort = (head) => {
	let sorted = null
	let curr = head 

	while (curr) {
		let temp = curr.next 
		sorted = sorted_insert(sorted, curr)
		curr = temp
	}

	return sorted
}

module.exports = insertion_sort