function toBin(n, binString = '') {
    if (n === 0) return binString
    else return toBin(Math.floor(n / 2), n % 2 + binString)
}

module.exports = toBin
