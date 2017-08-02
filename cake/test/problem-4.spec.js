const expect = require('expect')
const mergeRanges = require('../problem-4')

describe('mergeRanges', () => {
	it('should work for two meetings', () => {
		const meetingTimes = [
			{ startTime: 1, endTime: 3 },
			{ startTime: 2, endTime: 4 }
		]

		const expectedMerge = [
			{ startTime: 1, endTime: 4 }
		]

		expect(mergeRanges(meetingTimes)).toEqual(expectedMerge)
	})
	it('should merge meeting time ranges', () => {
		const meetingTimes = [
	    {startTime: 0,  endTime: 1},
	    {startTime: 3,  endTime: 5},
	    {startTime: 4,  endTime: 8},
	    {startTime: 10, endTime: 12},
	    {startTime: 9,  endTime: 10},
		]

		const expectedMerge = [
    	{startTime: 0, endTime: 1},
    	{startTime: 3, endTime: 8},
    	{startTime: 9, endTime: 12},
		]

		expect(mergeRanges(meetingTimes)).toEqual(expectedMerge)
	})
})