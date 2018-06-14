const intervalInsertionSort = require('./intervalInsertionSort')

const sort = (list) => {
  let inc = 1
  const len = list.length
  const incLimit = Math.floor(len / 2)
  while (inc < incLimit) inc = inc * 2 + 1
  do {
    intervalInsertionSort(list, inc)
    inc = (inc - 1) / 2
  } while (inc > 0)
}

module.exports = sort
