const BinaryTree = require('./BinaryTree')

describe('BinaryTree', () => {
  let tree = null
  beforeEach(() => tree = new BinaryTree())
  afterEach(() =>  tree = null)
  describe('.nodeCount', () => {
    test('returns 0 if there are no nodes in the tree', () => {
      expect(tree.nodeCount).toEqual(0)
    })
    test('returns the number of nodes in the tree', () => {
      tree.insert(0)
      expect(tree.nodeCount).toEqual(1)
      tree.insert(1)
      expect(tree.nodeCount).toEqual(2)
      tree.insert(2)
      expect(tree.nodeCount).toEqual(3)
      tree.insert(3)
      tree.insert(4)
      expect(tree.nodeCount).toEqual(5)
    })
    test('returns true if insertion succeeded', () => {
      expect(tree.insert(10)).toEqual(true)
    })
    test('returns false if insertion failed (like in the case of duplicates)', () => {
      tree.insert(10)
      expect(tree.insert(10)).toEqual(false)
    })
  })

  describe('#leaveCount', () => {
    test('returns 0 if the tree is empty', () => {
      expect(tree.leaveCount).toEqual(0)
    })
    test('returns 1 if there is only one element in the tree', () => {
      tree.insert(1)
      expect(tree.leaveCount).toEqual(1)
    })
    test('returns 1 if there is a root with a left leaf', () => {
      tree.insert(10)
      tree.insert(5)
      expect(tree.leaveCount).toEqual(1)
    })
    test('returns 1 if there is a root with a right leaf', () => {
      tree.insert(10)
      tree.insert(15)
      expect(tree.leaveCount).toEqual(1)
    })
    test('count the number of leaves in a tree', () => {
      const nums = [60, 70, 50, 30, 58, 80, 77, 46]
      nums.forEach((n) => tree.insert(n))
      expect(tree.leaveCount).toEqual(3)
    })
  })

  describe('inOrder', () => {
    test('in-order tree traversal', () => {
      const nums = [60, 70, 50, 30, 58, 80, 77, 46]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequence = [30, 46, 50, 58, 60, 70, 77, 80]
      const resultingInOrderSequence = []
      tree.inOrder(function(el) {
        resultingInOrderSequence.push(el)
      })
      expect(expectedInOrderSequence).toEqual(resultingInOrderSequence)
    })
  })

  describe('preOrder', () => {
    test('pre-order tree traversal', () => {
      const nums = [60, 70, 50, 30, 58, 80, 77, 46]
      nums.forEach((n) => tree.insert(n))
      const expectedPreOrderSequence = [60, 50, 30, 46, 58, 70, 80, 77]
      const resultingPreOrderSequence = []
      tree.preOrder((el) => resultingPreOrderSequence.push(el))
      expect(expectedPreOrderSequence).toEqual(resultingPreOrderSequence)
    })
  })

  describe('postOrder', () => {
    test('post-order tree traversal', () => {
      const nums = [60, 70, 50, 30, 58, 80, 77, 46]
      nums.forEach((n) => tree.insert(n))
      const expectedPostOrderSequence = [46, 30, 58, 50, 77, 80, 70, 60]
      const resultingPostOrderSequence = []
      tree.postOrder((el) => resultingPostOrderSequence.push(el))
      expect(expectedPostOrderSequence).toEqual(resultingPostOrderSequence)
    })
  })

  describe('#swapSubtrees', () => {
    test('should swap left and right subtrees', () => {
      const nums = [60, 70, 50, 30, 58, 80, 77, 46]
      nums.forEach((n) => tree.insert(n))

      tree.swapSubtrees()

      const expectedInOrderSequenceOfSwappedTree = [80, 77, 70, 60, 58, 50, 46, 30]
      const resultingInOrderSequenceOfSwappedTree = []
      tree.inOrder((el) => resultingInOrderSequenceOfSwappedTree.push(el))

      expect(expectedInOrderSequenceOfSwappedTree).toEqual(resultingInOrderSequenceOfSwappedTree)
    })
  })
})
