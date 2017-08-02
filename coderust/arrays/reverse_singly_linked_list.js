const reverse_list = (head) => {
	if (head == void(0) || head.next == void(0)) return head

	let current_head = head.next 
	let reversed_list = head 
	reversed_list.next = null
}

module.exports = reverse_list