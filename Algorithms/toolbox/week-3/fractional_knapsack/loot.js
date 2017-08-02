var readline = require('readline')

process.stdin.setEncoding('utf8')
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
})

rl.on('line', readLine)

let readCount = 0
let capacity = null
let numInputs = null
const items = []

function readLine (line) {
  if (line !== "\n") {
    if (readCount == 0) {
    	[numInputs, capacity] = line.split(' ')
    } else {
    	let [value, weight] = line.split(' ')
    	value = +value
    	weight = +weight

    	items.push({ weight, value })
    }
    readCount++
    if (items.length == numInputs) {
    	console.log(getOptimalValue(capacity, items))
    	process.exit()
    }
  }
}

function getOptimalValue(capacity, items) {
	items.forEach((item, i) => {
		items[i].fraction = items[i].value / items[i].weight
	})

	// we sort items in descending order
	items = items.sort((item1, item2) => (item1.fraction < item2.fraction) ? 1 : -1)

	let result = 0
	let item = null
	while (items.length) {
		item = items.shift()

		if ((capacity - item.weight) >= 0) {
			capacity -= item.weight
			result += item.value
		} else if ((capacity - item.weight) < 0) {
			let fraction =  capacity / item.weight
			let fractionValue = item.value * fraction
			capacity -= capacity
			result += fractionValue
			break
		}
	}

	return result

}

module.exports = getOptimalValue