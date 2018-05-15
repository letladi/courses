class Puzzle {
    constructor(n) {
        this.queens = n
        this.queensInRow = []
    }

    solve(solution = [], currentRow = 0, reverseMove = false) {
        if (this._lastSlotIsFilled(solution)) return this.solution = this.solution || solution

        let col = 0
        const n = this.queens
        const lastIdx = n - 1
        if (reverseMove) {
            currentRow--
            col = solution[currentRow]
            solution[currentRow] = void(0)
            if (col === lastIdx) return this.solve(solution, currentRow, reverseMove)
            col++
        }

        while (this.canPlaceQueen(solution, currentRow, col) === false && col < n)
            col++

        if (col === n)
            return this.solve(solution, currentRow, true)
        else {
            solution[currentRow] = col
            currentRow++
            return this.solve(solution, currentRow)
        }
    }

    _lastSlotIsFilled(array) {
        const n = this.queens
        return array[n - 1] !== void(0)
    }

    _isOnSameDiagonal(row1, col1, row2, col2) {
        return Math.abs(row1 - row2) === Math.abs(col1 - col2)
    }

    canPlaceQueen(array, row, col) {
        for (let i = 0; i < row; i++) {
            if (array[i] === col || this._isOnSameDiagonal(i, array[i], row, col))
                return false
        }
        return true
    }
}

module.exports = Puzzle
