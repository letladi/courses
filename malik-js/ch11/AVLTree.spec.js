const AVLTree = require('./AVLTree')

describe('AVLTree', () => {
  let tree = null
  beforeEach(() => tree = new AVLTree())
  afterEach(() => tree = null)

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

  describe('.height', () => {
    test('returns the height of the tree', () => {
      const nums = [60, 70, 90, 20, 55, 88, 28]
      nums.forEach((n) => tree.insert(n))
      expect(tree.height).toEqual(3)
    })
  })

  describe('#inOrder', () => {
    test('in-order tree traversal', () => {
      const nums = [40, 30, 20, 60, 50, 80, 15, 28, 25]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequence = [15, 20, 25, 28, 30, 40, 50, 60, 80]
      const resultingInOrderSequence = []
      tree.inOrder(function(el) {
        resultingInOrderSequence.push(el)
      })
      expect(expectedInOrderSequence).toEqual(resultingInOrderSequence)
    })
  })

  describe('#preOrder', () => {
    test('pre-order tree traversal', () => {
      const nums = [40, 30, 20, 60, 50, 80, 15, 28, 25]
      nums.forEach((n) => tree.insert(n))
      const expectedPreOrderSequence = [50, 28, 20, 15, 25, 30, 40, 60, 80]
      const resultingPreOrderSequence = []
      tree.preOrder((el) => resultingPreOrderSequence.push(el))
      expect(expectedPreOrderSequence).toEqual(resultingPreOrderSequence)
    })
  })

  describe('#postOrder', () => {
    test('post-order tree traversal', () => {
      const nums = [40, 30, 20, 60, 50, 80, 15, 28, 25]
      nums.forEach((n) => tree.insert(n))
      const expectedPostOrderSequence = [15, 25, 20, 40, 30, 28, 80, 60, 50]
      const resultingPostOrderSequence = []
      tree.postOrder((el) => resultingPostOrderSequence.push(el))
      expect(expectedPostOrderSequence).toEqual(resultingPostOrderSequence)
    })
  })

  describe('#insert', () => {
    test('case-1 (pg.638 - in the malik book)', () => {
      const nums = [50, 40, 70, 80, 90]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequenceOfTree = [40, 50, 70, 80, 90]
      const resultingInOrderSequenceOfTree = []
      tree.inOrder((data) => resultingInOrderSequenceOfTree.push(data))
      expect(resultingInOrderSequenceOfTree).toEqual(expectedInOrderSequenceOfTree)
    })
    test('case-2 (pg. 639 - in the same book)', () => {
      const nums = [50, 40, 70, 80, 75]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequenceOfTree = [40, 50, 70, 75, 80]
      const resultingInOrderSequenceOfTree = []
      tree.inOrder((data) => resultingInOrderSequenceOfTree.push(data))
      expect(resultingInOrderSequenceOfTree).toEqual(expectedInOrderSequenceOfTree)
    })
    test('case-3 (pg. 640 - fig.11-16)', () => {
      const nums = [50, 40, 75, 30, 45, 60, 80, 55, 78, 90, 95]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequenceOfTree = [30, 40, 45, 50, 55, 60, 75, 78, 80, 90, 95]
      const resultingInOrderSequenceOfTree = []
      tree.inOrder((data) => resultingInOrderSequenceOfTree.push(data))
      expect(resultingInOrderSequenceOfTree).toEqual(expectedInOrderSequenceOfTree)
    })
    test('case-4 (pg. 640 - fig.11-17)', () => {
      const nums = [50, 35, 80, 30, 70, 90, 85, 98, 88]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequenceOfTree = [30, 35, 50, 70, 80, 85, 88, 90, 98]
      const resultingInOrderSequenceOfTree = []
      tree.inOrder((data) => resultingInOrderSequenceOfTree.push(data))
      expect(resultingInOrderSequenceOfTree).toEqual(expectedInOrderSequenceOfTree)
    })
    test('case-5 (pg. 650 - fig.11-23; insertion with double rotation)', () => {
      const nums = [40, 30, 20, 60, 50, 80, 15, 28, 25]
      nums.forEach((n) => tree.insert(n))
      const expectedInOrderSequenceOfTree = [15, 20, 25, 28, 30, 40, 50, 60, 80]
      const resultingInOrderSequenceOfTree = []
      tree.inOrder((data) => resultingInOrderSequenceOfTree.push(data))
      expect(resultingInOrderSequenceOfTree).toEqual(expectedInOrderSequenceOfTree)
    })
    test('returns false if the element already exists', () => {
      const nums = [40, 30, 20, 60, 50]
      nums.forEach((n) => tree.insert(n))
      expect(tree.insert(30)).toEqual(false)
    })
    test('returns true if the element if insertion succeeded', () => {
      const nums = [40, 30, 20, 60, 50]
      nums.forEach((n) => tree.insert(n))
      expect(tree.insert(80)).toEqual(true)
    })
    test('should increase the size of the tree', () => {
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

  describe('#delete', () => {
    it('returns false if deleting from an empty tree', () => {
      expect(tree.delete(50)).toEqual(false)
    })
    it('returns false if attempting to delete a node that does not exist', () => {
      const nums = [1,2,3,4,5]
      nums.forEach((n) => tree.insert(n))
      expect(tree.delete(10)).toEqual(false)
    })
    it('returns true if deletion succeeded', () => {
      const nums = [44, 78, 17, 32, 50, 88, 48, 62]
      nums.forEach((n) => tree.insert(n))
      expect(tree.delete(32)).toEqual(true)
    })
    it('should work', () => {
      const nums = [44, 78, 17, 32, 50, 88, 48, 62]
      nums.forEach((n) => tree.insert(n))
      expect(tree.height).toEqual(3)
      tree.delete(32)
      expect(tree.height).toEqual(2)
    })
    it('should work - (in order sequene should be proper)', () => {
      const nums = [44, 78, 17, 32, 50, 88, 48, 62]
      nums.forEach((n) => tree.insert(n))
      tree.delete(32)
      const expectedInOrderSequenceAfterDeletion = [17, 44, 48, 50, 62, 78, 88]
      const resultingInOrderSequenceAfterDeletion = []
      tree.inOrder((el) => resultingInOrderSequenceAfterDeletion.push(el))
      expect(resultingInOrderSequenceAfterDeletion).toEqual(expectedInOrderSequenceAfterDeletion)
    })
    it('should decrease the number of elements')
  })
})
