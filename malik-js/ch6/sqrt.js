function sqrt(n, a = n, epsilon = 0.00000000000000000995) {
    const a2 = a**2
    if (Math.abs(a2 - n) <= epsilon) return a
    const prevA = a
    const newA = (a2 + n) / (2 * a)
    if (newA === prevA) return prevA
    return sqrt(n,  newA, epsilon)
}

module.exports = sqrt
