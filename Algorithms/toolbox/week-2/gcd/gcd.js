var readline = require('readline')

process.stdin.setEncoding('utf8')
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
})

rl.on('line', readLine)

function readLine (line) {
  if (line !== "\n") {
    const [a, b] = line.split(' ')
    console.log(gcd(a, b))
    process.exit()
  }
}

function gcd(a, b) {
	return (b == 0) ? a : gcd(b, a % b)
} 