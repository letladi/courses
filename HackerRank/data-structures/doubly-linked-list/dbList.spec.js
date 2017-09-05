const { expect } = require('chai')
const { values, insert, sortedInsert, sortedInsertRecursive, valuesWithHead, reverse } = require('./dbList')

describe('doubly-linked-list', () => {
	describe('#sortedInsert', () => {

		it('should have values 2<->4<->5 after inserting in order 2,5,4', () => {
			const valuesToBeInserted = [2, 5, 4]
			let list = void(0)
			const sortedValues = [2, 4, 5]
			valuesToBeInserted.forEach((el) => list = sortedInsert(list, el))

			expect(values(list)).to.eql(sortedValues)
		})

		it('should have values 1<->2<->3<->4 after inserting in order 2,1,4,3', () => {
			const valuesToBeInserted = [2, 1, 4, 3]
			let list = void(0)
			const sortedValues = [1, 2, 3, 4]
			valuesToBeInserted.forEach((el) => list = sortedInsert(list, el))

			expect(values(list)).to.eql(sortedValues)
		})

		it('should have values 1<->2<->3<->4<->6<->7<->9<->10 after inserting in order 1,4,2,3,7,6,9,10', () => {
			const valuesToBeInserted = [1, 4, 2, 3, 7, 6, 9, 10]
			let list = void(0)
			const sortedValues = [1, 2, 3, 4, 6, 7, 9, 10]
			valuesToBeInserted.forEach((el) => list = sortedInsert(list, el))

			expect(values(list)).to.eql(sortedValues)
		})
	})

	describe('#sortedInsertRecursive', () => {

		it('should have values 2<->4<->5 after inserting in order 2,5,4', () => {
			const valuesToBeInserted = [2, 5, 4]
			let list = void(0)
			const sortedValues = [2, 4, 5]
			valuesToBeInserted.forEach((el) => list = sortedInsertRecursive(list, el))

			expect(valuesWithHead(list)).to.eql(sortedValues)
		})

		it('should have values 1<->2<->3<->4 after inserting in order 2,1,4,3', () => {
			const valuesToBeInserted = [2, 1, 4, 3]
			let list = void(0)
			const sortedValues = [1, 2, 3, 4]
			valuesToBeInserted.forEach((el) => list = sortedInsertRecursive(list, el))

			expect(valuesWithHead(list)).to.eql(sortedValues)
		})

		it('should have values 1<->2<->3<->4<->6<->7<->9<->10 after inserting in order 1,4,2,3,7,6,9,10', () => {
			const valuesToBeInserted = [1, 4, 2, 3, 7, 6, 9, 10]
			let list = void(0)
			const sortedValues = [1, 2, 3, 4, 6, 7, 9, 10]
			valuesToBeInserted.forEach((el) => list = sortedInsertRecursive(list, el))

			expect(valuesWithHead(list)).to.eql(sortedValues)
		})
	})

	describe('#reverse', () => {
		it('should null given null', () => {
			const list = null
			expect(reverse(list)).to.eql(null)
		})
		it('should return null<->6<->4<->2<->null for null<->2<->4<->6<->null', () => {
			const valuesToBeInserted = [2, 4, 6]
			const reversedValues = [6, 4, 2]
			let list = void(0)
			valuesToBeInserted.forEach((el) => list = insert(list, el))

			const result = reverse(list)

			expect(valuesWithHead(result)).to.eql(reversedValues)
		})
	})
})