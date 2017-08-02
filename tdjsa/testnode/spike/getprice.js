const http = require('http')

const getPriceTrial = (ticker) => {
	http.get(`http://ichart.finance.yahoo.com/table.csv?s=${ticker}`, (res) => {
		if (res.statusCode == 200) {
			let data = ''
			let getChunk = (chunk) { data += chunk }
			res.on('data', getChunk)
			res.end(() => {
				console.log('received data for', ticker)
				console.log(data)
			})
		} else {
			console.log(`${ticker} - error getting data: ${res.statusCode}`)
		}
	}).on('error', (err) => {
		console.log(`${ticker} - error getting data: ${err.code}`)
	})
}

getPriceTrial('GOOG')
getPriceTrial('INVALID')