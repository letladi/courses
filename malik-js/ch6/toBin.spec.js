const toBin = require('./toBin')

describe('toBinary function', () => {
    test('toBin(13) = 1101', () => {
        expect(toBin(13)).toEqual('1101')
    })
    test('toBin(294) = 100100110', () => {
        expect(toBin(294)).toEqual('100100110')
    })
})
