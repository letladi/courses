const isPalindrome = require('./palindromeCheck')

describe('isPalindrome', () => {
    test('isPalindrome("Anna") = true', () => {
        expect(isPalindrome('Anna')).toEqual(true)
    })
    test('isPalindrome("Robert") = false', () => {
        expect(isPalindrome('Robert')).toEqual(false)
    })
    test('isPalindrome("A but tuba") = true', () => {
        expect(isPalindrome('A but tuba')).toEqual(true)
    })
    test('isPalindrome("Acrobats stab orca") = true', () => {
        expect(isPalindrome('Acrobats stab orca')).toEqual(true)
    })
})
