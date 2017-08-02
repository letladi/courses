describe('fetch location test', () => {
	it('should get lat and long from fetchLocation', function(done) {
		const onSuccess = (location) => {
			expect(location).to.have.property('lat')
			expect(location).to.have.property('lon')
			done()
		}

		const onError = (err) => {
			throw 'not expected'
		}

		this.timeout(10000)

		fetchLocation(onSuccess, onError)
	})
})