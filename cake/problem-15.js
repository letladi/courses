const numbers = [0, 1, 1]
let lastMinIndex = 3
const fib = (n) => {
	if (n < 0) throw new Error('Fibonacci number cannot have negative index')
		
	if (numbers[n] == void(0)) {
		while (lastMinIndex <= n) {
			numbers[lastMinIndex] = numbers[lastMinIndex - 1] + numbers[lastMinIndex - 2]
			lastMinIndex++
		}
	} 
	return numbers[n]
}

module.exports = fib