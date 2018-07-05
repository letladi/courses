const BST = require('./BSTree')
const Stack = require('../ch7/stack')

class Node {
  constructor(val) {
    this._val = val
    this._balanceFactor = 0
    this.left = null
    this.right = null
  }

  get data() {
    return this._val
  }

  set data(val) {
    this._val = val
  }

  get bf() {
    return this._balanceFactor
  }

  set bf(val) {
    this._balanceFactor = val
  }
}

const rotateToLeft = (node) => {
  if (node === null) throw new Error('Tree in invalid state; cannot rotate to left on an empty node')
  else if (node.right === null) throw new Error('Tree in invalid state; cannot rotate to left when there is no right subtree')

  const temp = node.right
  node.right = temp.left
  temp.left = node
  return temp
}

const rotateToRight = (node) => {
  if (node === null) throw new Error('Tree in invalid state; cannot rotate to right on an empty node')
  else if (node.left === null) throw new Error('Tree in invalid state; cannot rotate to right when there is no left subtree')

  const temp = node.left
  node.left = temp.right
  temp.right = node
  return temp
}

const balanceFromLeft = (node) => {
  const p = node.left

  switch (p.bf) {
    case -1:
      node.bf = 0
      p.bf = 0
      return rotateToRight(node)

    case 0: throw new Error('Tree does not need to be balanced from the left')

    case 1:
      const w = p.right
      switch (w.bf) {
        case -1:
          node.bf = 1
          p.bf = 0
          break

        case 0:
          node.bf = 0
          p.bf = 0
          break

        case 1:
          node.bf = 0
          p.bf = -1
      }

      w.bf = 0
      node.left = rotateToLeft(p)
      return rotateToRight(node)
  }
}

const balanceFromRight = (node) => {
  const p = node.right

  switch (p.bf) {
    case 1:
      node.bf = 0
      p.bf = 0
      return rotateToLeft(node)

    case 0: throw new Error('Tree does not need balancing from the right')

    case -1:
      const w = p.left
      switch (w.bf) {
        case -1:
          node.bf = 0
          p.bf = 1
          break

        case 0:
          node.bf = 0
          p.bf = 0
          break

        case 1:
          node.bf = -1
          p.bf = 0
      }

      w.bf = 0
      node.right = rotateToRight(p)
      return rotateToLeft(node)
  }
}

const max = (x, y) => (x > y) ? x : y

const height = (node) => {
  if (node == null) return -1;
  return 1 + max(height(node.left), height(node.right));
}

class AVLTree {

  constructor() {
    this.root = null
    this._count = 0
  }

  _incrementNodeCount() {
    this._count++
  }

  _decrementNodeCount() {
    this._count--
  }

  get nodeCount() {
    return this._count
  }

