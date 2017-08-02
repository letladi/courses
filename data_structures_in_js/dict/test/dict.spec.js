const Dict = require('../dict')
const expect = require('expect')

describe('Dictionary', () => {

	let dict = null

	const oneKey = 1
	const oneStringKey = '1'
	const numKey = 'number'
	const value1 = 'value1'
	const value2 = 'value2'

	describe('#add', () => {
		

		beforeEach(() => {
			dict = new Dict()
		})
		afterEach(() => {
			dict = null
		})

		it('should accept integer keys', () => {
			dict.add(oneKey, value1)
			expect(dict.size()).toEqual(1)
		})
		it('should accept string keys', () => {
			dict.add(oneStringKey, value2)
			expect(dict.size()).toEqual(1)
		})
		it('should not add a string key if an integer key of the same value exists', () => {
			dict.add(oneKey, value1)
			dict.add(oneStringKey, value2)
			expect(dict.size()).toEqual(1)
		})
		it('should not add an integer key if a string key of the same value exists', () => {
			dict.add(oneStringKey, value1)
			dict.add(oneKey, value2)
			expect(dict.size()).toEqual(1)
		})
		it('should overwrite the value of a key if it already exists', () => {
			dict.add(oneKey, value1)
			dict.add(oneKey, value2)
			expect(dict.get(oneKey)).toEqual(value2)
		})
		it('throws an exception if a value for the key is not given', () => {
			expect(() => dict.add(oneKey)).toThrow()
		})
		it('throws an exception if a key is not a number or string', () => {
			expect(() => dict.add(null, value1)).toThrow()
			expect(() => dict.add(undefined, value2)).toThrow()
			expect(() => dict.add([], value1)).toThrow()
			expect(() => dict.add({}, value2)).toThrow()
		})
	})

	describe('#size', () => {

		beforeEach(() => {
			dict = new Dict()
		})
		afterEach(() => {
			dict = null
		})

		it('should return 0 if the dict is empty', () => {
			expect(dict.size()).toEqual(0)
		})
		it('should return n: the number of values added to the dict', () => {
			dict.add(numKey, value1)
			dict.add(oneKey, value2)
			expect(dict.size()).toEqual(2)
		})
	})

	describe('#get', () => {

		beforeEach(() => {
			dict = new Dict()
		})
		afterEach(() => {
			dict = null
		})

		it('should return the value of a given key', () => {
			dict.add(oneKey, value1)
			expect(dict.get(oneKey)).toEqual(value1)
		})
		it('should return "undefined" if the value of the given key does not exist', () => {
			dict.add(oneStringKey, value1)
			expect(dict.get('randomKey')).toEqual(undefined)
		})
		it('it should return the value of an integer key even if the value was saved with a string key', () => {
			dict.add(oneStringKey, value1)
			expect(dict.get(oneKey)).toEqual(value1)
		})
		it('it should return the value of a string key even if the value was saved with a number key', () => {
			dict.add(oneKey, value1)
			expect(dict.get(oneStringKey)).toEqual(value1)
		})
	})

	describe('#remove', () => {
		beforeEach(() => {
			dict = new Dict()
		})
		afterEach(() => {
			dict = null
		})

		it('remove the value of the given key', () => {
			dict.add(oneKey, value1)
			expect(dict.get(oneKey)).toEqual(value1)
			dict.remove(oneKey)
			expect(dict.get(oneKey)).toEqual(undefined)
		})
	})

})