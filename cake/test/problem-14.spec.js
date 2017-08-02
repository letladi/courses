const expect = require('expect')
const canWatchTwoMovies = require('../problem-14.js')

describe('problem-14', () => {
	const flightTime = 200
	const movieLengths1 = [102, 101, 99, 98, 150, 65]
	const movieLengths2 = [103, 98, 101, 89, 120]
	it('should return true if there are two movie times whose sum equals the flight time', () => {
		expect(canWatchTwoMovies(flightTime, movieLengths1)).toEqual(true)
	})
	it('should return false if there are no movie times whose sum equals the flight time', () => {
		expect(canWatchTwoMovies(flightTime, movieLengths2)).toEqual(false)
	})	
	it('should return false if there are less than two movie lengths', () => {
		expect(canWatchTwoMovies(flightTime, [69])).toEqual(false)
	})
})