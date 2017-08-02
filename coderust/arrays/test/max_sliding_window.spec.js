const expect = require('expect')
const maxSlidingWindow = require('../max_sliding_window')

xdescribe('max sliding window problem', () => {
	it('should return [2,2,1,6] for array [-4,2,-5,1,-1,6]', () => {
		expect(maxSlidingWindow([-4, 2, -5, 1, -1, 6], 3)).toEqual([1,1,3,5])
	})
})