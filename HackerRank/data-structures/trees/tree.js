class Node {
	constructor(data) {
		this.data = data
		this.left = null 
		this.right = null
	}
}

const preOrder = (tree) => {
	const values = []

	const preOrderImpl = (tree) => {
		if (tree == void(0)) return void(0)

		values.push(tree.data)
		preOrderImpl(tree.left)
		preOrderImpl(tree.right)
	}

	preOrderImpl(tree)

	return values
}

const postOrder = (tree) => {
	const values = []

	const postOrderImpl = (tree) => {
		if (tree == void(0)) return void(0)

		postOrderImpl(tree.left)
		postOrderImpl(tree.right)
		values.push(tree.data)
	}

	postOrderImpl(tree)

	return values
}

const inOrder = (tree) => {
	const values = []

	const inOrderImpl = (tree) => {
		if (tree == void(0)) return void(0)

		inOrderImpl(tree.left)
		values.push(tree.data)
		inOrderImpl(tree.right)
	}

	inOrderImpl(tree)

	return values
}

const height = (tree) => {
	if (tree == void(0)) {
		return -1
	} else {
		return Math.max(1 + height(tree.left), 1 + height(tree.right)) 
	}
}

module.exports = {
	Node,
	preOrder,
	postOrder,
	inOrder,
	height,
}