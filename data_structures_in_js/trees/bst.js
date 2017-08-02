class Node {
	constructor(data) {
		this.data = data 
		this.left = null
		this.right = null
	}
}

class BST {
	constructor() {
		this._root = null
		this._size = 0
	}

	insert(data) {
		const node = new Node(data)

		this._size++

		if (this._root == null) {
			this._root = node 
			return
		}

		let current = this._root

		while (current) {

			if (data < current.data) {
				if (current.left == null) {
					current.left = node 
					return
				}
				current = current.left
			} else if (data > current.data) {
				if (current.right == null) {
					current.right = node 
					return 
				}
				current = current.right
			} else {
				return
			} 
		}
	}

	size() {
		return this._size
	}

	contains(data) {
		let current = this._root

		while (current) {
			if (data == current.data) {
				return true
			}

			if (data < current.data) {
				current = current.left
			} else if (data > current.data) {
				current = current.right
			}
		}

		return false
	}

	preOrder() {
		const output = []

		function preOrderImp(node) {
			if (node == void(0)) return 

			output.push(node.data)

			preOrderImp(node.left)

			preOrderImp(node.right)
		}

		preOrderImp(this._root)

		return output
	}

	inOrder() {
		const output = []

		function inOrderImpl(node) {
			if (node == void(0)) return

			inOrderImpl(node.left)

			output.push(node.data)

			inOrderImpl(node.right)
		}

		inOrderImpl(this._root)

		return output
	}

	postOrder() {
		const output = []

		function postOrderImpl(node) {
			if (node == void(0)) return

			postOrderImpl(node.left)
			postOrderImpl(node.right)
			output.push(node.data)
		}

		postOrderImpl(this._root)

		return output
	}

	maximum(node) {
		while (node.right) {
			node = node.right
		}
		return node.data
	}

	remove(key) {
		const node = this._removeImpl(key, this._root)
		if (node) {
			this._size--
			return node
		}
	}

	_removeImpl(key, node) {
		if (node != null) {
			if (key < node.data) {
				node.left = this._removeImpl(key, node.left)
			} else if (key > node.data) {
				node.right = this._removeImpl(key, node.right)
			} else {

				if (node.left && node.right) {
					node.data = this.maximum(node.left)
					node.left = this._removeImpl(node.data, node.left)
				} else {
					node = node.left || node.right
				}
			}
		}
		return node
	}
}

module.exports = BST