const intervalInsertionSort = require('./intervalInsertionSort')

const sort = (list) => {
  let inc = 4
  do {
    intervalInsertionSort(list, inc)
    inc--
  } while (inc > 0)
}

module.exports = sort
