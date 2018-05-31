const deepEqual = require('deep-equal')
const Tour = require('./knight-tour')

describe("Knight's Tour Problem", () => {
    describe('#findValidMoves: find valid moves the given position', () => {
        test('5x5 board: edge point', () => {
            const tour = new Tour(5)
            expect(tour.findValidMoves(0, 0)).toEqual([ [1, 2], [2, 1] ])
        })
        test('5x5 board: middle point', () => {
            const tour = new Tour(5)
            const moves = tour.findValidMoves(2, 2)
            const expectedMoves = [ [1, 0], [3, 0], [1, 4], [3, 4], [0, 1], [0, 3], [4, 1], [4, 3] ]

            expect(deepEqual(moves, expectedMoves)).toEqual(true)
        })

    })

    describe('#findMovesThatHaveNotBeenMade', () => {
        test('should not return any points if they are all filled in', () => {
            const grid = [
                [1, 6, 15, 10, 11],
                [14, 9, 20, 5, 16],
                [19, 2, 7, 22, 11],
                [8, 13, 24, 17, 4],
                [25, 18, 3, 12, 23],
            ]
            const tour = new Tour(5)
            expect(tour.findMovesThatHaveNotBeenMade(0,0, grid)).toEqual([])
        })
        test('should only return points that are not filled in', () => {
            const grid = [
                [1, 6, 15, 10, 11],
                [14, 9, 20, 5, 16],
                [19, void(0), 7, 22, 11],
                [8, 13, 24, 17, 4],
                [25, 18, 3, 12, 23],
            ]
            const tour = new Tour(5)
            expect(tour.findMovesThatHaveNotBeenMade(0, 0, grid)).toEqual([ [2, 1] ])
        })
    })
    describe('#solve', () => {
        test('should return a grid containing all the moves sequences', () => {
            const tour = new Tour(5)
            const expectedGrid = [
                [1, 6, 15, 10, 11],
                [14, 9, 20, 5, 16],
                [19, 2, 7, 22, 11],
                [8, 13, 24, 17, 4],
                [25, 18, 3, 12, 23],
            ]
            expect(tour.solve(0, 0)).toEqual(expectedGrid)
        })
        test('should return a grid containing all the moves sequences - 6x6 grid', () => {
            const tour = new Tour(6)
            const expectedGrid = [
                [1, 16, 7, 26, 11, 14],
                [34, 25, 12, 15, 6, 27],
                [17, 2, 33, 8, 13, 10],
                [32, 35, 24, 21, 8, 5],
                [23, 18, 3, 30, 9, 20],
                [36, 31, 22, 19, 4, 29],
            ]
            expect(tour.solve(0, 0)).toEqual(expectedGrid)
        })
    })
})
