const expect = require('expect')
const maxDuffelBagValue = require('../problem-16')

describe('maxDuffelBagValue', () => {
	const cakeTypes = [
    {weight: 7, value: 160},
    {weight: 3, value: 90},
    {weight: 2, value: 15},
	]

	capacity = 20

	xit(`should return 555 cakes (${cakeTypes.toString()}) with bag capacity 20`, () => {
		expect(maxDuffelBagValue(cakeTypes, capacity)).toEqual(555)
	})
})