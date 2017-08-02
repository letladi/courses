const fs = require('fs')
const http = require('http')

class Stockfetch {

	constructor() {
		this.tickersCount = 0
		this.http = http
	}


	readTickersFile(filename, onError) {
		fs.readFile(filename, (err, data) => {
			if (err) {
				onError(`Error reading file: ${filename}`)
			} else {
				const tickers  = this.parseTickers(data.toString())

				if (tickers.length) {
					this.processTickers(tickers)	
				} else {
					onError(`File ${filename} has invalid content`)
				}
				
			}
		})
	}

	parseTickers(data) {
		const isInRightFormat = (str) => {
			return str.trim().length && str.indexOf(' ') < 0
		}
		return data.split('\n').filter(isInRightFormat)
	}

	processTickers(tickers) {
		this.tickersCount = tickers.length
		tickers.forEach((ticker) => this.getPrice(ticker))
	}

	getPrice(symbol) {
		const url = `http://ichart.finance.yahoo.com/table.csv?s=${symbol}`
		this.http.get(url, this.processResponse.bind(this, symbol))
			.on('error', this.processHttpError.bind(this, symbol))
	}

	processResponse(symbol, res) {
		if (res.statusCode == 200) {
			let data = ''
			res.on('data', (chunk) => { data += chunk })
			res.on('end', () => { this.parsePrice(symbol, data) })
		} else {
			this.processError(symbol, res.statusCode)
		}
	}

	parsePrice() {}

	processHttpError(ticker, error) {
		this.processError(ticker, error.code)
	}

	processError() {}

}

module.exports = Stockfetch