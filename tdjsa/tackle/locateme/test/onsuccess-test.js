xdescribe('onSuccess test', () => {
	it('should call createURL with latitude and longitude', () => {
		const createURLSpy = sandbox.spy(createURL)

		const position = { coords: { latitude: 40.41, longitude: -105.55 }}

		onSuccess(position)

		expect(createURLSpy).to.have.been.calledWith(40.41, -105.55)
	})

	it('should call setLocation with URL returned by createURL', () => {
		const url = 'http://www.example.com'

		sandbox.stub(createURL)
			.returns(url)

		const setLocationSpy = sandbox.spy(setLocation)

		const position = { coords: { latitude: 40.41, longitude: -105.55 }}
		onSuccess(position)

		expect(setLocationSpy).to.have.been.calledWith(window, url)
	})
})