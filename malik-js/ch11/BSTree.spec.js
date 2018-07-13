const BSTree = require('./BSTree')

describe('BSTree', () => {
  let tree = null
  beforeEach(() => tree = new BSTree())
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
  })

  describe('.leaveCount', () => {
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

  describe('#insert', () => {
    test('returns true if insertion succeeded', () => {
      expect(tree.insert(10)).toEqual(true)
    })
    test('returns false if insertion failed (like in the case of duplicates)', () => {
      tree.insert(10)
      expect(tree.insert(10)).toEqual(false)
    })
    test('shoule increase number of nodes in the tree', () => {
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
  })

  describe('#inOrder', () => {
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

  describe('#preOrder', () => {
    test('pre-order tree traversal', () => {
      const nums = [60, 70, 50, 30, 58, 80, 77, 46]
      nums.forEach((n) => tree.insert(n))
      const expectedPreOrderSequence = [60, 50, 30, 46, 58, 70, 80, 77]
      const resultingPreOrderSequence = []
      tree.preOrder((el) => resultingPreOrderSequence.push(el))
      expect(expectedPreOrderSequence).toEqual(resultingPreOrderSequence)
    })
  })

  describe('#postOrder', () => {
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

  describe('#singleParent', () => {
    test('returns 0 for an empty tree', () => {
      expect(tree.singleParent()).toEqual(0)
    })
    test('returns 0 for a tree with only one node', () => {
      tree.insert(1)
      expect(tree.singleParent()).toEqual(0)
    })
    test('returns number of parents with only one node', () => {
      const nums = [60, 70, 50, 30, 58, 80, 77, 46]
      nums.forEach((n) => tree.insert(n))
      expect(tree.singleParent()).toEqual(3)
    })
    test('returns zero for a tree with many nodes but no single parent', () => {
      const nums = [60, 50, 90, 40, 55, 85, 95]
      nums.forEach((n) => tree.insert(n))
      expect(tree.singleParent()).toEqual(0)
    })
    test('n elements inserted in sorted order will result in n-1 single parents', () => {
      const nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
      nums.forEach((n) => tree.insert(n))
      expect(tree.singleParent()).toEqual(9)
    })
  })

  describe('#iterativeInOrder', () => {
    test('in-order tree traversal', () => {
      const nums = [60, 70, 50, 30, 58, 80, 77, 46]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequence = [30, 46, 50, 58, 60, 70, 77, 80]
      const resultingInOrderSequence = []
      tree.iterativeInOrder(function(el) {
        resultingInOrderSequence.push(el)
      })
      expect(expectedInOrderSequence).toEqual(resultingInOrderSequence)
    })
  })

  describe('#iterativePreOrder', () => {
    test('pre-order tree traversal', () => {
      const nums = [60, 70, 50, 30, 58, 80, 77, 46]
      nums.forEach((n) => tree.insert(n))
      const expectedPreOrderSequence = [60, 50, 30, 46, 58, 70, 80, 77]
      const resultingPreOrderSequence = []
      tree.iterativePreOrder((el) => resultingPreOrderSequence.push(el))
      expect(expectedPreOrderSequence).toEqual(resultingPreOrderSequence)
    })
  })

  describe('#iterativePostOrder', () => {
    test('post-order tree traversal', () => {
      const nums = [60, 70, 50, 30, 58, 80, 77, 46]
      nums.forEach((n) => tree.insert(n))
      const expectedPostOrderSequence = [46, 30, 58, 50, 77, 80, 70, 60]
      const resultingPostOrderSequence = []
      tree.iterativePostOrder((el) => resultingPostOrderSequence.push(el))
      expect(expectedPostOrderSequence).toEqual(resultingPostOrderSequence)
    })
  })

  describe('#delete', () => {
    test('should delete a node with no right subtree', () => {
      const nums = [60, 50, 70, 30, 53, 80, 75, 77, 57, 35, 32, 40, 48, 45]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequenceAfterDeletion = [30, 32, 35, 40, 48, 50, 53, 57, 60, 70, 75, 77, 80]
      const resultingInOrderSequenceAfterDeletion = []
      tree.delete(45)
      tree.inOrder((el) => resultingInOrderSequenceAfterDeletion.push(el))
      expect(resultingInOrderSequenceAfterDeletion).toEqual(expectedInOrderSequenceAfterDeletion)
    })
    test('should delete a node with no left subtree', () => {
      const nums = [60, 50, 70, 30, 53, 80, 75, 77, 57, 35, 32, 40, 48, 45]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequenceAfterDeletion = [32, 35, 40, 45, 48, 50, 53, 57, 60, 70, 75, 77, 80]
      const resultingInOrderSequenceAfterDeletion = []
      tree.delete(30)
      tree.inOrder((el) => resultingInOrderSequenceAfterDeletion.push(el))
      expect(resultingInOrderSequenceAfterDeletion).toEqual(expectedInOrderSequenceAfterDeletion)
    })
    test('should delete a node no left and right subtree', () => {
      const nums = [60, 50, 70, 30, 53, 80, 75, 77, 57, 35, 32, 40, 48, 45]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequenceAfterDeletion = [30, 32, 35, 40, 45, 48, 50, 53, 57, 60, 70, 75, 77]
      const resultingInOrderSequenceAfterDeletion = []
      tree.delete(80)
      tree.inOrder((el) => resultingInOrderSequenceAfterDeletion.push(el))
      expect(resultingInOrderSequenceAfterDeletion).toEqual(expectedInOrderSequenceAfterDeletion)
    })
    test('should delete a node with non-empty left and right subtree', () => {
      const nums = [60, 50, 70, 30, 53, 80, 75, 77, 57, 35, 32, 40, 48, 45]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequenceAfterDeletion = [30, 32, 35, 40, 45, 48, 53, 57, 60, 70, 75, 77, 80]
      const resultingInOrderSequenceAfterDeletion = []
      tree.delete(50)
      tree.inOrder((el) => resultingInOrderSequenceAfterDeletion.push(el))
      expect(resultingInOrderSequenceAfterDeletion).toEqual(expectedInOrderSequenceAfterDeletion)
    })
    test('should return true if deletion succeeded', () => {
      const nums = [60, 50, 70, 30, 53, 80, 75, 77, 57, 35, 32, 40, 48, 45]
      nums.forEach((n) => tree.insert(n))
      expect(tree.delete(50)).toEqual(true)
    })
    test('should return false if we try delete from empty tree', () => {
      const nums = [60, 50, 70, 30, 53, 80, 75, 77, 57, 35, 32, 40, 48, 45]
      expect(tree.delete(120)).toEqual(false)
    })
    test('should return false if the item being deleted is not in the tree', () => {
      const nums = [60, 50, 70, 30, 53, 80, 75, 77, 57, 35, 32, 40, 48, 45]
      nums.forEach((n) => tree.insert(n))
      expect(tree.delete(150)).toEqual(false)
    })
  })

  describe('#topView', () => {
    test('example-1', () => {
      const nums = [20, 8, 22, 4, 12, 10, 14, 25]
      nums.forEach((n) => tree.insert(n))
      expect(tree.topView()).toEqual([20, 8, 22, 4, 25])
    })
    test('example-2', () => {
      const nums = [1, 2, 5, 3, 6, 4]
      nums.forEach((n) => tree.insert(n))
      expect(tree.topView()).toEqual([1, 2, 5, 6])
    })
  })
})
