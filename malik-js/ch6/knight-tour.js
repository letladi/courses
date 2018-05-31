let count = 0

class Tour {
    constructor(n = 5) {
        this.n = n
        this.grid = []
        for (let i = 0; i < n; i++) {
            this.grid[i] = []
            for (let j = 0; j < n; j++) {
                this.grid[i][j] = void(0)
            }
        }
        this.move = 1
    }

    allSlotsAreFilled() {
        const n = this.n
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                if (this.grid[i][j] === void(0)) return false
            }
        }
        return true
    }

    _getAllPotentialMoves(row, col) {
        const moves = []
        // get all horizontal moves
        moves.push([row - 1, col - 2], [row + 1, col - 2], [row - 1, col + 2], [row + 1, col + 2])
        // get all vertical moves
        moves.push([row - 2, col - 1], [row - 2, col + 1], [row + 2, col - 1], [row + 2, col + 1])
        return moves
    }

    findValidMoves(row, col, grid = this.grid) {
        const min = 0
        const max = this.n

        const allPotentialMoves = this._getAllPotentialMoves(row, col)

        return allPotentialMoves.filter(([moveRow, moveCol]) => {
            return (min <= moveRow && moveRow < max)
                && (min <= moveCol && moveCol < max)
        })
    }

    findMovesThatHaveNotBeenMade(row, col, grid = this.grid) {
        const movesFromGivenLocation = this.findValidMoves(row, col)
        return movesFromGivenLocation.filter(([x, y]) => grid[x][y] === void(0))
    }

    solve(row = 0, col = 0) {
        if (this.allSlotsAreFilled()) return this.grid
        else if (this.grid[row][col] == void(0)) {
            this.grid[row][col] = this.move++
        }

        const movesFromHere = this.findMovesThatHaveNotBeenMade(row, col)

        for (let i = 0; i < movesFromHere.length; i++) {
            const [r, c] = movesFromHere[i]

            if (this.solve(r, c))
                return this.grid
            else {
                this.grid[r][c] = void(0)
                this.move = 0
            }
        }

        if (this.allSlotsAreFilled()) return this.grid
        else {
            this.grid[row][col] = void(0)
            this.move--
            return false
        }
    }
}

module.exports = Tour
