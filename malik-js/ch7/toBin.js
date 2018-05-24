const Stack = require('./stack')

const toBin = (decimal) => {
    const stack = []

    while (decimal > 0) {
        stack.push(decimal % 2)
        decimal = Math.floor(decimal / 2)
    }

    let ret = ''
    while (stack.length) ret += stack.pop()
    return ret
}

module.exports = toBin
