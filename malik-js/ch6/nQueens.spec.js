const Puzzle = require('./nQueens')

describe('n-queens', () => {
    describe('4-queens', () => {
        test('solution is [1, 3, 0, 2]', () => {
            const puzzle = new Puzzle(4)
            expect(puzzle.solve()).toEqual([1, 3, 0, 2])
        })

        describe('#canPlaceQueen', () => {
            describe('the first row queen can be placed on any column', () => {
                const array = [ , , , , ]
                test('canPlaceQueen([ , , , ,], 0, 0) = true', () => {
                    const puzzle = new Puzzle(4)
                    expect(puzzle.canPlaceQueen(array, 0, 0)).toEqual(true)
                })
                test('canPlaceQueen([ , , , , ], 0, 1) = true', () => {
                    const puzzle = new Puzzle(4)
                    expect(puzzle.canPlaceQueen(array, 0, 1)).toEqual(true)
                })
                test('canPlaceQueen([ , , , , ], 0, 2) = true', () => {
                    const puzzle = new Puzzle(4)
                    expect(puzzle.canPlaceQueen(array, 0, 2)).toEqual(true)
                })
                test('canPlaceQueen([ , , , , ], 0, 3) = true', () => {
                    const puzzle = new Puzzle(4)
                    expect(puzzle.canPlaceQueen(array, 0, 3)).toEqual(true)
                })
                test('canPlaceQueen([ , , , , ], 0, 4) = true; this value is out of range', () => {
                    const puzzle = new Puzzle(4)
                    expect(puzzle.canPlaceQueen(array, 0, 4)).toEqual(true)
                })
            })

            describe('queens cannot be on the same column', () => {
                test('canPlaceQueen([0, , , , ], 1, 0) = false', () => {
                    const puzzle = new Puzzle(4)
                    const array = [0, , , , ]
                    expect(puzzle.canPlaceQueen(array, 1, 0)).toEqual(false)
                })
                test('canPlaceQueen([0, , , , ], 2, 0) = false', () => {
                    const puzzle = new Puzzle(4)
                    const array = [0, , , , ]
                    expect(puzzle.canPlaceQueen(array,2, 0)).toEqual(false)
                })
                test('canPlaceQueen([0, , , , ], 2, 0) = false', () => {
                    const puzzle = new Puzzle(4)
                    const array = [0, , , , ]
                    expect(puzzle.canPlaceQueen(array, 2, 0)).toEqual(false)
                })
                test('canPlaceQueen([0, , , , ], 3, 0) = false', () => {
                    const puzzle = new Puzzle(4)
                    const array = [0, , , , ]
                    expect(puzzle.canPlaceQueen(array, 3, 0)).toEqual(false)
                })
            })

            describe('queens cannot be on the same diagonal', () => {
                test('canPlaceQueen([0, , , , ], 1, 1) = false', () => {
                    const puzzle = new Puzzle(4)
                    const array = [0, , , , ]
                    expect(puzzle.canPlaceQueen(array, 1, 1)).toEqual(false)
                })
                test('canPlaceQueen([0, 2, , , ], 2, 1) = false', () => {
                    const puzzle = new Puzzle(4)
                    const array = [0, 2, , , ]
                    expect(puzzle.canPlaceQueen(array, 2, 1)).toEqual(false)
                })
                test('canPlaceQueen([0, , , , ], 2, 2) = false', () => {
                    const puzzle = new Puzzle(4)
                    const array = [0, , , , ]
                    expect(puzzle.canPlaceQueen(array, 2, 2)).toEqual(false)
                })
                test('canPlaceQueen([0, , , , ], 3, 3) = false', () => {
                    const puzzle = new Puzzle(4)
                    const array = [0, , , , ]
                    expect(puzzle.canPlaceQueen(array, 3, 3)).toEqual(false)
                })
                test('canPlaceQueen([0, 2, , , ], 2, 3) = false', () => {
                    const puzzle = new Puzzle(4)
                    const array = [0, 2, , , ]
                    expect(puzzle.canPlaceQueen(array, 2, 3)).toEqual(false)
                })
            })
        })
    })


})
