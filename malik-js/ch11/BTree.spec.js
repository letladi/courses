const BTree = require('./BTree')

describe('BTree - order 5 tree', () => {
  let tree = null
  beforeEach(() => tree = new BTree(5))
  afterEach(() => tree = null)

  describe('.order=', () => {
    it('should not allow changing the order of the tree', () => {
      expect(() => tree.order = 3).toThrow()
    })
  })

  describe('#inOrder', () => {
    it('should do in order traversal')
  })
  describe('#preOrder', () => {
    it('should do pre order traversal')
  })
  describe('#postOrder', () => {
    it('should do post order traversal')
  })
  describe('#search', () => {
    it('should return true if the item is found in the tree')
    it('should return false if the item is not found in the tree')
  })
  describe('#insert', () => {
    // page 667. malik book
    it('returns false if the insertion failed (like when there is a duplicate)')
    it('returns true if the insertion succeeded')
    it('should increase the height of the tree', () => {
      const initElements = [5, 30, 40, 70]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.height).toEqual(0)
      tree.insert(16)
      expect(tree.height).toEqual(1)
    })
    it('should not increase height of the tree if elements are added to an existing node', () => {
      const initElements = [5, 30, 40, 70, 16]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.height).toEqual(1)
      const extraElements = [82, 95]
      extraElements.forEach((n) => tree.insert(n))
      expect(tree.height).toEqual(1)
    })
    it('should increase the number of leaves if the tree overflows', () => {
      const initElements = [5, 30, 40, 70]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.leaveCount).toEqual(0)
      tree.insert(16)
      expect(tree.leaveCount).toEqual(2)
    })

    it('should not increase the numnber of leaves if the tree does not overflow', () => {
      const initElements = [5, 30, 40, 70, 16]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.leaveCount).toEqual(2)
      tree.insert(82)
      tree.insert(95)
      expect(tree.leaveCount).toEqual(2)
    })

  })
  describe('#delete', () => {
    it('it can result in reducing the height of the b-tree')
    it('returns false if the deletion failed (like when the item is not in the tree)')
    it('returns true if the deletion succeeded')
  })
})
