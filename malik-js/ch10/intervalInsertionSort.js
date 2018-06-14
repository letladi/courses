const sort = (list, h) => {
  let passes = 0
  let index = 0
  while (passes < h) {
    for (let iBefore = index, i = index + h, lastIndex = list.length - 1; list[i]; iBefore = i, i += h) {
      if (list[i] < list[iBefore]) {
        const temp = list[i]
        let j = i,
            jBefore = iBefore

        do {
          list[j] = list[jBefore]
          j = jBefore
          jBefore -= h
        } while (j > index && list[jBefore] > temp)
        list[j] = temp
      }
    }
    index++
    passes++
  }
}

module.exports = sort
