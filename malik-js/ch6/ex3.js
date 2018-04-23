const pad = (x, n) => {
    const spacesOnEachSide = n - x
    return ' '.repeat(spacesOnEachSide) + '* '.repeat(x) + ' '.repeat(spacesOnEachSide)
}

function stars(n) {
    downStars(n, n)
    upStars(n - 1, n)
}

function downStars(n, max) {
    if (n === 0) return

    downStars(n - 1, max)
    console.log(pad(n, max))
}

function upStars(n, max) {
    if (n === 0) return
    console.log(pad(n, max))
    upStars(n - 1, max)
}

module.exports = stars
