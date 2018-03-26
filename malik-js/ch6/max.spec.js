const max = require('./max')

describe('max function', () => {
    test('test #1', () => {
        const nums = [-100, -5, 0, -200, -2, -.3, -5]
        expect(max(nums)).toEqual(0)
    })
    test('test #2', () => {
        const nums = [1, 2, 3, 4, 5, 6]
        expect(max(nums)).toEqual(6)
    })
    test('test #2', () => {
        const nums = [Number.MIN_VALUE, Number.MAX_VALUE, 0, 2 ** 10]
        expect(max(nums)).toEqual(Number.MAX_VALUE)
    })
})
