const toDec = require('./toDec')

describe('toDec', () => {
    const testData = new Map([
        ['11000101', 197],
        ['10101010', 170],
        ['11111111', 255],
        ['10000000', 128],
        ['1111100000', 992],
    ])
    for (const [binary, decimal] of testData) {
        test(`toDec(${binary}) = ${decimal}`, () => {
            expect(toDec(binary)).toEqual(decimal)
        })
    }
})
