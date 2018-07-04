const toOrderedLinkedList = require('./problem-10')
const BSTree = require('./BSTree')

describe('problem-10 function', () => {
  test('should turn the tree into an OrderedLinkedList', () => {
    const nums = [60, 70, 90, 20, 55, 88, 28]
    const tree = new BSTree()
    nums.forEach((n) => tree.insert(n))
    const expectedLinkedListEntries = [20, 28, 55, 60, 70, 88, 90]


    const list = toOrderedLinkedList(tree)
    const resultingListEntries = list.entries()
    expect(resultingListEntries).toEqual(expectedLinkedListEntries)
  })
})
