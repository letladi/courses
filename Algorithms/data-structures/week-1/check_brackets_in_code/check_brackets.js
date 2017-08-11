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


// const bracketsMatch = (brackets) => {
// 	const openingBrackets = []
// 	const closingBrackets = []
// 	for (let i = 0; i < brackets.length; i++) {
// 		let char = brackets[i]

// 		if (isOpeningBracket(char)) {
// 			openingBrackets.push({ openingBracket: char, openingIndex: i + 1 })
// 		} else if (isClosingBracket(char)) {
// 			closingBrackets.push({ closingBracket: char, closingIndex: i + 1 })
// 		}
// 	}

// 	console.log('OPENING BRACKETS', openingBrackets, 'OPENING BRACKET COUNT', openingBrackets.length)
// 	console.log('CLOSING BRACKETS', closingBrackets, 'CLOSING BRACKET COUNT', closingBrackets.length)

// 	while (closingBrackets.length) {
// 		let { closingBracket, closingIndex } = closingBrackets.pop()
// 		if (openingBrackets.length == 0) {
// 			return closingIndex
// 		} else {
// 			let { openingBracket, openingIndex } = openingBrackets.pop()
// 			console.log(`openingBracket: ${openingBracket}; openingIndex: ${openingIndex}`)
// 			console.log(`closingBracket: ${closingBracket}; closingIndex: ${closingIndex}`)
// 			if (openingBracket != matchingBracket(closingBracket)) {
// 				return closingIndex
// 			}
// 		}
// 	}

// 	if (openingBrackets.length == closingBrackets.length) {
// 		return true
// 	} else {
// 		let { openingBracket, openingIndex } = openingBrackets.pop()
// 		return openingIndex
// 	}
// }

const bracketsMatch = (brackets) => {
	const stack = []
	for (let i = 0; i < brackets.length; i++) {
		let char = brackets[i]
		if (isOpeningBracket(char)) {
			stack.push({ bracket: char, index: i + 1 })
		} else {
			if (stack.length == 0) return i + 1
			let { bracket, index } = stack.pop()
			if (isOpeningBracket(bracket) && char != matchingBracket(bracket)) {
				return i + 1
			}
		}
	}

	if (stack.length) {
		console.log('is at the end', stack)
		let { bracket, index } = stack.pop()
		return index
	} else {
		return true
	}
}

module.exports = {
	bracketsMatch
}