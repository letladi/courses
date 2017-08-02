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
    console.log(fibonacci(n))
    process.exit()
  }
}

function fibonacci(n) {
  if (n <= 1) return n

  return this[n] = this[n] || fibonacci(n - 1) + fibonacci(n - 2)
}