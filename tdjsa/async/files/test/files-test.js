const expect = require('chai').expect
const linesCount = require('../src/files')

describe('test server-side callback', () => {
	it('should return correct lines count for a valid file', (done) => {
		const callback = (count) => {
			expect(count).to.be.eql(15)
			done()
		} 

		linesCount('src/files.js', callback)
	})

	it('should report error for an invalid file name', (done) => {
		const onError = (error) => {
			expect(error).to.be.eql('unable to open file src/flies.js')
			done()
		}
		linesCount('src/flies.js', undefined, onError)
	})
})