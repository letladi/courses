const OrderedLinkedList = require('../ch5/OrderedLinkedList')
const BSTree = require('./BSTree')

const toOrderedLinkedList = (tree) => {
  const list = new OrderedLinkedList()
  tree.inOrder((el) => list.insert(el))
  return list
}

module.exports = toOrderedLinkedList
