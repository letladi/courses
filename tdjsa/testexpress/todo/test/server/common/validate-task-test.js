const { expect } = require('chai')
const { validateTask } = require('../../../public/javascripts/common/validate-task')

describe('.validateTask tests', () => {
	let sampleTask

	beforeEach(() => {
		sampleTask = { name: 'a new task', month: 12, day: 10, year: 2016 }
	})

	const expectFailForProperty = (property, value) => {
		sampleTask[property] = value
		expect(validateTask(sampleTask)).to.be.false
	}

	const testForPresence = (prop) => {
		it(`should return false for undefined ${prop}`, () => {
			expectFailForProperty(prop)
		})

		it(`should return false for null ${prop}`, () => {
			expectFailForProperty(prop, null)
		})
	}

	const testForPresenceofNumeric = (prop) => {
		it('should return false for non number', () => {
			expectFailForProperty(prop, 'text')
		})
	}

	it(`should return false for empty name`, () => {
			expectFailForProperty('name', '')
	})


	it('should return true for valid task', () => {
		expect(validateTask(sampleTask)).to.be.true
	})

	it('should return false for undefined task', () => {
		expect(validateTask()).to.be.false
	})

	it('should return false for null task', () => {
		expect(validateTask(null)).to.be.false
	})

	testForPresence('name')
	testForPresence('month')
	testForPresenceofNumeric('month')
	testForPresenceofNumeric('year')
	testForPresenceofNumeric('day')


}) 