const minIndex = (list, startIndex = 0) => {
  let minIndex = startIndex
  for ( ; startIndex < list.length; startIndex++) {
    minIndex = (list[startIndex] < list[minIndex]) ? startIndex : minIndex
  }
  return minIndex
}

const sort = (list) => {

  for (let i = 0; i < list.length; i++) {
    let min_i = minIndex(list, i + 1)

    if (list[min_i] < list[i]) {
      let temp = list[i]
      list[i] = list[min_i]
      list[min_i] = temp
    }
  }
  return list 
}


module.exports = sort