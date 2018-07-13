const reverse = (chList, lo = 0, hi = chList.length - 1) => {
  while (lo < hi) {
    const temp = chList[hi]
    chList[hi] = chList[lo]
    chList[lo] = temp
    lo++
    hi--
  }
}

module.exports = reverse
