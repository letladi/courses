const expect = require('expect')
const TempTracker = require('../problem-7')


describe('TempTracker', () => {
	let tracker = null
	beforeEach(() => {
		const numbers = [1, 3, 6, 3, 1, 3]
		tracker = new TempTracker()
		numbers.forEach((num) => tracker.insert(num))
	})
	afterEach(() => {
		tracker = null
	})

	describe('#getMax', () => {
		it('should the maximum number that has been inserted in the tracker', () => {
			expect(tracker.getMax()).toEqual(6)
		})
	})

	describe('#getMin', () => {
		it('should the minimum number that has been inserted in the tracker', () => {
			expect(tracker.getMin()).toEqual(1)
		})
	})

	describe('#getMean', () => {
		it('should return the mean of all the temperatures', () => {
			expect(tracker.getMean()).toEqual(2.8333333333333335)
		})
	})

	describe('#getMode', () => {
		it('should return the mode of the temperatures', () => {
			expect(tracker.getMode()).toEqual(3)
		})
		it('should return one of the modes if there is more than one', () => {
			const numbers = [3, 1, 3, 1, 6, 4, 5]
			tracker = null
			tracker = new TempTracker()
			numbers.forEach((num) => tracker.insert(num))

			const mode = tracker.getMode()

			expect(mode).toEqual(3)
		})
	})

})