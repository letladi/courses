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

const replaceItemAtLocation = (node, item, location) => {
  node.list[location] = item
}

const deleteFromNode = (node, item, location) => {
  const child = node.children[location + 1]
  for (let index = location; index < node.count; index++) {
    node.list[index] = node.list[index + 1]
    node.children[index + 1] = node.children[index]
  }
  node.list.pop()
  node.children.pop()
  node.count--
  return child
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

const isFalsy = (val) => (!!val) === false
const isTruthy = val => !isFalsy(val)

const isLeaf = (node) => (!!node) && node.children.every((child) => isFalsy(child))

const nodeViolatesOrderInvariantMax = (node) => node.count === node.order

const minimumRequiredKeys = (node) => Math.ceil(node.order / 2) - 1
const keyCount = (node) => node.count
const childrenCount = (node) => node.children.filter((el) => isTruthy(el)).length
const keysEqualToRequiredMinimum = (node) => keyCount(node) === minimumRequiredKeys(node)
const keysGreaterThanRequiredMininum = (node) => keyCount(node) > minimumRequiredKeys(node)
const keysLessThanRequiredMinimum = (node) => keyCount(node) < minimumRequiredKeys(node)

const removeLastItem = node => {
  const item = node.list.pop()
  node.children.pop()
  node.count--
  return item
}

const removeFirstItem = node => {
  node.count--
  node.children.pop()
  return node.list.shift()
}

const getLastItem = node => node.list[node.count - 1]

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

const replaceLastItem = (node, item) => node.list[node.count - 1] = item
const getItemAt = (node, location) => node.list[location]

const mergeNodes = (left, right) => {
  for (let i = left.count, index = 0; index < right.count; index++, i++) {
    left.list[i] = right.list[index]
    left.children[i + 1] = right.list[index + 1]
  }
  return left
}

const getLastChild = (node) => {

  let i = 0
  let prev = null
  let current = node.children[i]
  while (isTruthy(current)) {
    prev = current
    current = node.children[++i]
  }
  return prev
}

const balanceTreeSiblings = (node, location) => {
  const leftSibling = node.children[location - 1]
  const rightSibling = node.children[location + 1]

  if (leftSibling) {
    if (keysGreaterThanRequiredMininum(leftSibling)) {
      const nodeToMerge = node.children[location]
      insertNode(nodeToMerge, node.list[location - 1], null, 0)
      node.list[location -1] = leftSibling.list[--leftSibling.count]
      leftSibling.list.pop()
      return node
    } else if (keysEqualToRequiredMinimum(leftSibling)) {
      leftSibling.list[leftSibling.count++] = node.list[location - 1]
      leftSibling.children[leftSibling.count] = null
      node.list.splice(location - 1, 1)

      const nodeToMerge = node.children[location]
      let i = 0
      while (nodeToMerge.list.length) {
        leftSibling.list[leftSibling.count++] = nodeToMerge.list[i++]
        leftSibling.children[leftSibling.count] = nodeToMerge.list[i]
        nodeToMerge.list.shift()
      }
      node.children.splice(location, 1)
      return (node.list.length) ? node : leftSibling
    }
  } else {
    if (keysGreaterThanRequiredMininum(rightSibling)) {
      const nodeToMerge = node.children[location]
      nodeToMerge.list[nodeToMerge.count++] = node.list[location]
      node.list[location] = rightSibling.list.shift()
      rightSibling.count--
      rightSibling.children.shift()
      return node
    } else if (keysEqualToRequiredMinimum(rightSibling)) {
      rightSibling.list[rightSibling.count++] = node.list[location]
      rightSibling.children[rightSibling.count] = null
      node.list.splice(location, 1)

      const nodeToMerge = node.children[location]
      let i = nodeToMerge.length
      while (nodeToMerge.list.length) {
        rightSibling.list[rightSibling.count++] = nodeToMerge.list.pop()
        rightSibling.children[rightSibling.count] = nodeToMerge.list[i--]
      }
      node.children.splice(location, 1)
      return (node.list.length) ? node : rightSibling
    }
  }
}

const swapWithChildPredessor = (node, location, item) => {
  let trailCurrent = null
  let current = node.children[location]
  while (current) {
    trailCurrent = current
    current = getLastChild(current)
  }
  const temp = trailCurrent.list[trailCurrent.count - 1]
  node.list[location] = temp
  trailCurrent.list[trailCurrent.count - 1] = item
}

class BTree {
  constructor(order) {
    this._order = order
    this.root = null
  }

  search(item) {
    let current = this.root
    while (current !== null) {
      const { found, location } = searchNode(current, item)
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

  _leaveCountHelper(node, cb) {
    if (node) {
      for (let i = 0, len = childrenCount(node); i <= len; i++) {
        if (isLeaf(node.children[i])) cb(node.children[i])
        else this._leaveCountHelper(node.children[i], cb)
      }
    }
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

  set order(_unused) {
    throw new Error('The order of a tree may not be changed after the tree is created')
  }

  get order() {
    return this._order
  }

  insert(item) {
    try {
      const newRoot = this._insertionHelper(this.root, item)
      if (nodeViolatesOrderInvariantMax(newRoot)) {
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
    } else if (searchNode(node, item).found) throw new Error('no duplicates allowed in the tree')
    else if (isLeaf(node)) {
      const { location } = searchNode(node, item)
      insertNode(node, item, null, location)
    }
    else {
      let i = searchNode(node, item).location

      const returnedNode = this._insertionHelper(node.children[i], item)

      if (nodeViolatesOrderInvariantMax(returnedNode)) {
        const { median, right } =  splitNode(returnedNode)
        const insertPos = searchNode(node, median.value)
        insertNode(node, median.value, right, insertPos)
      }
    }
    return node
  }

  delete(item) {
    try {
      const newRoot = this._deletionHelper(this.root, item)
      this.root = newRoot
      return true
    } catch (e) {
      return false
    }
  }

  _deletionHelper(node, item) {
    if (isFalsy(node)) throw new Error('Cannot delete an item that is not in the tree')
    else if (isLeaf(node)) {
      const { found, location } = searchNode(node, item)
      if (found === false) throw new Error('Cannot delete an item that is not in the tree')
      else deleteFromNode(node, item, location)
    } else {
      const { found, location } = searchNode(node, item)
      if (found) swapWithChildPredessor(node, location, item)
      node.children[location] = this._deletionHelper(node.children[location], item)
      if (keysLessThanRequiredMinimum(node.children[location])) {
        node = balanceTreeSiblings(node, location)
      }
    }
    return node
  }
}

module.exports = BTree
