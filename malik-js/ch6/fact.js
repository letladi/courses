function fact(n, product = 1) {
    if (n === 0) return product
    else return fact(n - 1, n * product)
}

module.exports = fact
