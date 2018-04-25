const reverse = require('./reverseArray')

describe('reverse an array recursively', () => {
    test('reverse([1,2,3,4,5]) = [5,4,3,2,1]', () => {
        expect(reverse([1,2,3,4,5])).toEqual([5,4,3,2,1])
    })
    test('reverse([-10, 5, 0, 2]) = [2, 0, -5, -10]', () => {
        expect(reverse([-10, -5, 0, 2])).toEqual([2, 0, -5, -10])
    })
    test('reverse([1,2,3,4, 5,6,7,8,9,10, 11,12], 4, 9) = [1, 2, 3, 4, 10, 9, 8, 7, 6, 5, 11, 12]', () => {
        expect(reverse([1,2,3,4, 5,6,7,8,9,10, 11,12], 4, 9)).toEqual([1, 2, 3, 4, 10, 9, 8, 7, 6, 5, 11, 12])
    })
    test('reverse([1]) = [1]', () => {
        expect(reverse([1])).toEqual([1])
    })
    test('reverse([]) = []', () => {
        expect(reverse([])).toEqual([])
    })
})
