const { expect } = require('chai')
const sinon = require('sinon')
const fs = require('fs')
const Stockfetch = require('../src/stockfetch')

describe('Stockfetch tests', () => {

	let stockfetch
	let sandbox

	beforeEach(() => {
		stockfetch = new Stockfetch()
		sandbox = sinon.sandbox.create()
	})

	afterEach(() => {
		sandbox.restore()
	})

	it('should pass this canary test', () => {
		expect(true).to.be.true
	})

	describe('#readTickersFile', () => {
		it('should invoke error handler for invalid file', (done) => {
			const onError = (err) => {
				expect(err).to.be.eql('Error reading file: InvalidFile')
				done()
			}

			sandbox.stub(fs, 'readFile', (fileName, cb) => {
				cb(new Error('failed'))
			})

			stockfetch.readTickersFile('InvalidFile', onError)
		})

		it('should invoke processTickers for valid file', (done) => {
			const rawData = 'GOOG\nAAPL\nORCL\nMSFT'
			const parsedData = ['GOOG', 'AAPL', 'ORCL', 'MSFT']

			sandbox.stub(stockfetch, 'parseTickers')
				.withArgs(rawData).returns(parsedData)

			sandbox.stub(stockfetch, 'processTickers', (data) => {
				expect(data).to.be.eql(parsedData)
				done()
			})

			sandbox.stub(fs, 'readFile', (fileName, cb) => {
				cb(void(0), rawData)
			})

			stockfetch.readTickersFile('tickets.txt')
		})

		it('should return error if given file is empty', (done) => {
			const onError = (err) => {
				expect(err).to.be.eql('File tickers.txt has invalid content')
				done()
			}

			sandbox.stub(stockfetch, 'parseTickers').withArgs('').returns([])

			sandbox.stub(fs, 'readFile', (fileName, cb) => {
				cb(null, '')
			})

			stockfetch.readTickersFile('tickers.txt', onError)
		})
	})

	describe('#parseTickers', () => {
		it('should return a list of tickers when given a string', () => {
			const rawData = 'GOOG\nAAPL\nORCL\nMSFT'
			const parsedData = ['GOOG', 'AAPL', 'ORCL', 'MSFT']

			const result = stockfetch.parseTickers(rawData)

			expect(result).to.eql(parsedData)
		})
		it('should return an empty array if content is empty', () => {
			const rawData = ''
			const parsedData = []

			const result = stockfetch.parseTickers(rawData)

			expect(result).to.eql(parsedData)
		})
		it('should return an empty array for white-space-only content', () => {
			const rawData = '          '
			const parsedData = []

			const result = stockfetch.parseTickers(rawData)

			expect(result).to.eql(parsedData)
		})
		it('should ignore unexpected format in content', () => {
			const rawData = 'AAPL  \nBla h\nGOOG\n\n   '
			const parsedData = ['GOOG']

			const result = stockfetch.parseTickers(rawData)

			expect(result).to.eql(parsedData)
		})
	})

	describe('#processTickers', () => {
		it('should call getPrice for each ticker symbol', () => {
			const stockfetchMock = sandbox.mock(stockfetch)
			stockfetchMock.expects('getPrice').withArgs('A')
			stockfetchMock.expects('getPrice').withArgs('B')
			stockfetchMock.expects('getPrice').withArgs('C')

			stockfetch.processTickers(['A', 'B', 'C'])
			stockfetchMock.verify()
		})
		it('should save tickers count', () => {
			sandbox.stub(stockfetch, 'getPrice')

			stockfetch.processTickers(['A', 'B', 'C'])
			expect(stockfetch.tickersCount).to.be.eql(3)
		})
	})

	describe('#getPrice', () => {
		it('should call get on http with valid URL', (done) => {
			const httpStub = sandbox.stub(stockfetch.http, 'get', (url) => {
				expect(url).to.eql(`http://ichart.finance.yahoo.com/table.csv?s=GOOG`)
				done()
				return { on: () => {} }
			})

			stockfetch.getPrice('GOOG')
		})
		it('should send a response handler to get', (done) => {
			const aHandler = () => {}

			sandbox.stub(stockfetch.processResponse, 'bind')
				.withArgs(stockfetch, 'GOOG')
				.returns(aHandler)

			const httpStub = sandbox.stub(stockfetch.http, 'get', (url, handler) => {
				expect(handler).to.be.eql(aHandler)
				done()
				return { on: () => {} }
			})

			stockfetch.getPrice('GOOG')
		})

		it('should register handler for failure to reach host', (done) => {
			const errorHandler = () => {}

			sandbox.stub(stockfetch.processHttpError, 'bind')
				.withArgs(stockfetch, 'GOOG')
				.returns(errorHandler)

			const onStub = (e, handler) => {
				expect(e).to.be.eql('error')
				expect(handler).to.be.eql(errorHandler)
				done()
			}

			sandbox.stub(stockfetch.http, 'get').returns({ on: onStub })

			stockfetch.getPrice('GOOG')
		})
	})

	describe('#processResponse', () => {
		it('should call parsePrice with  valid data', () => {
			let dataFunc
			let endFunc

			const response = {
				statusCode: 200, 
				on(e, handler) {
					if (e == 'data') dataFunc = handler
					if (e == 'end') endFunc = handler
				}
			}

			const parsePriceMock = sandbox.mock(stockfetch)
				.expects('parsePrice').withArgs('GOOG', 'some data')

			stockfetch.processResponse('GOOG', response)
			dataFunc('some ')
			dataFunc('data')
			endFunc()

			parsePriceMock.verify()
		})

		it('should call processError if response failed', () => {
			const response = { statusCode: 404 }

			const processErrorMock = sandbox.mock(stockfetch)
				.expects('processError')
				.withArgs('GOOG', 404)

			stockfetch.processResponse('GOOG', response)
			processErrorMock.verify()
		})

		it('should call processError only if response failed', () => {
			const response = { 
				statusCode: 200,
				on() {} 
			}

			const processErrorMock = sandbox.mock(stockfetch)
				.expects('processError')
				.never()

			stockfetch.processResponse('GOOG', response)
			processErrorMock.verify()
		})
	})

	describe('#processHttpError', () => {
		it('should call processError with error details', () => {
			const processErrorMock = sandbox.mock(stockfetch)
				.expects('processError')
				.withArgs('GOOG', '...error code...')

			const error = { code: '...error code...' }
			stockfetch.processHttpError('GOOG', error)
			processErrorMock.verify()
		})
	})

	​const data = ​`Date,Open,High,Low,Close,Volume,Adj Close\n\​​ ​2015-09-11,619.75,625.780029,617.419983,625.77002,1360900,625.77002\n\​​ ​2015-09-10,613.099976,624.159973,611.429993,621.349976,1900500,621.349976`
	describe('#parsePrice', () => {
		
		it('should update prices', () => {
			stockfetch.parsePrice('GOOG', data)

			expect(stockfetch.prices.GOOG).to.be.eql('625.77002')
		})

		it('should call printReport', () => {
			const printReportMock = sandbox.mock(stockfetch).expects('printReport')
			stockfetch.parsePrice('GOOG', data)
			printReportMock.verify()
		})
	})

})