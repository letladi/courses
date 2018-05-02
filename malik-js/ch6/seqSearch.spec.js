const search = require('./seqSearch')

describe('recursive sequential search', () => {
    test('search([], 22) = -1', () => {
        expect(search([], 22)).toEqual(-1)
    })
    test('search([10, 20, 80, 30, 60, 50, 110, 100, 130, 170], 110) = 6', () => {
        expect(search([10, 20, 80, 30, 60, 50, 110, 100, 130, 170], 110)).toEqual(6)
    })
    test('search([10, 20, 80, 30, 60, 50, 110, 100, 130, 170], 175) = -1', () => {
        expect(search([10, 20, 80, 30, 60, 50, 110, 100, 130, 170], 175)).toEqual(-1)
    })
})
