describe('locate test', () => {
	it('should register handlers with getCurrentPosition', () => {
		const getCurrentPositionMock = sandbox.mock(navigator.geolocation)
																	   .expects('getCurrentPosition')
																	   .withArgs(onSuccess, onError)

		locate()

		getCurrentPositionMock.verify()
	})
})