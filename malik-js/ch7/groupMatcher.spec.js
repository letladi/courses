const isBalanced = require('./groupMatcher')

describe('group-matcher', () => {
    test('isBalanced("{25+(3-6) * 8}") = true', () => {
        expect(isBalanced("{25+(3-6) * 8}")).toEqual(true)
    })
    test('isBalanced("5+{(13+7)/8-2*9") = false', () => {
        expect(isBalanced("5+{(13+7)/8-2*9")).toEqual(false)
    })
    test('isBalanced("7+8*2") = true', () => {
        expect(isBalanced("7+8*2")).toEqual(true)
    })
})
