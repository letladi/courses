function stars(n) {
    if (n === 0) return

    console.log(`${'*'.repeat(n)}`)
    stars(n - 1)
    console.log(`${'*'.repeat(n)}`)
}

module.exports = stars
