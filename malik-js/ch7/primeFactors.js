const primeSieve = require('./primeSieve')
const Stack = require('./stack')

const entries = (stack) => {
    const ret = []
    let i = 0
    while (stack.isEmpty() === false) {
        ret[i++] = stack.pop()
    }
    return ret
}

const primeFactors = (n) => {
    const primesLessThanN = primeSieve(n)
    const stack = new Stack()
    let i = 0
    while (n > 1 && i < n) {
        const prime =  primesLessThanN[i]
        if (n % prime === 0) {
           stack.push(prime)
           n /= prime
       } else {
           i++
       }
    }
    return entries(stack)
}

module.exports = primeFactors
