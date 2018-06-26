const Stack = require('../ch7/stack')

class Node {
  constructor(val) {
    this.left = null
    this.right = null
    this._val = val
  }

  get data() {
    return this._val
  }
}

class BinaryTree {
  constructor() {
    this.count = 0
    this.root = null
  }

  get nodeCount() {
    return this.count
  }

  isEmpty() {
    return this.nodeCount === 0
  }

  insert(val) {
    if (this.isEmpty()) {
      this.root = new Node(val)
      return true
    } else {
      let current = this.root
      let trailCurrent = null
      while (current !== null) {
        trailCurrent = current
        if (current.data === val) return false
        current = (val > current.data) ? current.right : current.left
      }

      console.log('here is the trailCurrent value', trailCurrent)

      if (trailCurrent === null) {
        this.root = new Node(val)
      } else if (val > trailCurrent.data) {
        trailCurrent.right = new Node(val)
      } else {
        trailCurrent.left = new Node(val)
      }
      console.log('here is the final tree', this.root)
      this.count++
      return true
    }
  }

  get leaveCount() {
    const stack = new Stack()

    let current = this.root
    let count = 0

    while (current !== null || stack.isEmpty() === false) {
      if (current !== null) {
        if (this.isLeaf(current)) count++
        stack.push(current)
        current = current.left
      } else {
        current = stack.pop()
        current = current.right
      }
    }

    return count
  }

  isLeaf(node) {
    return (node.left === null && node.right === null)
  }
}

module.exports = BinaryTree
