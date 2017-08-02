function isPalindrome(phrase) {	
	if (phrase == void(0)) {
		throw new Error('Invalid argument')
	}

	return phrase.trim().length > 0 && phrase.split('').reverse().join('') === phrase
}

module.exports = isPalindrome