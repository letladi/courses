function mergeRanges(array) {
	const startTimes = []
	const endTimes = []

	array = array.slice(0).sort((meeting1, meeting2) => {
		return meeting1.startTime > meeting2.startTime ? 1 : -1
	})

	let currentMeeting = array[0]
	let nextMeeting = array[1]

	let resultCount = 0
	const result = []
	result[resultCount] = currentMeeting

	let count = 0
	
	while (nextMeeting) {

		if (currentMeeting.endTime < nextMeeting.startTime) {
			result[resultCount].endTime = currentMeeting.endTime
			resultCount++
			result[resultCount] = nextMeeting
		} else {
			result[resultCount].endTime = nextMeeting.endTime
		}

		count++
		currentMeeting = nextMeeting
		nextMeeting = array[count]
	}

	return result
}


module.exports = mergeRanges