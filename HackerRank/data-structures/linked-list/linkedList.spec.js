const { expect } = require('chai')
const { inspect } = require('util')
const { removeDuplicates, Node, addEl, buildList } = require('./linkedList')

const listValues = (head) => {
	let current = head 
	values = []

	while (current) {
		values.push(current.data)
		current = current.data
	}
	return values
}

describe('Linked List methods', () => {
	describe('method to remove duplicates', () => {
		it('should return (1->2->3->4) for a list (1->2->2->3->3->4)', () => {
			const array = [1, 2, 2, 3, 3, 4]
			const noDupsArray = [1, 2, 3, 4]
			const head = buildList(array)
			const listWithoutDups = buildList(noDupsArray)
			expect(removeDuplicates(head)).to.eql(listWithoutDups)
		})
		it('should return (1) for a list (1->1->1->1->1->1->1', () => {
			const array = [1, 1, 1, 1, 1, 1, 1]
			const noDupsArray = [1]
			const head = buildList(array)
			const listWithoutDups = buildList(noDupsArray)
			expect(removeDuplicates(head)).to.eql(listWithoutDups)
		})
		it('should return (2->3->4->6) for a list (2->3->3->4->6)', () => {
			const array = [2, 3, 3, 4, 6]
			const noDupsArray = [2, 3, 4, 6]
			const head = buildList(array)
			const listWithoutDups = buildList(noDupsArray)
			expect(removeDuplicates(head)).to.eql(listWithoutDups)
		})
		it('should return (10) for a list (10)', () => {
			const array = [10]
			const noDupsArray = [10]
			const head = buildList(array)
			const listWithoutDups = buildList(noDupsArray)
			expect(removeDuplicates(head)).to.eql(listWithoutDups)
		})
	})
})