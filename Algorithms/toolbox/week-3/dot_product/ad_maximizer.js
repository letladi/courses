var readline = require('readline')

process.stdin.setEncoding('utf8')
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
})

rl.on('line', readLine)

let readCount = 0
let adProfits = null
let slotClicks = null

function readLine (line) {
  if (line !== "\n") {
    if (readCount == 1) {
    	adProfits = line.split(' ')
    } else if (readCount == 2) {
    	slotClicks = line.split(' ')
    	console.log(maxAdProfit(adProfits, slotClicks))
    	process.exit()
    }
    readCount++ 
  }
}

function maxAdProfit(adProfits, slotClicks) {
	adProfits = adProfits.slice(0).sort((a, b) => (a > b) ? -1 : 1)
	slotClicks = slotClicks.slice(0).sort((a, b) => (a > b) ? -1 : 1)
	const slotCount = slotClicks.length
	let profit = 0

	for (let i = 0; i < slotCount; i++) {
		profit += adProfits[i] * slotClicks[i]
	}

	return profit
}

module.exports = {
	 maxAdProfit
}