const BSTree = require('./BSTree')

const nums = [60, 70, 90, 20, 55, 88, 28]
const T1 = new BSTree()
nums.forEach((n) => T1.insert(n))

const T2 = new BSTree()
T1.postOrder((el) => T2.insert(el))

const T3 = new BSTree()
T2.preOrder((el) => T3.insert(el))

let T3InOrderSequence = []
T3.inOrder((el) => T3InOrderSequence.push(el))

const printTreeDetails = (tree, treeName) => {
  console.log(`*** ${treeName} ***`)
  console.log(`${treeName} height: ${tree.height}`)
  console.log(`${treeName} leaf count: ${tree.leaveCount}`)
  console.log()
}
printTreeDetails(T1, 'T1')

printTreeDetails(T2, 'T2')

printTreeDetails(T3, 'T3')
console.log('T3 in-order sequence:', T3InOrderSequence.join(' - '))
console.log()
