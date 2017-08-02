const expect = require('expect')
const rotationPoint = require('../problem-13')

describe('rotation point method', () => {
	const words = [
    'ptolemaic',
    'retrograde',
    'supplant',
    'undulate',
    'xenoepist',
    'asymptote', // <-- rotates here!
    'babka',
    'banoffee',
    'engender',
    'karpatka',
    'othellolagkage',
	];

	it('should work', () => {
		expect(rotationPoint(words)).toEqual(5)
	})
	
	it('should work with exercise example', () => {
		expect(rotationPoint(['k','v','a','b','c','d','e','g','i'])).toEqual(2)
	})
})