const mult = require('./mult')

describe('recursive multiplication function', () => {
    test('mult(2, 2) = 4', () => {
        expect(mult(2,2)).toEqual(4)
    })
    test('mult(10, 10) = 100', () => {
        expect(mult(10, 10)).toEqual(100)
    })
    test('mult(66, 81) = 5346', () => {
        expect(mult(66, 81)).toEqual(5346)
    })
})
