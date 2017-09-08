const { expect } = require('chai')
const { Node, preOrder, postOrder, inOrder, height } = require('./tree')

describe('Tree Data Structure', () => {
	const tree = new Node(1)
	const firstBranch = new Node(2)
	const secondBranch = new Node(5)
	const leftThirdBranch = new Node(3)
	const rightThirdBranch = new Node(6)
	fourthBranch = new Node(4)

	tree.right = firstBranch
	firstBranch.right = secondBranch
	secondBranch.left = leftThirdBranch
	secondBranch.right = rightThirdBranch
	leftThirdBranch.right = fourthBranch


	describe('#preOrder', () => {
		const preOrderValues = [1, 2, 5, 3, 4, 6]
		it('should return an array of the values in pre-order', () => {
			expect(preOrder(tree)).to.eql(preOrderValues)
		})
	})

	describe('#postOrder', () => {
		const postOrderValues = [4, 3, 6, 5, 2, 1]
		it('should return an array of the values in post-order', () => {
			expect(postOrder(tree)).to.eql(postOrderValues)
		})
	})

	describe('#inOrder', () => {
		const inOrderValues = [1, 2, 3, 4, 5, 6]
		it('should return an array of the values that have traversed in-order', () => {
			expect(inOrder(tree)).to.eql(inOrderValues)
		})
	})

	describe('#height', () => {

		it('should return height of a tree', () => {

			const tree = new Node(3)
			const leftFirstBranch = new Node(2)
			const rightFirstBranch = new Node(5)

			tree.left = leftFirstBranch
			tree.right = rightFirstBranch

			const firstLeftSecondBranch = new Node(1)
			leftFirstBranch.left = firstLeftSecondBranch

			const secondLeftSecondBranch = new Node(4)
			rightFirstBranch.left = secondLeftSecondBranch
			const rightSecondBranch = new Node(6)
			rightFirstBranch.right = rightSecondBranch

			const rightThirdBranch = new Node(7)
			rightSecondBranch.right = rightThirdBranch

			const leftFourthBranch = new Node(10)
			rightThirdBranch.left = leftFourthBranch

			expect(height(tree)).to.eql(4)
		})

		it('should return the proper height for a binary tree', () => {
			const tree = new Node(10)
			const leftFirstBranch = new Node(5)
			const rightFirstBranch = new Node(30)
			tree.left = leftFirstBranch
			tree.right = rightFirstBranch

			const leftLeftSecondBranch = new Node(4)
			const rightLeftSecondBranch = new Node(8)
			leftFirstBranch.left = leftLeftSecondBranch
			leftFirstBranch.right = rightLeftSecondBranch

			const leftRightSecondBranch = new Node(28)
			const rightRightSecondBranch = new Node(42)
			rightFirstBranch.left = leftRightSecondBranch
			rightFirstBranch.right = rightRightSecondBranch

			expect(height(tree)).to.eql(2)
		})

		it('should return zero for a tree with only one node', () => {
			const tree = new Node(10)

			expect(height(tree)).to.eql(0)
		})

	})
})