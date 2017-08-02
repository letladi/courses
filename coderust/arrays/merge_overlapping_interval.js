const mergeOverlappingIntervals = (meetings) => {
	const mergedTimes = []
	let mergeCount = 0
	mergedTimes[mergeCount] = meetings[0]

	for (let i = 1, len = meetings.length; i < len; i++) {
		let currentMeeting = meetings[i]
		let previousMeeting = mergedTimes[mergeCount]

		
		if (previousMeeting.end > currentMeeting.start) {
			previousMeeting.end = Math.max(previousMeeting.end, currentMeeting.end)
		} else {
			mergeCount++
			mergedTimes[mergeCount] = {
				start: currentMeeting.start,
				end: currentMeeting.end
			}
		}
	}

	return mergedTimes
}

module.exports = mergeOverlappingIntervals