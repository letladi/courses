const swap = (list, i, j) => {
  const temp = list[i]
  list[i] = list[j]
  list[j] = temp
}

const partition = (list, first, last) => {
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

function quickSort(list, lo = 0, hi = list.length - 1) {
  if (lo < hi) {
    const pivotIdx = partition(list, lo, hi)
    quickSort(list, lo, pivotIdx - 1)
    quickSort(list, pivotIdx + 1, hi)
  }

}

module.exports = quickSort
