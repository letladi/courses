var readline = require('readline')

process.stdin.setEncoding('utf8')
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
})

rl.on('line', readLine)

function readLine (line) {
  if (line !== "\n") {
    const n = line
    console.log(change(n))
    process.exit()
  }
}

const coins = [10, 5, 1]

function change(m) {
	let coinCount = 0

	let currentCoin = 0

	coins.forEach((coin) => {
		if (coin > m) currentCoin++
	})
	
	let coin = null
	while (m > 0) {
		coin = coins[currentCoin]

		if (coin > m) {
			currentCoin++
		} else {
			m -= coin	
			coinCount++
		}
	}

	return coinCount
}

module.exports = change 