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
      const nums = [1, 3, 4, 5, 7, 8, 9, 11, 12]
      nums.forEach((n) => tree.insert(n))
      console.log('here is the tree', JSON.stringify(tree))
      expect(tree.leaveCount).toEqual(4)
    })
  })
})
