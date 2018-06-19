const insertionSort = require('../insertionSort')
const swap = (list, i, j) => {
  const temp = list[i]
  list[i] = list[j]
  list[j] = temp
}

const partition = (list, lo = 0, hi = list.length - 1) => {
  const pivotIdx = Math.floor((lo + hi) / 2)
  const pivot = list[pivotIdx]
  swap(list, pivotIdx, lo)
  let smallIndex = lo

  for (let i = smallIndex + 1; i <= hi; i++) {
    if (list[i] < pivot) {
      smallIndex++
      swap(list, i, smallIndex)
    }
  }
  swap(list, lo, smallIndex)
  return smallIndex
}

const quickSort = (list, lo = 0, hi = list.length - 1) => {
  if (lo < hi) {
    const index = partition(list, lo, hi)
    quickSort(list, lo, index - 1)
    quickSort(list, index + 1, hi)
  }
}

module.exports = quickSort
