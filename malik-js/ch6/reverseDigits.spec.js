const reverseDigits = require('./reverseDigits')

describe('recursive function to return a number with the digits reversed', () => {
    test('reverseDigits(1988) = 8891', () => {
        expect(reverseDigits(1988)).toEqual(8891)
    })
    test('reverseDigits(28) = 82', () => {
        expect(reverseDigits(28)).toEqual(82)
    })
    test('reverseDigits(2018) = 8102', () => {
        expect(reverseDigits(2018)).toEqual(8102)
    })
})
