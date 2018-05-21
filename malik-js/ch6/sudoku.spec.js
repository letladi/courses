const Sudoku = require('./sudoku')

describe(`Sudoku for board: \n [
    [6,0,3,0,2,0,0,9,0],
    [0,0,0,0,5,0,0,8,0],
    [0,2,0,4,0,7,0,0,1],
    [0,0,6,0,1,4,3,0,0],
    [0,0,0,0,8,0,0,5,6],
    [0,4,0,6,0,3,2,0,0],
    [8,0,0,2,0,0,0,0,7],
    [0,1,0,0,7,5,8,0,0],
    [0,3,0,0,0,6,1,0,5],
]`, () => {

    describe('#numAlreadyInRow', () => {
        let puzzle = null
        beforeEach(() => puzzle = new Sudoku())
        afterEach(() => puzzle = null)
        test('numAlreadyInRow(0, 5) = false', () => {
            expect(puzzle.numAlreadyInRow(0, 5)).toEqual(false)
        })
        test('numAlreadyInRow(1, 8) = true', () => {
            expect(puzzle.numAlreadyInRow(1, 8)).toEqual(true)
        })
        test('numAlreadyInRow(2, 6) = false', () => {
            expect(puzzle.numAlreadyInRow(2, 6)).toEqual(false)
        })
        test('numAlreadyInRow(3, 9) = false', () => {
            expect(puzzle.numAlreadyInRow(3, 9)).toEqual(false)
        })
        test('numAlreadyInRow(7, 7) = true', () => {
            expect(puzzle.numAlreadyInRow(7, 7)).toEqual(true)
        })
    })

    describe('#numAlreadyInCol', () => {
        let puzzle = null
        beforeEach(() => puzzle = new Sudoku())
        afterEach(() => puzzle = null)
        test('numAlreadyInCol(0, 5) = false', () => {
            expect(puzzle.numAlreadyInCol(0, 5)).toEqual(false)
        })
        test('numAlreadyInCol(1, 1) = true', () => {
            expect(puzzle.numAlreadyInCol(1, 1)).toEqual(true)
        })
        test('numAlreadyInCol(7, 9) = true', () => {
            expect(puzzle.numAlreadyInCol(7, 9)).toEqual(true)
        })
        test('numAlreadyInCol(8, 8) = false', () => {
            expect(puzzle.numAlreadyInCol(8, 8)).toEqual(false)
        })
    })

    describe('#numAlreadyInBox', () => {
        let puzzle = null
        beforeEach(() => puzzle = new Sudoku())
        afterEach(() => puzzle = null)
        test('numAlreadyInBox(2,2, 2) = true', () => {
            expect(puzzle.numAlreadyInBox(2, 2, 2)).toEqual(true)
        })
        test('numAlreadyInBox(1, 5, 6) = false', () => {
            expect(puzzle.numAlreadyInBox(1, 5, 6)).toEqual(false)
        })
        test('numAlreadyInBox(4, 3, 2) = false', () => {
            expect(puzzle.numAlreadyInBox(4, 3, 2)).toEqual(false)
        })
    })

    describe('#solve', () => {
        test(`return the solution;\n [
            [6,5,3,1,2,8,7,9,4],
            [1,7,4,3,5,9,6,8,2],
            [9,2,8,4,6,7,5,3,1],
            [2,8,6,5,1,4,3,7,9],
            [3,9,1,7,8,2,4,5,6],
            [5,4,7,6,9,3,2,1,8],
            [8,6,5,2,3,1,9,4,7],
            [4,1,2,9,7,5,8,6,3],
            [7,3,9,8,4,6,1,2,5],
        ]`, () => {
            const puzzle = new Sudoku()
            expect(puzzle.solve()).toEqual(true)
            expect(puzzle.getGrid()).toEqual([
                [6,5,3,1,2,8,7,9,4],
                [1,7,4,3,5,9,6,8,2],
                [9,2,8,4,6,7,5,3,1],
                [2,8,6,5,1,4,3,7,9],
                [3,9,1,7,8,2,4,5,6],
                [5,4,7,6,9,3,2,1,8],
                [8,6,5,2,3,1,9,4,7],
                [4,1,2,9,7,5,8,6,3],
                [7,3,9,8,4,6,1,2,5],
            ])
        })
    })

    describe('#findEmptySlot', () => {
        test('should return undefined if there are no more slots empty on the board', () => {
            const grid = [
                [6,5,3,1,2,8,7,9,4],
                [1,7,4,3,5,9,6,8,2],
                [9,2,8,4,6,7,5,3,1],
                [2,8,6,5,1,4,3,7,9],
                [3,9,1,7,8,2,4,5,6],
                [5,4,7,6,9,3,2,1,8],
                [8,6,5,2,3,1,9,4,7],
                [4,1,2,9,7,5,8,6,3],
                [7,3,9,8,4,6,1,2,5],
            ]
            const puzzle = new Sudoku()
            expect(puzzle.findEmptySlot(grid)).toEqual(void(0))
        })
        describe('should return the coordinates of first encountered empty slot on the board', () => {
            test('test-1', () => {
                const grid = [
                    [6,0,3,0,2,0,0,9,0],
                    [0,0,0,0,5,0,0,8,0],
                    [0,2,0,4,0,7,0,0,1],
                    [0,0,6,0,1,4,3,0,0],
                    [0,0,0,0,8,0,0,5,6],
                    [0,4,0,6,0,3,2,0,0],
                    [8,0,0,2,0,0,0,0,7],
                    [0,1,0,0,7,5,8,0,0],
                    [0,3,0,0,0,6,1,0,5],
                ]
                const puzzle = new Sudoku()
                expect(puzzle.findEmptySlot(grid)).toEqual({ row: 0, col: 1 })
            })
            test('test-2', () => {
                const grid = [
                    [6,5,3,1,2,8,7,9,4],
                    [1,7,4,3,5,9,6,8,2],
                    [9,2,8,4,6,7,5,3,1],
                    [2,8,6,5,1,4,3,7,9],
                    [3,9,1,7,8,2,4,5,6],
                    [5,4,7,6,9,3,2,1,8],
                    [8,6,5,2,0,1,9,4,7],
                    [4,1,2,9,7,5,8,6,3],
                    [7,3,9,8,4,6,1,2,5],
                ]
                const puzzle = new Sudoku()
                expect(puzzle.findEmptySlot(grid)).toEqual({ row: 6, col: 4 })
            })
        })
    })
})
