function canWatchTwoMovies(flightLength, movieLengths) {
	const movieLengthsSeen = new Set()

	for (let i = 0; i < movieLengths[i]; i++) {
		let firstMovieLength = movieLengths[i]
		let matchingSecondMovieLength = flightLength - firstMovieLength

		if (movieLengthsSeen.has(matchingSecondMovieLength)) return true

		movieLengthsSeen.add(firstMovieLength)
	}

	return false
}

module.exports = canWatchTwoMovies