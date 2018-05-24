const toBin = require('./toBin')

describe('stack-toBin', () => {
    const testData = new Map([
        [197, '11000101'],
        [170, '10101010'],
        [255, '11111111'],
        [128, '10000000'],
        [992, '1111100000'],
    ])

    testData.forEach(function(binary, decimal) {
        test(`toBin(${decimal}) = ${binary}`, () => {
            expect(toBin(decimal)).toEqual(binary)
        })
    })
})
