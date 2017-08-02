const expect = require('expect')
const reverse_list = require('../reverse_singly_linked_list')

describe('reversing a singly linked list', () => {
	const list = {
		value: 1,
		next: {
			value: 2,
			next: {
				value: 3,
				next: {
					value: 4,
					next: null
				}
			}
		}
	}
	const reversedList = {
		value: 4,
		next: {
			value: 3,
			next: {
				value: 2,
				next: {
					value: 1,
					next: null
				}
			}
		}
	}

	const oneElementList = {
		value: 50,
		next: null
	}

	const emptyList = null

	it('should reverse a singly linked list', () => {
		expect(reverse_list(list)).toEqual(reversedList)
	})
	it('should just return the list if it only has one element', () => {
		expect(reverse_list(oneElementList)).toEqual(oneElementList)
	})
	it('should just return the list if it is empty', () => {
		expect(reverse_list(emptyList)).toEqual(emptyList)
	})
})