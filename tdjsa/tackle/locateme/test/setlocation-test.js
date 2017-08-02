describe('setLocation test', () => {
	it('should set the URL into location of window', () => {
		const windowStub = {}
		const url = `http://example.com`
		setLocation(windowStub, url)

		expect(windowStub.location).to.be.eql(url)
	})
})