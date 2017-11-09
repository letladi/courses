const expect = require('expect')
const { LinkedListNode } = require('../common')
const { hasCycle } = require('../problem-23')

describe('problem-23', () => {
	it('should return false if the list does not have a cycle', () => {
		const a = new LinkedListNode('a')
		const b = new LinkedListNode('b')
		const c = new LinkedListNode('c')

		a.next = b
		b.next = c

		expect(hasCycle(a)).toBeFalsy()
	})

  it('should return true if the list has a cycle', () => {
    const a = new LinkedListNode('a')
    const b = new LinkedListNode('b')
    const c = new LinkedListNode('c')
    const d = new LinkedListNode('d')
    const e = new LinkedListNode('e')

    a.next = b
    b.next = c 
    c.next = d 
    d.next = e 
    e.next = b

    expect(hasCycle(a)).toBeTruthy()
  })
})