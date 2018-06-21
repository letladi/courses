const swap = (list, i, j) => {
  const temp = list[i]
  list[i] = list[j]
  list[j] = temp
}

const defaultCompare = (a, b) => (a < b) ? -1 : 1
const partition = (list, first, last, compare = defaultCompare) => {
  const pivotIdx = Math.floor((first + last) / 2)
  const pivot = list[pivotIdx]
  swap(list, first, pivotIdx)

  let smallIndex = first

  for (let i = first + 1; i  <= last; i++) {
    if (compare(list[i], pivot) === -1) {
      smallIndex++
      swap(list, smallIndex, i)
    }
  }

  swap(list, first, smallIndex)
  return smallIndex
}

function quickSortHelper(list, lo, hi, compare) {
  if (lo < hi) {
    const pivotIdx = partition(list, lo, hi, compare)
    quickSortHelper(list, lo, pivotIdx - 1, compare)
    quickSortHelper(list, pivotIdx + 1, hi, compare)
  }
}



module.exports = {
  defaultCompare,
  swap,
  partition,
  quickSortHelper,
}
