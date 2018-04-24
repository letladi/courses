function reverse(str = '', i = 0, result = '') {
    if (i === str.length) return result
    return reverse(str, i + 1, str[i] + result)
}

module.exports = reverse
