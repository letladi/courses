const insertionSort = (list) => {
    for (let i = 1, iBefore = i - 1, lastIndex = list.length - 1; i <= lastIndex; i++, iBefore++) {
        if (list[i] < list[iBefore]) {
            let j = i
              , jBefore = iBefore
              , temp = list[i]
            do {
                list[j] = list[jBefore]
                j = jBefore--
            } while (j > 0 && list[jBefore] > temp)
            list[j] = temp
        }
    }
}

module.exports = insertionSort
