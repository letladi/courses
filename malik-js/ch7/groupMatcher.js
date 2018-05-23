const Stack = require('./stack')

const openingParens = new Set(['(', '{', '['])
const closingParens = new Set(['}', ')', ']'])
const removeIrelevantCharacters = (str = '') => str.replace(/[^({\[\]})]/g, '')
const isClosingParens = (c) => closingParens.has(c)
const isOpeningParens = (c) => openingParens.has(c)
const matchingParens = {
    ']': '[',
    ')': '(',
    '}': '{',
}
const isMatchingClosingParens = (opener, closer) => matchingParens[closer] === opener

const isBalanced = (str) => {
    const stack = new Stack()

    str = removeIrelevantCharacters(str)

    for (let i = 0; i < str.length; i++) {
        const c = str[i]
        if (isOpeningParens(c)) stack.push(c)
        else if (isClosingParens(c)) {
            const opener = stack.pop()

            if (isOpeningParens(opener) === false) return false
            if (isMatchingClosingParens(opener, c) === false) return false
        }
    }

    while (stack.isEmpty() == false) {
        const c = stack.pop()

        if (c == void(0) || isOpeningParens(c)) return false
        else if (isClosingParens(c)) {
            const opener = stack.pop()
            if (opener == void(0) || isMatchingClosingParens(opener, c) === false) return false
        }
    }
    return true
}

module.exports = isBalanced
