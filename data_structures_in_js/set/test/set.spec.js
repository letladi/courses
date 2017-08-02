const Set = require('../set')
const expect = require('expect')

describe('Set', () => {

	let set = null
	let elementToAdd = 'some-element'

	beforeEach(() => {
		set = new Set()
	})

	afterEach(() => {
		set = null
	})

	describe('#add', () => {
		it('should add element to the set', () => {
			expect(set.size()).toEqual(0)
			set.add(elementToAdd)
			expect(set.size()).toEqual(1)
		})
		it('does not add the element if it already exists in the Set', () => {
			expect(set.size()).toEqual(0)
			set.add(elementToAdd)
			set.add(elementToAdd)
			set.add(elementToAdd)
			expect(set.size()).toEqual(1)
		})
	})

	describe('#remove', () => {
		it('removes the element from the set', () => {
			set.add(elementToAdd)
			expect(set.size()).toEqual(1)
			set.remove(elementToAdd)
			expect(set.size()).toEqual(0)
		})
	})

	describe('#size', () => {
		const el1 = 'el1'
		const el2 = 'el2'
		const el3 = 'el3'

		beforeEach(() => {
			set.add(el1)
			set.add(el2)
			set.add(el3)
		})
		it('should return the number of elements in the Set', () => {
			expect(set.size()).toEqual(3)
		})
	})

	describe('#member', () => {
		const inside = 'inside'
		const outside = 'outside'
		beforeEach(() => {
			set.add(inside)
		})
		it('returns true if the given element exists in the set', () => {
			expect(set.member(inside)).toBeTruthy()
		})
		it('returns false if the given element does not exist in the set', () => {
			expect(set.member(outside)).toBeFalsy()
		})
	})

	describe('#union', () => {
		const name = 'Letladi'
		const siblings = ['Kapei', 'Adelaide', 'katlego', 'Mathokolle'] 
		const occupation = 'UX Designer/Developer'
		const salary = 150000
		const age = 29 

		const set1 = new Set()
		const set2 = new Set()
		const expectedUnion = new Set()

		beforeEach(() => {
			set1.add(name)
			set1.add(siblings)
			set1.add(occupation)

			set2.add(salary)
			set2.add(age)

			expectedUnion.add(name)
			expectedUnion.add(siblings)
			expectedUnion.add(occupation)
			expectedUnion.add(salary)
			expectedUnion.add(age)
		})

		it('should return a new set containing elements from both sets', () => {
			const union = set1.union(set2)
			expect(union).toEqual(expectedUnion)
		})
	})

	describe('#intersect', () => {
		const name = 'Letladi'
		const siblings = ['Kapei', 'Adelaide', 'katlego', 'Mathokolle'] 
		const occupation = 'UX Designer/Developer'
		const salary = 150000
		const age = 29 

		const set1 = new Set()
		const set2 = new Set()
		const expectedIntersection = new Set()

		beforeEach(() => {
			set1.add(name)
			set1.add(siblings)
			set1.add(occupation)

			set2.add(salary)
			set2.add(siblings)
			set2.add(age)

			expectedIntersection.add(siblings)
		})

		it('should return a new set containing elements common to each set', () => {
			const intersectionSet = set1.intersect(set2)
			intersectionSet.add(siblings)

			expect(intersectionSet).toEqual(expectedIntersection)
		})
	})

	describe('#difference', () => {

		const name = 'Letladi'
		const siblings = ['Kapei', 'Adelaide', 'katlego', 'Mathokolle'] 
		const occupation = 'UX Designer/Developer'
		const salary = 150000
		const age = 29 

		const set1 = new Set()
		const set2 = new Set()
		const expectedDifference = new Set()

		beforeEach(() => {
			set1.add(name)
			set1.add(siblings)
			set1.add(occupation)
			set1.add(age)

			set2.add(salary)
			set2.add(siblings)
			set2.add(age)

			expectedDifference.add(name)
			expectedDifference.add(occupation)
		})

		it('returns a new set containing elements in one set, and not in the given one', () => {
			expect(set1.difference(set2)).toEqual(expectedDifference)
		})
	})

})