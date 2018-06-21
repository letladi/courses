const { quickSortHelper, partition } = require('./util')

const kThSmallestItem = (list, k) => {
    const lo = 0
    const hi = list.length - 1
    const pivotIdx = partition(list, lo, hi)

    if (pivotIdx === k) return list[pivotIdx]
    else if (k < pivotIdx) quickSortHelper(list, lo, pivotIdx - 1)
    else quickSortHelper(list, pivotIdx + 1, hi)

    return list[k]
}

module.exports = kThSmallestItem
