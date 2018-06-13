const intervalInsertionSort = require('./insertionSort')

const sort = (list) => {
  let inc = null

  for (inc = 1, lastIndex = list.length - 1; inc < Math.floor(lastIndex / 9); inc = (3 * inc) + 1) {
    // empty loop
    console.log('increment inside empty loop', inc)
  }

  do {
    console.log('list length = ', list.length, '\ninc = ', inc)
    for (let begin = 0; begin < inc; begin++) {
      intervalInsertionSort(list, begin, begin + inc)
    }
    inc = Math.floor(inc / 3)
    console.log('increment inside the loop', inc)
  } while (inc > 0)
  console.log('the sorted list?', list)
}

module.exports = sort
