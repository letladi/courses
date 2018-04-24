const isPalindrome = require('./palindrome')

describe('recursive palindrome-checking function', () => {
    test('isPalindrome("letladi") = false', () => {
        expect(isPalindrome('letladi')).toEqual(false)
    })
    test('isPalindrome("madam") = true', () => {
        expect(isPalindrome('madam')).toEqual(true)
    })
    test('isPalindrome("anna") = true', () => {
        expect(isPalindrome('anna')).toEqual(true)
    })
    test('isPalindrome("Avid diva") = true', () => {
        expect(isPalindrome('avid diva')).toEqual(true)
    })
    test('isPalindrome("") = false', () => {
        expect(isPalindrome('')).toEqual(false)
    })
})
