const binarySearch = require('./binarySearch')

class Node {
  constructor(order) {
    this.count = 0
    this.list = []
    this.children = []
    this.order = order
  }
}

const insertNode = (node, item, rightChild, insertPosition) => {
  let index = null
  for (index = node.count; index > insertPosition; index--) {
    node.list[index] = node.list[index - 1]
    node.children[index + 1] = node.children[index]
  }
  node.list[index] = item
  node.children[index + 1] = rightChild
  node.count++
}

const searchNode = (node, item) => {
  const location = binarySearch(node.list, item)
  return { found: node.list[location] === item, location }
}

const getMedian = (node) => {
  const index = (node.count - 1) / 2
  let value = node.list[index]
  return { index, value }
}

const isFalsy= (val) => (!!val) === false

const isLeaf = (node) => (!!node) && node.children.every((child) => isFalsy(child))

const nodeViolatesOrderInvariant = (node) => node.count === node.order

const splitNode = (node) => {
  const median = getMedian(node)
  const right = new Node(node.order)
  right.list = node.list.splice(median.index)
  right.list.shift()
  right.count = right.list.length

  right.children = node.children.splice(median.index + 1)

  node.count = node.list.length

  return { left: node, right, median }
}

class BTree {
  constructor(order) {
    this._order = order
    this.root = null
  }

  search(root = this.root, item) {
    let current = root
    let insertPosition = null

    while (current !== null) {
      const { found, location } = searchNode(current, item)
      insertPosition = location
      if (found) return true
      else current = current.children[location]
    }
    return false
  }

  get leaveCount() {
    let count = 0
    this._leaveCountHelper(this.root, (leaf) => count++)
    return count
  }

  get height() {
    return (isFalsy(this.root)) ? 0 : this._heightHelper(this.root) - 1
  }

  _heightHelper(node, total = 0) {
    if (isFalsy(node)) return 0
    else if (isLeaf(node)) return 1
    else {
      for (let i = 0, len = node.children.length; i < len; i++) {
        total += Math.max(this._heightHelper(node.children[i], total), total)
      }
      return total
    }
  }

  _leaveCountHelper(node, cb) {
    if (node) {
      for (let i = 0; i <= node.count; i++) {
        if (isLeaf(node.children[i])) cb(node.children[i])
        else this._leaveCountHelper(node.children[i], cb)
      }
    }
  }

  set order(_unused) {
    throw new Error('The order of a tree may not be changed after the tree is created')
  }

  get order() {
    return this._order
  }

  insert(item) {
    try {
      const newRoot = this._insertionHelper(this.root, item)
      if (nodeViolatesOrderInvariant(newRoot)) {
      const { median, right, left } = splitNode(newRoot)
      const temp = new Node(this.order)
      temp.list[temp.count++] = median.value
      temp.children[0] = left
      temp.children[1] = right
      this.root = temp
      } else {
        this.root = newRoot
      }
      return true
    } catch (e) {
      return false
    }
  }

  _insertionHelper(node, item) {
    if (node === null) {
      node = new Node(this.order)
      insertNode(node, item, null, 0)
      return node
    } else if (searchNode(node, item).found) throw new Error('no duplicates allowed in the tree')
    else if (isLeaf(node)) {
      const { location } = searchNode(node, item)
      insertNode(node, item, null, location)
      return node
    }
    else {
      let i = 0
      const numElementsInNode = node.count
      while (item > node.list[i] && i < numElementsInNode) i++

      const returnedNode = this._insertionHelper(node.children[i], item)

      if (nodeViolatesOrderInvariant(returnedNode)) {
        const { median, right } =  splitNode(returnedNode)
        const insertPos = searchNode(node, median.value)
        insertNode(node, median.value, right, insertPos)
        return node
      } else
        return node
    }
  }
}

module.exports = BTree
