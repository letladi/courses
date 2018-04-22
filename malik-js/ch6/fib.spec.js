const nthFib = require('./fib')

describe('nthFib', () => {
    test('nthFib(6) = 8', () => {
        expect(nthFib(6)).toEqual(8)
    })
    test('nthFib(8) = 21', () => {
        expect(nthFib(8)).toEqual(21)
    })
})
