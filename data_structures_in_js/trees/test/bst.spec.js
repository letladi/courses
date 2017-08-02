const expect = require('expect')
const BST = require('../bst')

describe('Binary Search Tree', () => {
	let bst = null
	const el1 = 'el1'
	const el2 = 'el2'

	beforeEach(() => {
		bst = new BST()
	})

	afterEach(() => {
		bst = null
	})

	describe('#insert', () => {
		it('should insert the element into the bst', () => {
			bst.insert(el1)
			expect(bst.contains(el1)).toBeTruthy()
		})
	})

	describe('#contains', () => {

		beforeEach(() => {
			bst.insert(el2)
		})

		afterEach(() => {
			bst = null
		})

		it('should return false if the bst does not contain the element', () => {
			expect(bst.contains(el2)).toBeTruthy()
		})
		it('should return true if the bst does contain the element', () => {
			expect(bst.contains(el1)).toBeFalsy()
		})
	})

	describe('traversal / removal / size', () => {
		const preOrderedList = [50, 40, 20, 45, 70, 60, 99]
		const inOrderList = [20, 40, 45, 50, 60, 70, 99]
		const postOrderList = [20, 45, 40, 60, 99, 70, 50]

		beforeEach(() => {
			bst.insert(50)
			bst.insert(40)
			bst.insert(70)
			bst.insert(20)
			bst.insert(45)
			bst.insert(60)
			bst.insert(99)
		})

		afterEach(() => {
			bst = null
		})

		describe('preOrder traversal', () => {
			it('should the pre-ordered elements', () => {
				expect(bst.preOrder()).toEqual(preOrderedList)
			})
		})

		describe('inOrder traversal', () => {
			it('should return the elements in order', () => {
				expect(bst.inOrder()).toEqual(inOrderList)
			})
		})

		describe('postOrder traversal', () => {
			it('should return the post-ordered elements', () => {
				expect(bst.postOrder()).toEqual(postOrderList)
			})
		})

		describe('#remove', () => {
			it('should remove the element from the bst', () => {
				bst.remove(40)
				expect(bst.inOrder()).toEqual([20, 45, 50, 60, 70, 99])
				bst.remove(70)
				expect(bst.inOrder()).toEqual([20, 45, 50, 60, 99])
			})
		})

		describe('#size', () => {
			it('should return the number of elements in the tree', () => {
				const size = bst.size()
				expect(size).toEqual(7)
			})
		})

	})

})
