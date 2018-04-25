const gcd = require('./gcd')

describe('greatest common divisor function; recursive version', () => {
    test('gcd(8, 12) = 4', () => {
        expect(gcd(8, 12)).toEqual(4)
    })
    test('gcd(54, 24) = 6', () => {
        expect(gcd(54, 24)).toEqual(6)
    })
})
