const listIterationComplete = (list, iterationIndex) => list.length === iterationIndex

const mergeArrays = (list1, list2) => {
  const mergedArry = []
  let i = 0
  let index1 = 0
  let index2 = 0
  const len = list1.length + list2.length

  while (listIterationComplete(list1, index1) === false || listIterationComplete(list2, index2) === false) {
    if ( listIterationComplete(list2, index2) || (list1[index1] < list2[index2]) ) {
      mergedArry[i++] = list1[index1++]
    } else if (listIterationComplete(list1, index1) || (list2[index2] < list1[index1]) ) {
      mergedArry[i++] = list2[index2++]
    }
  }
  return mergedArry
}

module.exports = mergeArrays
