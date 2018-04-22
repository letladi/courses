function nthFib (n, a1 = 1, a2 = 1) {
    if (n === 1) return a1
    else if (n === 2) return a2
    return this[n] = this[n] || nthFib(n - 1, a1, a2) + nthFib(n - 2, a1, a2)
}

module.exports = nthFib
