const expect = require('expect')
const { deleteNode, deletionNode, deletionErrorMsg, } = require('../problem-22')
const { LinkedListNode, listValues } = require('../common')

describe('problem-22', () => {
	it('should delete the given node, if it\'s in the middle', () => {
		const a = new LinkedListNode('A')
		const b = new LinkedListNode('B')
		const c = new LinkedListNode('C')

		const finalListValues = ['A', 'C']

		a.next = b
		b.next = c 

		deleteNode(b)

		expect(listValues(a)).toEqual(finalListValues)
	})

	it('should delete the given node, if it\'s the head', () => {
		const a = new LinkedListNode('A')
		const b = new LinkedListNode('B')
		const c = new LinkedListNode('C')

		const finalListValues = ['B', 'C']

		a.next = b
		b.next = c 

		deleteNode(a)

		expect(listValues(a)).toEqual(finalListValues)
	})

	it('should throw an error if the node is a tail', () => {
		const a = new LinkedListNode('A')
		const b = new LinkedListNode('B')
		const c = new LinkedListNode('C')

		a.next = b
		b.next = c 

		expect(() => deleteNode(c)).toThrow(deletionErrorMsg)
	})
}) 