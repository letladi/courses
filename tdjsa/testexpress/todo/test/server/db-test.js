const { expect } = require('chai')
const db = require('../../db')

describe('db tests', () => {
	it('should pass this canary test', () => {
		expect(true).to.be.true
	})

	describe('#get', () => {
		it('should return null connection by default', () => {
			expect(db.get()).to.be.null
		})
	})

	describe('#close', () => {
		it('should set connection to null', () => {
			db.close()
			expect(db.connection).to.be.null
		})

		it('should close existing connection', (done) => {
			db.connection = { close() { done() } }
			db.close()
			expect(db.connection).to.be.null
		})
	})

	describe('#connect', () => {
		it('should set connection given valid database name', (done) => {
			const cb = (err) => {
				expect(err).to.be.null
				expect(db.get().databaseName).to.be.eql('todotest')
				db.close()
				done()
			}

			db.connect('mongodb://localhost/todotest', cb)
		})
	}) 
})