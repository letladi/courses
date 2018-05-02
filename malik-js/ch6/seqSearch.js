function search(list = [], key, lo = 0, hi = list.length - 1) {
    if (lo > hi) return -1
    if (list[lo] === key) return lo
    if (list[hi] === key) return hi
    return search(list, key, lo + 1, hi - 1)
}

module.exports = search
