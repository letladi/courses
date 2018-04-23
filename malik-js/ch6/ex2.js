function stars(n) {
    downStars(n)
    upStars(n)
}

function downStars(n) {
    if (n === 0) return
    downStars(n - 1)
    console.log('*'.repeat(n))
}

function upStars(n) {
    if (n === 0) return
    console.log('*'.repeat(n))
    upStars(n - 1)
}



module.exports = stars
