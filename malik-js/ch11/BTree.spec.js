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

  describe('.order', () => {
    it('should return the order of the tree', () => {
      expect(tree.order).toEqual(5)
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
    it('should return true if the item is found in the tree', () => {
      const initElements = [5, 30, 40, 70]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.search(40)).toEqual(true)
    })
    it('should return false if the item is not found in the tree', () => {
      const initElements = [5, 30, 40, 70]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.search(60)).toEqual(false)
    })
  })
  describe('#insert', () => {
    // page 667. malik book
    it('returns false if the insertion failed (like when there is a duplicate)', () => {
      const initElements = [5, 30, 40, 70]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.insert(5)).toEqual(false)
    })
    it('returns true if the insertion succeeded', () => {
      const initElements = [5, 30, 40, 70]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.insert(80)).toEqual(true)
    })
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
    it('it can result in reducing the height of the b-tree (when removing from right leaf)', () => {
      const initElements = [40, 30, 70, 5, 16]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.height).toEqual(1)
      tree.delete(40)
      expect(tree.height).toEqual(0)
    })
    it('it can result in reducing the height of the b-tree (when removing from left leaf)', () => {
      const initElements = [40, 30, 70, 5, 16]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.height).toEqual(1)
      tree.delete(16)
      expect(tree.height).toEqual(0)
    })
    it('it can result in reducing the number of leaves in the tree (when removing from middle leaf)', () => {
      const initElements = [40, 30, 70, 5, 16, 82, 95, 100]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.leaveCount).toEqual(3)
      tree.delete(40)
      expect(tree.leaveCount).toEqual(2)
    })
    it('it can result in reducing the number of leaves in the tree (when removing from left leaf)', () => {
      const initElements = [40, 30, 70, 5, 16, 82, 95, 100]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.leaveCount).toEqual(3)
      tree.delete(16)
      expect(tree.leaveCount).toEqual(2)
    })
    it('it can result in reducing the number of leaves in the tree (when removing from right leaf)', () => {
      const initElements = [40, 30, 70, 5, 16, 82, 95, 100]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.leaveCount).toEqual(3)
      tree.delete(100)
      expect(tree.leaveCount).toEqual(2)
    })
    it('returns false if the deletion failed (like when the item is not in the tree)', () => {
      const initElements = [5, 30, 40, 70, 16]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.delete(150)).toEqual(false)
    })
    it('returns true if the deletion succeeded', () => {
      const initElements = [5, 30, 40, 70]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.delete(5)).toEqual(true)
    })
    it('should not change tree structure (by reducing height) if we delete from a node with minimum number of keys still intact', () => {
      const initElements = [40, 30, 70, 5, 16, 82, 95]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.height).toEqual(1)
      tree.delete(70)
      expect(tree.height).toEqual(1)
    })
    it('should not change tree structure (by reducing leave count) if we delete from a node with minimum number of keys still intact', () => {
      const initElements = [40, 30, 70, 5, 16, 82, 95]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.leaveCount).toEqual(2)
      tree.delete(70)
      expect(tree.leaveCount).toEqual(2)
    })
    it('should not change height when left siblings have more keys', () => {
      const initElements = [40, 30, 70, 5, 20, 10]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.height).toEqual(1)
      tree.delete(40)
      expect(tree.height).toEqual(1)
    })
    it('should not change leave count when left siblings have more keys', () => {
      const initElements = [40, 30, 70, 5, 20, 10]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.leaveCount).toEqual(2)
      tree.delete(40)
      expect(tree.leaveCount).toEqual(2)
    })
    it('should not change height when right siblings have more keys', () => {
      const initElements = [40, 30, 70, 5, 20, 50]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.height).toEqual(1)
      tree.delete(20)
      expect(tree.height).toEqual(1)
    })
    it('should not change leave count when right siblings have more keys', () => {
      const initElements = [40, 30, 70, 5, 20, 50]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.leaveCount).toEqual(2)
      tree.delete(20)
      expect(tree.leaveCount).toEqual(2)
    })
    it('should delete key that is not in a leaf', () => {
      const initElements = [40, 30, 70, 5, 16, 82, 95, 100]
      initElements.forEach((n) => tree.insert(n))
      expect(tree.leaveCount).toEqual(3)
      tree.delete(30)
      expect(tree.leaveCount).toEqual(2)
    })
  })
})
