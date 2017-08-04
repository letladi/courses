const reverse_list = (head) => {
	if (head == void(0) || head.next == void(0)) return head

	let current_head = head.next 
	let reversed_head = head 
	reversed_head.next = null

	while (current_head) {
		let temp = current_head
		current_head = current_head.next 

		temp.next = reversed_head
		reversed_head = temp
	}

	return reversed_head
}

const reverse_recursive = (head) => {
	if (head == void(0) || head.next == void(0)) return head 

	const reversed_head = reverse_recursive(head.next)

	head.next.next = head 
	head.next = null

	return reversed_head
}

module.exports = reverse_recursive