const vowelCount = require('./vowelCount')

describe('recursive vowel count function', () => {
    test('vowelCount("sebesho") = 3', () => {
        expect(vowelCount('sebesho')).toEqual(3)
    })
    test('vowelCount("letladi") = 3', () => {
        expect(vowelCount('letladi')).toEqual(3)
    })
    test('vowelCount("sometimes") = 4', () => {
        expect(vowelCount('sometimes')).toEqual(4)
    })
})
