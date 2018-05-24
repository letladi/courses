const Stack = require('./stack')

const toDec = (binary) => {
    const stack = new Stack()
    for (let i = 0, len = binary.length; i < len; i++) stack.push(binary[i])

    let ret = 0
    let count = 0
    while (stack.isEmpty() === false)
        ret += stack.pop() * Math.pow(2, count++)
    return ret
}

module.exports = toDec
