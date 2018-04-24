const sum = require('./listSum')

describe('recursively sum elements of array', () => {
    test('sum([]) = 0', () => {
        expect(sum([])).toEqual(0)
    })
    test('sum([1,2,3,4,5]) = 15', () => {
        expect(sum([1,2,3,4,5])).toEqual(15)
    })
    test('sum([-2,2,4]) = 4', () => {
        expect(sum([-2,2,4])).toEqual(4)
    })
})
