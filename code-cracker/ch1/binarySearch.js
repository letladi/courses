function search(list, val) {
  let lo = 0, hi = list.length - 1

  while (hi >= lo) {
    const mid = lo + Math.floor((hi - lo) / 2)
    if (list[mid] === val) return mid
    else if (val < list[mid]) hi = mid - 1
    else lo = mid + 1
  }
  return -1
}

module.exports = search
