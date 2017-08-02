describe('create-url test', () => {
	it('should return proper url given lat and long', () => {
		const latitude = -33.857
		const longitude = 151.215

		const url = createURL(latitude, longitude)

		expect(url).to.be.eql(`https://google.com?q=${latitude},${longitude}`)
	})

	it('should return proper url given another lat and long', () => {
		const latitude = -37.826
		const longitude = -122.423

		const url = createURL(latitude, longitude)

		expect(url).to.be.eql(`https://google.com?q=${latitude},${longitude}`)
	})

	it('should return empty string if latitude is undefined', () => {
		const latitude = undefined
		const longitude = 188.123

		const url = createURL(latitude, longitude)

		expect(url).to.be.eql('')
	})

	it('should return empty string if longitude is undefined', () => {
		const latitude = -40.234
		const longitude = undefined

		const url = createURL(latitude, longitude)

		expect(url).to.be.eql('')
	})
})