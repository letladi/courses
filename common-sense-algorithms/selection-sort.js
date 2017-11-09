const sort = (list) => {
  let minIndex = 0

  for (let i = 0; i < list.length; i++) {
    for (let j = i + 1; j < list.length; j++) {
      minIndex = (list[j] < list[i]) ? j : i
    }
    [ list[i], list[minIndex] ] = [ list[minIndex], list[i] ]
  }

  return list 
}


module.exports = sort