class Tour {
    constructor(n = 5) {
        this.n = n
        this.grid = new Array(n)
        this.grid.fill(new Array(n))
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

    findValidMoves(row, col) {
        const min = 0
        const max = this.n

        const allPotentialMoves = this._getAllPotentialMoves(row, col)

        return allPotentialMoves.filter(([moveRow, moveCol]) => {
            return (min <= moveRow && moveRow < max) && (min <= moveCol && moveCol < max)
        })
    }

    findMovesThatHaveNotBeenMade(row, col) {
        const movesFromGivenLocation = this.findValidMoves(row, col)
        return movesFromGivenLocation.filter(([x, y]) => this.grid[x][y] === void(0))
    }

    solve(row = 0, col = 0, move = 1) {
        const grid = this.grid
        console.log('the grid', grid)
        if (this.allSlotsAreFilled()) return grid
        if (grid[row][col]) return false

        grid[row][col] = move

        const movesFromHere = this.findMovesThatHaveNotBeenMade(row, col)

        console.log('movesFromHere', movesFromHere)

        for (let i = 0; i < movesFromHere.length; i++) {
            const [r, c] = movesFromHere[i]

            if (this.solve(r, c, move + 1)) return grid
            grid[r][c] = void(0)
        }

        grid[row][col] = void(0)
        return void(0)
    }
}

module.exports = Tour
