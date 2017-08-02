const {expect} = require('chai')
const {f2c}= require('../src/util')

describe('util tests', () => {
	it('should pass if f2c returns 0C ofr 32F', () => {
		const fahrenheit = 32

		const celcius = f2c(fahrenheit)

		expect(celcius).to.eql(0)
	})

	it('should pass if f2c return 10C for 50F', () => {
		const fahrenheit = 50

		const celcius = f2c(fahrenheit)

		expect(celcius).to.eql(10)
	})
})