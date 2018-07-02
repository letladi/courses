const AVLTree = require('./AVLTree')

describe('AVLTree', () => {
  let tree = null
  beforeEach(() => tree = new AVLTree())
  afterEach(() => tree = null)

  describe('#insert', () => {
    test('case-1 (pg.638 - in the malik book)', () => {
      const nums = [50, 40, 70, 80]
      nums.forEach((n) => tree.insert(n))
      tree.insert(90)
      const expectedInOrderSequenceOfTree = [40, 50, 70, 80, 90]
      const resultingInOrderSequenceOfTree = []
      tree.inOrder((data) => resultingInOrderSequenceOfTree.push(data))
      expect(resultingInOrderSequenceOfTree).toEqual(expectedInOrderSequenceOfTree)
    })
    test('case-2 (pg. 639 - in the same book)', () => {
      const nums = [50, 40, 70, 80, 75]
      nums.forEach((n) => tree.insert(n))
      tree.insert(75)
      const expectedInOrderSequenceOfTree = [40, 50, 70, 75, 80]
      const resultingInOrderSequenceOfTree = []
      tree.inOrder((data) => resultingInOrderSequenceOfTree.push(data))
      expect(resultingInOrderSequenceOfTree).toEqual(expectedInOrderSequenceOfTree)
    })
    test('case-3 (pg. 640 - fig.11-16)', () => {
      const nums = [50, 40, 75, 30, 45, 60, 80, 55, 78, 90]
      nums.forEach((n) => tree.insert(n))
      tree.insert(95)
      const expectedInOrderSequenceOfTree = [30, 40, 45, 50, 55, 60, 75, 78, 80, 90, 95]
      const resultingInOrderSequenceOfTree = []
      tree.inOrder((data) => resultingInOrderSequenceOfTree.push(data))
      expect(resultingInOrderSequenceOfTree).toEqual(expectedInOrderSequenceOfTree)
    })
    test('case-4 (pg. 640 - fig.11-17)', () => {
      const nums = [50, 35, 80, 30, 70, 90, 85, 98]
      nums.forEach((n) => tree.insert(n))
      tree.insert(88)
      const expectedInOrderSequenceOfTree = [30, 35, 50, 70, 80, 85, 88, 90, 98]
      const resultingInOrderSequenceOfTree = []
      tree.inOrder((data) => resultingInOrderSequenceOfTree.push(data))
      expect(resultingInOrderSequenceOfTree).toEqual(expectedInOrderSequenceOfTree)
    })
    test('case-5 (pg. 650 - fig.11-23; insertion with double rotation)', () => {
      const nums = [40, 30, 20, 60, 50, 80, 15, 28]
      nums.forEach((n) => tree.insert(n))
      tree.insert(25)
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
    test('should increase the size of the tree')
  })
})
