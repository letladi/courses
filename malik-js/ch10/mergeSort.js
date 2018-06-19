const partition = (list, lo = 0, hi = list.length - 1) => {
  const pivotIdx = Math.floor((lo + hi) / 2)
  return pivotIdx
}

const mergeSort = (list, lo = 0, hi = list.length - 1) => {
  if (lo < hi) {
    const index = partition(list, lo, hi)
    const sublist1 = mergeSort(list, lo, index)
    const sublist2 = mergeSort(list, index + 1, hi)

    const ret = []
    let m = 0, n = 0, i = 0
    const sublist1Len = sublist1.length
    const sublist2Len = sublist2.length

    while (m < sublist1Len || n < sublist2Len) {
      if (m === sublist1Len) {
        ret[i] = sublist2[n++]
      } else if (n === sublist2Len) {
        ret[i] = sublist1[m++]
      } else if (sublist1[m] < sublist2[n]) {
        ret[i] = sublist1[m++]
      } else {
        ret[i] = sublist2[n++]
      }
      i++
    }
    return ret
  } else {
    return [list[lo]]
  }
}

module.exports = mergeSort
