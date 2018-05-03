const sqrt = require('./sqrt')

describe('sqrt', () => {
    test('sqrt(4) = 2', () => {
        expect(sqrt(4)).toEqual(2)
    })
    test('sqrt(1000000) = 1000', () => {
        expect(sqrt(1000000)).toEqual(1000)
    })
    test('sqrt(2) approximately equals 1.4142135623730951', () => {
        expect(sqrt(2)).toBeCloseTo(1.4142135623730951, 5)
    })
})
