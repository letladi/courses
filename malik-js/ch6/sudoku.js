class Sudoku {
    constructor() {
        this.grid = [
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
    }

    initializeGrid(grid) {

    }

    solve(grid = this.grid) {

    }

    slotIsEmpty(row, col) {

    }

    canPlaceNum(row, col, x) {
        return this.numAlreadyInCol(col, x) === false && this.numAlreadyInRow(row, x) === false
            && this.numAlreadyInBox(row, col, x) === false
    }

    numAlreadyInRow(row, x) {
        const rowList = this.grid[row]
        return rowList.includes(x)
    }

    numAlreadyInCol(col, x) {
        const grid = this.grid
        const len = grid.length
        for (let row = 0; row < len; row++) {
            if (grid[row][col] === x) return true
        }
        return false
    }

    _beginningAndEndCoordinates(x) {
        let start = null
        let end = null
        if (0 <= x && x <= 2) {
            start = 0
            end = 2
        } else if (3 <= x && x <= 5) {
            start = 3
            end = 5
        } else if (6 <= x && x <= 8) {
            start = 6
            end = 8
        }
        return { start, end }
    }

    numAlreadyInBox(smallGridRow, smallGridCol, x) {
        let rowCoordinates = this._beginningAndEndCoordinates(smallGridRow)
        let colCoordinates = this._beginningAndEndCoordinates(smallGridCol)

        let rowStart = rowCoordinates.start
        let rowEnd = rowCoordinates.end

        let colStart = rowCoordinates.start
        let colEnd = rowCoordinates.end

        const grid = this.grid

        for (let i = rowStart ; i <= rowEnd; i++) {
            for (let j = colStart; j <= colEnd; j++) {
                if (grid[i][j] === x) return true
            }
        }
        return false
    }

    findEmptySlot() {

    }
}

module.exports = Sudoku
