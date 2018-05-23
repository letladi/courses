const primeFactors = require('./primeFactors')

describe('primeFactors', () => {
    test('primeFactors(6) = [3, 2, 1]', () => {
        expect(primeFactors(6)).toEqual([3, 2])
    })
    test('primeFactors(12) = [3, 2, 2, 1]', () => {
        expect(primeFactors(12)).toEqual([3, 2, 2])
    })
    test('primeFactors(48) = [3, 2, 2, 2, 2]', () => {
        expect(primeFactors(48)).toEqual([3, 2, 2, 2, 2])
    })
})
