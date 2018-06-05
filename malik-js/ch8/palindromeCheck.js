const Stack = require('../ch7/stack')
const Queue = require('./queue')

const keepAlphanumericChars = (str) => str.replace(/[^A-Za-z0-9]/g, '')
const toLowerCase = (str) => ''.toLowerCase.call(str)

const isPalindrome = (str = '') => {
    str = toLowerCase(keepAlphanumericChars(str))

    const stack = new Stack()
    const queue = new Queue()
    for (let i = 0, len = str.length; i < len; i++) {
        stack.push(str[i])
        queue.enqueue(str[i])
    }
    while (stack.isEmpty() === false) {
        const a = stack.pop()
        const b = queue.dequeue()
        if (a !== b) return false
    }
    return true
}

module.exports = isPalindrome
