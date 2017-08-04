const { expect } = require('chai')
const remove_duplicates = require('../remove_duplicates')
const delete_node = require('../delete_node')
const reverse_list = require('../reverse_singly_linked_list')
const insertion_sort = require('../insertion_sort')

describe('linked list methods', () => {
	let item1, item2, item3, item4, item5, item6
	let item7, item8, item9, item10, item11

	after(() => {
		item1 = item2 = item3 = item4 = item5 = item6 = null
		item7 = item8 = item9 = item10 = item11 = null
	})
	
	describe('remove duplicates from linked list', () => {
		beforeEach(() => {
			item1 = {
				value: 7
			}
			item2 = {
				value: 14
			}
			item3 = {
				value: 28
			}
			item4 = {
				value: 28
			}
			item5 = {
				value: 14
			}
			item6 = {
				value: 21
			}

			item7 = {
				value: 7
			}
			item8 = {
				value: 14
			}
			item9 = {
				value: 28
			}
			item10 = {
				value: 21
			}
		})
		

		it('should remove duplicates from a list', () => {
			item1.next = item2
			item2.next = item3
			item3.next = item4
			item4.next = item5
			item5.next = item6
			item6.next = null

			item7.next = item8
			item8.next = item9
			item9.next = item10
			item10.next = null

			expect(remove_duplicates(item1)).to.eql(item7)
		})
	})

	describe('reversing a linked list', () => {
		beforeEach(() => {
			item1 = {
				value: 7
			}
			item2 = {
				value: 14
			}
			item3 = {
				value: 21
			}
			item4 = {
				value: 28
			}

			item5 = {
				value: 28
			}
			item6 = {
				value: 21
			}
			item7 = {
				value: 14
			}
			item8 = {
				value: 7
			}
		})

		it('should reverse a linked list', () => {
			item1.next = item2
			item2.next = item3
			item3.next = item4
			item4.next = null

			item5.next = item6
			item6.next = item7
			item7.next = item8
			item8.next = null

			expect(reverse_list(item1)).to.eql(item5)
		})
	})

	describe('delete node from linked list', () => {

		beforeEach(() => {
			item1 = {
				value: 7
			}
			item2 = {
				value: 14
			}
			item3 = {
				value: 21
			}
			item4 = {
				value: 28
			}
			item5 = {
				value: 35
			}
			item6 = {
				value: 42
			}

			item7 = {
				value: 7
			}
			item8 = {
				value: 14
			}
			item9 =  {
				value: 21
			}
			item10 = {
				value: 35
			}
			item11 = {
				value: 42
			}
		})

		it('should delete a node from a linked list', () => {
			item1.next = item2
			item2.next = item3
			item3.next = item4
			item4.next = item5
			item5.next = item6
			item6.next = null

			item7.next = item8
			item8.next = item9
			item9.next = item10
			item10.next = item11
			item11.next = null

			expect(delete_node(item1, 28)).to.eql(item7)
		})
	})

	describe('sort linked list using insertion sort', () => {
		beforeEach(() => {
			item1 = {
				value: 29
			}
			item2 = {
				value: 23
			}
			item3 = {
				value: 82
			}
			item4 = {
				value: 11
			}

			item5 = {
				value: 11
			}
			item6 = {
				value: 23
			}
			item7 =  {
				value: 29
			}
			item8 = {
				value: 82
			}
		})

		it('should sort the linked list using insertion sort', () => {
			item1.next = item2
			item2.next = item3
			item3.next = item4
			item4.next = null 

			item5.next = item6
			item6.next = item7
			item7.next = item8
			item8.next = null

			expect(insertion_sort(item1)).to.eql(item5)
		})
	})
})

