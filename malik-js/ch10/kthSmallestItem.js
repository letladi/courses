const sort = require('./quickSort')

const swap = (list, i, j) => {
  const temp = list[i]
  list[i] = list[j]
  list[j] = temp
}

const partition = (list, first = 0, last = list.length - 1) => {
  const pivotIdx = Math.floor((first + last) / 2)
  const pivot = list[pivotIdx]
  swap(list, first, pivotIdx)

  let smallIndex = first

  for (let i = first + 1; i  <= last; i++) {
    if (list[i] < pivot) {
      smallIndex++
      swap(list, smallIndex, i)
    }
  }
  swap(list, first, smallIndex)
  return smallIndex
}

const kThSmallestItem = (list, k) => {
    const pivotIdx = partition(list)
    const lo = 0
    const hi = list.length - 1

    if (pivotIdx === k) return list[pivotIdx]
    else if (k < pivotIdx) sort(list, lo, pivotIdx - 1)
    else sort(list, pivotIdx + 1, hi)

    return list[k]
}

module.exports = kThSmallestItem
