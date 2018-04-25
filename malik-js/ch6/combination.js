const factorial = require('./fact')

function combination(n, r) {
    return Math.round(factorial(n) / (factorial(r) * factorial(n - r)))
}

module.exports = combination
