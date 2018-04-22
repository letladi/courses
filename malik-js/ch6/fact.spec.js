const fact = require('./fact')

describe('factorial function', () => {
    test('fact(3) = 6', () => {
        expect(fact(3)).toEqual(6)
    })
    test('fact(6) = 720', () => {
        expect(fact(6)).toEqual(720)
    })
    test('fact(10) = 3628800', () => {
        expect(fact(10)).toEqual(3628800)
    })
})
