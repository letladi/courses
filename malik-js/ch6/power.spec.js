const power = require('./power')

describe('recursive function to perform powers', () => {
    test('power(2, 4) = 16', () => {
        expect(power(2, 4)).toEqual(16)
    })
    test('power(2, 10) = 1048576', () => {
        expect(power(2, 20)).toEqual(1048576)
    })
    test('power(100000, 0) = 1', () => {
        expect(power(100000, 0)).toEqual(1)
    })
    test('power(100000, 1) = 100000', () => {
        expect(power(100000, 1)).toEqual(100000)
    })
})
