function mult(x, y, sum = 0) {
    if (y === 0) return sum
    else return mult(x, y - 1, sum + x)
}

function multiply(x, y) {
    if (x < y) return mult(y, x)
    else return mult(x, y)
}

module.exports = multiply