  get height() {
    return height(this.root)
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

  insert(val) {
    try {
      const newNode = new Node(val)
      this.isTaller = false
      const newRoot = this._insertionHelper(this.root, newNode)
      this.root = newRoot
      this.isTaller = false
      this._incrementNodeCount()
      return true
    } catch (e) {
      return false
    }
  }

  _insertionHelper(root, newNode) {
    if (root === null) {
      this.isTaller = true
      return newNode
    }
    else if (root.data === newNode.data) throw new Error('Duplicates are not allowed')
    else if (root.data > newNode.data) {
      root.left = this._insertionHelper(root.left, newNode)
      return (this.isTaller) ? this.balanceGrowthFromLeftSubtree(root) : root
    } else {
      root.right = this._insertionHelper(root.right, newNode)
      return (this.isTaller) ? this.balanceGrowthFromRightSubtree(root) : root
    }
  }

  balanceGrowthFromLeftSubtree(node) {
    switch (node.bf) {
      case -1:
        const newNode = balanceFromLeft(node)
        this.isTaller = false
        return newNode

      case 0:
        node.bf = -1
        this.isTaller = true
        return node

      case 1:
        node.bf = 0
        this.isTaller = false
        return node
    }
  }

  balanceShrinkageFromLeftSubtree(node) {
    switch (node.bf) {
      case -1:
        node.bf = 0
        this.isShorter = true
        return node

      case 0:
        node.bf = 1
        this.isShorter = false
        return node

      case 1:
        const newNode = balanceFromRight(node)
        this.isShorter = false
        return newNode
    }
  }

  balanceShrinkageFromRightSubtree(node) {
    switch (node.bf) {
      case -1:
        const newNode = balanceFromLeft(node)
        this.isShorter = false
        return newNode

      case 0:
        node.bf = -1
        this.isShorter = false
        return node

      case 1:
        node.bf = 0
        this.isShorter = true
        return node
    }
  }

  balanceGrowthFromRightSubtree(node) {
    switch (node.bf) {
      case -1:
        node.bf = 0
        this.isTaller = false
        return node

      case 0:
        node.bf = 1
        this.isTaller = true
        return node

      case 1:
        const newRoot = balanceFromRight(node)
        this.isTaller = false
        return newRoot
    }
  }

  // delete(deleteVal) {
  //   if (this.root === null) {
  //     return false
  //   } else {
  //     let current = this.root
  //     let trailCurrent = this.root
  //     let found = false
  //
  //     while (current !== null && found === false) {
  //       if (current.data === deleteVal) found = true
  //       else {
  //         trailCurrent = current
  //         current = (current.data > deleteVal) ? current.left : current.right
  //       }
  //     }
  //
  //     if (current === null) return false
  //     else if (found) {
  //       if (current === this.root) this.root = this._deleteHelper(this.root)
  //       else if (trailCurrent.data > deleteVal) trailCurrent.left = this._deleteHelper(trailCurrent.left)
  //       else trailCurrent.right = this._deleteHelper(trailCurrent.right)
  //     }
  //   }
  //   return true
  // }

  delete(val) {
    try {
      this.isShorter = false
      const newRoot = this._deletionHelper(val, this.root)
      this.root = newRoot
      this.isShorter = false
      this._decrementNodeCount()
      return true
    } catch (e) {
      return false
    }
  }

  _deletionHelper(val, root) {
    if (root === null) throw new Error('Cannot delete an element that is not in the tree')
    else if (root.data === val) return this._removeNode(root)
    else if (root.data > val) {
      root.left = this._deletionHelper(val, root.left)
      return (this.isShorter) ? this.balanceShrinkageFromLeftSubtree(root) : root
    } else {
      root.right = this._deletionHelper(val, root.right)
      return (this.isShorter) ? this.balanceShrinkageFromRightSubtree(root) : root
    }
  }

  _removeNode(node) {
    if (node === null) throw new Error('Cannot delete "null" from a tree')

    this.isShorter = true

    if (node.left === null && node.right === null) {
      return null
    } else if (node.left === null) {
      return node.right
    } else if (node.right === null) {
      return node.left
    } else {
      const stack = new Stack()
      stack.push(node)
      let current = node.left
      let trailCurrent = null
      let parent = node

      while (current.right !== null) {
        stack.push(current)
        trailCurrent = current
        current = current.right
      }

      node.data = current.data

      if (trailCurrent === null) { // we didn't move
        node.left = current.left
        return node
      } else {
        trailCurrent.right = current.left

        let parent = stack.pop()
        let parentTrail = trailCurrent

        while (parent !== node) {
          if (this.isShorter) {
            parentTrail = this.balanceShrinkageFromRightSubtree(parentTrail)
            parent.right = parentTrail
          } else {
            parent.right = parentTrail
          }
          parentTrail = parent
          parent = stack.pop()
        }

        if (this.isShorter) {
          return parent.left = trailParent
          return parent
        } else {
          parent.left = this.balanceShrinkageFromLeftSubtree(trailParent)
          return parent
        }
      }

    }
  }
}

module.exports = AVLTree
