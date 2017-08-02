describe('onError test', () => {
	it('should set the error DOM element', () => {
		const domElement = { innerHTML: ''}
		sandbox.stub(document, 'getElementById')
			.withArgs('error')
			.returns(domElement)

		const message = "you're kidding"
		const positionError = { message }

		onError(positionError)

		expect(domElement.innerHTML).to.be.eql(message)
	})
})