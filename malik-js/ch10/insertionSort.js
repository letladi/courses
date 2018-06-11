const insertionSort = (list, from = 0, to) => {
    if (from > to) throw new Error("An interval's opening value cannot be greater than its closing value")

    from = (from < 0) ? 0 : from
    const len = list.length
    to = ((to > len - 1) || (to === void(0))) ? (len - 1) : to

    for (let i = from + 1, iBefore = from; i <= to; i++, iBefore++) {
        if (list[i] < list[iBefore]) {
            let j = i
              , jBefore = iBefore
              , temp = list[i]
            do {
                list[j] = list[jBefore]
                j = jBefore--
            } while (j > from && list[jBefore] > temp)
            list[j] = temp
        }
    }
}

module.exports = insertionSort
