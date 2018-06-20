const heapify = (list, lo = 0, hi = list.length - 1) => {
  let largeIndex = (2 * lo) + 1
  let temp = list[lo]
  while (largeIndex <= hi) {
    if (largeIndex < hi)
      if (list[largeIndex] < list[largeIndex + 1]) largeIndex = largeIndex + 1

      if (temp > list[largeIndex]) break // subtree is already in a heap
      else {
        list[lo] = list[largeIndex]
        lo = largeIndex
        largeIndex = (2 * lo) + 1
      }
  }
  list[lo] = temp
}

const buildHeap = (array) => {
  for (let len = array.length, i = Math.floor(len / 2) - 1; i >= 0; i--) {
    heapify(array, i, len - 1)
  }
}

const swap = (list, i, j) => {
  const temp = list[i]
  list[i] = list[j]
  list[j] = temp
}

const heapSort = (list) => {
  buildHeap(list)
  const firstIndex = 0
  for (let lastOufOfOrder = list.length - 1; lastOufOfOrder >= 0; lastOufOfOrder--) {
    swap(list, lastOufOfOrder, firstIndex)
    heapify(list, firstIndex, lastOufOfOrder - 1)
  }
}

module.exports = heapSort
