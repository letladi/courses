const expect = require('expect')
const { reverse } = require('../problem-24')
const { LinkedListNode, listValues } = require('../common')

describe('reverse linked list', () => {
  it('should return a linked list', () => {
    const a = new LinkedListNode('a')
    const b = new LinkedListNode('b')
    const c = new LinkedListNode('c')
    const d = new LinkedListNode('d')
    const e = new LinkedListNode('e')

    a.next = b
    b.next = c 
    c.next = d 
    d.next = e 

    const expectedListValues = ['e', 'd', 'c', 'b', 'a']
    const reversedList = reverse(a)

    expect(listValues(reversedList)).toEqual(expectedListValues)

  })
})