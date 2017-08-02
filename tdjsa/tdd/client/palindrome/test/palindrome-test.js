describe('palindrome-test', () => {

	it('should return true for argument "mom"', () => {
		const word = 'mom'

		const result = isPalindrome(word)

		expect(result).to.be.true
	})

	it('should return true for argument "dad"', () => {
		const phrase = 'dad'

		const result = isPalindrome(phrase)

		expect(result).to.be.true
	})

	it('should return false for argument dude', () => {
		const phrase = 'dude'

		const result = isPalindrome(phrase)

		expect(result).to.be.false
	})

	it('should return true for argument "mom mom"', () => {
		const phrase = 'mom mom'

		const result = isPalindrome(phrase)

		expect(result).to.be.true
	})

	it('should return false for argument mom dad', () => {
		const phrase = 'mom dad'

		const result = isPalindrome(phrase)

		expect(result).to.be.false
	})

	it('should return false when  argument is an empty string', () => {
		const phrase = ''

		const result = isPalindrome(phrase)

		expect(result).to.be.false
	})

	it('should return false for argument with only two spaces', () => {
		const phrase = '  '

		const result = isPalindrome(phrase)

		expect(result).to.be.false
	})

	it('should throw an exception if argument is missing', () => {
		const call = () => isPalindrome()

		expect(call).to.throw(Error, 'Invalid argument')
	})

})