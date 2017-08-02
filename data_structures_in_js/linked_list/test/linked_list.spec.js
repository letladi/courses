const expect = require('expect')
const LinkedList = require('../')

describe('LinkedList',() => {
	let list = null

	const el1 = 'el1'
	const el2 = 'el2'
	const el3 = 'el3'

	beforeEach(() => {
		list = new LinkedList()
	})
	afterEach(() => {
		list = null
	})

	describe('#push', () => {
		it('should add the element to the linked list', () => {
			list.push(el1)
			expect(list.size())
		})
	})

	describe('#size', () => {
		it('should return 0 if there are no elements in the list', () => {
			expect(list.size()).toEqual(0)
		})
		it('should return n (the number of elements in the list)', () => {
			list.push(el1)
			list.push(el2)
			list.push(el3)

			expect(list.size()).toEqual(3)
		})
	})

	describe('#itemAt', () => {
		it('should return null if no element exists at the specified index', () => {
			list.push(el1)
			list.push(el2)
			list.push(el3)

			expect(list.itemAt(5)).toBe(null)
			expect(list.itemAt(-1)).toBe(null)
		})
		it('should return the element at the specified index', () => {
			list.push(el1)
			list.push(el2)
			list.push(el3)

			expect(list.itemAt(0)).toEqual(el1)
			expect(list.itemAt(1)).toEqual(el2)
			expect(list.itemAt(2)).toEqual(el3)
		})
	})

	describe('#remove', () => {
		it('should return null if the element does not exist in the list', () => {
			list.push(el1)
			list.push(el2)
			list.push(el3)

			expect(list.remove(-1)).toBe(null)
			expect(list.remove(5)).toBe(null)
		})
		it('should return the element if it exists in the list', () => {
			list.push(el1)
			list.push(el2)
			list.push(el3)
			
			expect(list.remove(2)).toEqual(el3)	
			expect(list.remove(1)).toEqual(el2)
			expect(list.remove(0)).toEqual(el1)
		})
		it('should remove the element from the list', () => {
			list.push(el1)
			list.push(el2)
			list.push(el3)

			expect(list.remove(0)).toEqual(el1)
			expect(list.itemAt(0)).toNotEqual(el1)
			expect(list.remove(1)).toEqual(el3)
			expect(list.remove(1)).toEqual(null)
		})
	})

	describe('#search', () => {
		beforeEach(() => {
			list.push(el1)
			list.push(el2)
			list.push(el3)
		})
		afterEach(() => {
			list = null
		})
		it('should return the index of the given value item if it exists', () => {
			expect(list.search(el2)).toEqual(1)
			expect(list.search(el3)).toEqual(2)
			expect(list.search(el1)).toEqual(0)
		})
		it('should return null if an item with the given value does not exist', () => {
			expect(list.search('el4')).toEqual(null)
		})
	})

})
