const swap = (list, i, j) => {
    const temp = list[i]
    list[i] = list[j]
    list[j] = temp
}

const minIndex = (list, lo = 0, hi = list.length - 1) => {
    let min = lo;
    for (let i = min + 1; i <= hi; i++) {
        min = (list[min] < list[i]) ? min : i
    }
    return min
}

const sort = (list) => {
    for (let i = 0, lastIndex = list.length - 1; i < lastIndex; i++) {
        const minI = minIndex(list, i, lastIndex)
        swap(list, i, minI)
    }
}

module.exports = sort
