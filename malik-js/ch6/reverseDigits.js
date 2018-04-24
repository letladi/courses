const reverse = require('./reverseString')

function reverseDigits(n) {
    str = `${n}`
    return +reverse(str)
}

module.exports = reverseDigits
