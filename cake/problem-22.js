const deletionErrorMsg = `Can't delete the last node with this method!`

const deleteNode = (node) => {
	
	const nextNode = node.next 

	if (nextNode) {
		node.value = nextNode.value
		node.next = nextNode.next
	} else {
		throw new Error(deletionErrorMsg)
	}
}

module.exports = {
	deleteNode,
	deletionErrorMsg,
}