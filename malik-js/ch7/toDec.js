const Stack = require('./stack')

const toDec = (binary) => {
    const stack = new Stack()
    const len = binary.length
    let index = len - 1
    for (let i = 0; i < len; i++) stack.push(binary[i] * Math.pow(2, index--))

    let ret = 0
    let count = 0
    while (stack.isEmpty() === false)
        ret += stack.pop()
    return ret
}

module.exports = toDec
