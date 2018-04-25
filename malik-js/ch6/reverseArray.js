function reverse(list, lo = 0, hi = list.length - 1) {
    if (lo >= hi) return list
    let temp = list[lo]
    list[lo] = list[hi]
    list[hi] = temp
    return reverse(list, lo + 1, hi - 1)
}

module.exports = reverse
