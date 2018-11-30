const Stack = require('../ch7/stack')
const Queue = require('../ch8/queue')

const onlyHasOneChild = (node) => node && ((node.left === null && node.right) || (node.right === null && node.left))
const TO_LEFT_BRANCH = 1
const TO_RIGHT_BRANCH = 2
const TO_PARENT = 0

class Node {
  constructor(val) {
    this.left = null
    this.right = null
    this._val = val
  }

  get data() {
    return this._val
  }

  set data(val) {
    this._val = val
  }
}

const max = (x, y) => (x > y) ? x : y

const height = (node) => {
  if (node == null) return -1;
  return 1 + max(height(node.left), height(node.right));
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

  _incrementCount() {
    this.count++
  }

  _decrementCount() {
    this.count--
  }

  get height() {
    return height(this.root)
  }

  insert(val) {
    if (this.isEmpty()) {
      this.root = new Node(val)
    } else {
      let current = this.root
      let trailCurrent = null
      while (current !== null) {
        trailCurrent = current
        if (current.data === val) return false
        current = (val > current.data) ? current.right : current.left
      }

      if (trailCurrent === null) {
        this.root = new Node(val)
      } else if (val > trailCurrent.data) {
        trailCurrent.right = new Node(val)
      } else {
        trailCurrent.left = new Node(val)
      }
    }
    this._incrementCount()
    return true
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

  _inOrderTraversal(node, cb) {
    if (node !== null) {
      this._inOrderTraversal(node.left, cb)
      cb(node.data)
      this._inOrderTraversal(node.right, cb)
    }
  }

  inOrder(cb) {
    this._inOrderTraversal(this.root, cb)
  }

  preOrder(cb) {
    this._preOrderTraversal(this.root, cb)
  }

  _preOrderTraversal(node, cb) {
    if (node !== null) {
      cb(node.data)
      this._preOrderTraversal(node.left, cb)
      this._preOrderTraversal(node.right, cb)
    }
  }

  postOrder(cb) {
    this._postOrderTraversal(this.root, cb)
  }

  _postOrderTraversal(node, cb) {
    if (node !== null) {
      this._postOrderTraversal(node.left, cb)
      this._postOrderTraversal(node.right, cb)
      cb(node.data)
    }
  }

  swapSubtrees(node = this.root) {
    if ((node === null) || (node.left === null && node.right === null)) return void(0)

    const temp = node.left
    node.left = node.right
    node.right = temp

    this.swapSubtrees(node.left)
    this.swapSubtrees(node.right)
  }

  singleParent() {
    let singleParentCount = 0
    const stack = new Stack()
    let current = this.root

    while (current !== null || stack.isEmpty() === false) {
      if (current !== null) {
        stack.push(current)
        if (onlyHasOneChild(current)) singleParentCount++
        current = current.left
      } else {
        current = stack.pop()
        current = current.right
      }
    }
    return singleParentCount
  }

  iterativeInOrder(cb) {
    let current = this.root
    const stack = new Stack()

    while (current !== null || stack.isEmpty() === false) {
      if (current !== null) {
        stack.push(current)
        current = current.left
      } else {
        current = stack.pop()
        cb(current.data)
        current = current.right
      }
    }
  }

  iterativePreOrder(cb) {
    let current = this.root
    const stack = new Stack()

    while (current !== null || stack.isEmpty() === false) {
      if (current !== null) {
        cb(current.data)
        stack.push(current)
        current = current.left
      } else {
        current = stack.pop()
        current = current.right
      }
    }
  }

  iterativePostOrder(cb) {
    let current = this.root
    const visitStack = new Stack()
    const nodeStack = new Stack()
    let visit = TO_PARENT

    if (current !== null) {
      nodeStack.push(current)
      visitStack.push(TO_LEFT_BRANCH)
      current = current.left

      while (nodeStack.isEmpty() === false) {
        if (current !== null && visit === TO_PARENT) {
          nodeStack.push(current)
          visitStack.push(TO_LEFT_BRANCH)
          current = current.left
        } else {
          visit = visitStack.pop()
          current = nodeStack.pop()

          if (visit === TO_LEFT_BRANCH) {
            nodeStack.push(current)
            visitStack.push(TO_RIGHT_BRANCH)
            current = current.right
            visit = TO_PARENT
          } else {
            cb(current.data)
          }
        }
      }
    }
  }

  _deleteHelper(node) {
    if (node === null) throw new Error('Cannot delete "null" from a tree')
    else if (node.left === null && node.right === null) {
      return null
    } else if (node.left === null) {
      return node.right
    } else if (node.right === null) {
      return node.left
    } else {
      let current = node.left
      let trailCurrent = null

      while (current.right !== null) {
        trailCurrent = current
        current = current.right
      }

      node.data = current.data

      if (trailCurrent === null) node.left = current.left
      else trailCurrent.right = current.left

      return node
    }
  }

  delete(deleteVal) {
    if (this.root === null) {
      return false
    } else {
      let current = this.root
      let trailCurrent = this.root
      let found = false

      while (current !== null && found === false) {
        if (current.data === deleteVal) found = true
        else {
          trailCurrent = current
          current = (current.data > deleteVal) ? current.left : current.right
        }
      }

      if (current === null) return false
      else if (found) {
        if (current === this.root) this.root = this._deleteHelper(this.root)
        else if (trailCurrent.data > deleteVal) trailCurrent.left = this._deleteHelper(trailCurrent.left)
        else trailCurrent.right = this._deleteHelper(trailCurrent.right)
      }
    }
    return true
  }
}

module.exports = BinaryTree
