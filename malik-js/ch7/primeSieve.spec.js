const primeSieve = require('./primeSieve')

describe('primeSieve', () => {
    test('primeSieve(12) = [2,3,5,7,11]', () => {
        expect(primeSieve(12)).toEqual([2,3,5,7,11])
    })
    test('primeSieve(100) = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]', () => {
        expect(primeSieve(100)).toEqual([2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97])
    })
})
