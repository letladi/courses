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
    console.log(fibonacci_last_digit(n))
    process.exit()
  }
}

function fibonacci_last_digit(n) {
  const num_count = n+1
  const numbers = new Array(num_count)

  numbers.fill(0)

  numbers[0] = 0
  numbers[1] = 1

  for (let i = 2; i < num_count; i++) {
    numbers[i] = (numbers[i -1] + numbers[i - 2]) % 10
  }
  return numbers[n]
}