function power(x, p, result = 1) {
    if (p === 0) return result
    else return power(x, p - 1, result * x)
}

module.exports = power
