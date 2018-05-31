const Stack = require('./stack')
const operators = new Set(['-', '+', '*', '/'])
const openingBrackets = new Set(['('])
const closingBrackets = new Set([')'])
const isOpeningBracket = (c) => openingBrackets.has(c)
const isClosingBracket = (c) => closingBrackets.has(c)
const isOperator = (c) => operators.has(c)

const inFixToPostFix = (infx) => {
    const stack = new Stack()
    let postfix = ''

    for (let i = 0, len = infx.length; i < len; i++) {
        const c = infx[i]
        if (isOpeningBracket(c)) stack.push(c)
        else if (isClosingBracket(c)) {
            while (isOpeningBracket(stack.top()) === false) {
                postfix += stack.pop()
            }
            stack.pop()
        } else if (isOperator(c)) {
            
        }
    }

}

module.exports = inFixToPostFix
