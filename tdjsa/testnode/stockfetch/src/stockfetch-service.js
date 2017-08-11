const http = require('http')
const querystring = require('querystring')
const StockFetch = require('./stockfetch')

const handler = (req, res) => {
	const symbolsString = querystring.parse(req.url.split('?')[1]).s || ''

	if (symbolsString) {
		const stockfetch = new StockFetch()
		console.log('HERE IS THE SYMBOLS STRING', symbolsString)
		const tickers = symbolsString.split(',')
		stockfetch.reportCallback = (prices, errors) => {
			res.end(JSON.stringify({ prices, errors }))
		}

		stockfetch.processTickers(tickers)
	} else {
		res.end('invalid query, use format ?s=SYM1,SYM2')
	}
}

http.createServer(handler).listen(3001)