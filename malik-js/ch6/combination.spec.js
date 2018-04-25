const combination = require('./combination')

describe('recursive combination method', () => {
    test('combination(52, 5) = 2598960', () => {
        expect(combination(52, 5)).toEqual(2598960)
    })
    test('combination(6, 4) = 15', () => {
        expect(combination(6, 4)).toEqual(15)
    })
})
