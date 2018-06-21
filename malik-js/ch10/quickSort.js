const { quickSortHelper } = require('./util')

function quickSort(list, compare) {
  quickSortHelper(list, 0, list.length - 1, compare)
}

module.exports = quickSort
