const chai = require('chai')
chai.use(require('chai-as-promised'))
const { expect } = chai
const linesCount = require('../src/files')

describe('test promises', () => {
	it('should return correct lines count for a valid file', function(done) {
		const checkCount = (count) => {
			expect(count).to.be.eql(15)
			done()
		}

		linesCount('src/files.js')
			.then(checkCount)
	})

	it('should return correct lines count - using return', () => {
		const cb = (count) => {
			expect(count).to.be.eql(15)
		}

		return linesCount('src/files.js').then(cb)
	})

	it('should return correct lines count - using eventually', () => {
		return expect(linesCount('src/files.js')).to.eventually.eql(15)
	})

	it('should report error for an invalid file name', (done) => {
		expect(linesCount('src/flies.js')).to.be.rejectedWith('unable to open file src/flies.js').notify(done)
	})
})