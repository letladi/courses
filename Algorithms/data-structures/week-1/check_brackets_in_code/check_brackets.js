const readline = require('readline')

process.stdin.setEncoding('utf8')
var rl = readline.createInterface({
  input: process.stdin,
  terminal: false
})

rl.on('line', readLine)

function readLine (line = '') {
  if (line.trim() !== "\n") {
    const matchingResult = bracketsMatch(line)
    console.log(matchingResult === true ? 'Success' : matchingResult)
    process.exit()
  }
}

const isOpeningBracket = (char) => /[({\[]/.test(char)
const isClosingBracket = (char) => /[)\]}]/.test(char)
const matchingBracket = (char) => ({
	'[': ']',
	'(': ')',
	'{': '}',
	']': '[',
	'}': '{',
	')': '('
}[char])

const bracketsMatch = (brackets) => {
	const stack = []
	for (let i = 0; i < brackets.length; i++) {
		let char = brackets[i]
		if (isOpeningBracket(char)) {
			stack.push({ bracket: char, index: i + 1 })
		} else if (isClosingBracket(char)) {
			if (stack.length == 0) return i + 1

			let { bracket } = stack.pop()

			if (char != matchingBracket(bracket)) {
				return i + 1
			}
		}
	}

	if (stack.length) {
		let { bracket, index } = stack.pop()
		return index
	} 

	return true
}

module.exports = {
	bracketsMatch
}