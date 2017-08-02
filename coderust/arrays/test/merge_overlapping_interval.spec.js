const expect = require('expect')
const mergeOverlappingIntervals = require('../merge_overlapping_interval')

describe('merge overlapping intervals problem', () => {
	const meetingTimes = [
		{start: 1, end: 5}, {start: 3, end: 7}, {start: 4, end: 6},
		{start: 6, end: 8}, {start: 10, end: 12}, {start: 11, end: 15}
	]

	it(`should merge ${meetingTimes.toString()} into [{start:1, end:8}, {start:10, end: 15}]`, () => {
		const mergedTimes = mergeOverlappingIntervals(meetingTimes)
		expect(mergedTimes).toEqual([{ start: 1, end: 8 }, { start: 10, end: 15 }])
	})
})