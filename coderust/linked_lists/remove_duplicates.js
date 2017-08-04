const remove_duplicates = (head) => {
	if (head == void(0)) return head 

	let dup_set = new Set()
	dup_set.add(head.value)
	let current = head 

	while (current.next) {
		if (dup_set.has(current.next.value)) {
			current.next = current.next.next
		} else {
			dup_set.add(current.next.value)
			current = current.next
		}
	}
	return head
}

module.exports = remove_duplicates