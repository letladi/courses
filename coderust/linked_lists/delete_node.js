const delete_node = (head, key) => {
	let prev = null
	let current = head

	while (current) {
		if (current.value == key) {
			break
		}

		prev = current
		current = current.next
	}

	// if key not found
	if (current == void(0)) {
		return head
	}

	// key is on the head
	if (current == head) {
		return head = head.next
	}

	// for all other cases
	prev.next = current.next
	return head
}

module.exports = delete_node