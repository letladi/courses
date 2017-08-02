class BinaryTreeNode {
	constructor(val) {
		this._value = val
		this._left = null
		this._right = null
	}

	insertLeft(val) {
		this._left = new BinaryTreeNode(val)
		return this._left
	}

	insertRight(val) {
		this._right = new BinaryTreeNode(val)
		return this._right
	}
}

function isBalanced(treeRoot) {
	if (treeRoot == void(0)) return true

	const depths = []

	const nodes = []
	nodes.push([treeRoot, 0])

	while (nodes.length) {
		let nodePair = nodes.pop()
		let node = nodePair[0]
		depth = nodePair[1]

		if (node.left == void(0) && void.right == void(0)) {
			if (depths.indexOf(depth) > 0) {
				depths.push(depth)

				if (depths.length > 2 || (depths.length == 2 && Math.abs(depths[0] - depths[1]) > 1)) {
					return false
				}
			}
		} else {
			if (node.left) {
				nodes.push([node.left, depth + 1])
			}
			if (node.right) {
				nodes.push([node.right, depth + 1])
			}
		}
	}

	return true
}

function isBinarySearchTree(treeRoot) {
	const nodeAndBoundsStack = []
	nodeAndBoundsStack.push({ node: treeRoot, lowerBound: -Infinity, upperBound: Infinity })

	while (nodeAndBoundsStack.length) {
		let nodeAndBounds = nodeAndBoundsStack.pop()
		let node = nodeAndBounds.node
		let lowerBound = nodeAndBounds.lowerBound
		let upperBound = nodeAndBounds.upperBound

		if (node.value <= lowerBound || node.value >= upperBound) {
			return false
		}

		if (node.left) {
			nodeAndBoundsStack.push({ node: node.left, lowerBound, upperBound: node.value })
		}

		if (node.right) {
			nodeAndBoundsStack.push({ node: node.right, lowerBound: node.value, upperBound })
		}
	}

	return true
}

function isBinarySearchTree(treeRoot, lowerBound = Number.NEGATIVE_INFINITY, upperBound = Number.POSITIVE_INFINITY) {
	if (treeRoot == void(0)) return true

	if (treeRoot.value >= upperBound || treeRoot.value <= lowerBound) {
		return false
	}

	return isBinarySearchTree(treeRoot.left, lowerBound, treeRoot.value) && isBinarySearchTree(treeRoot.right, treeRoot.value, upperBound)
}