class Node {
  constructor(order) {
    this.count = 0
    this.list = []
    this.children = []
    this.order = order
  }
}

class BTree {
  constructor(order) {
    this.order = order
  }

  set order(_) {
    throw new Error('The order of a tree may not be changed after the tree is created')
  }

  insert(item) {

  }
}

module.exports = BTree
