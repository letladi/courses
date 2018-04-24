function sum(array, i = 0, total = 0) {
    if (i === array.length) return total
    return sum(array, i + 1, total + array[i])
}

module.exports = sum
