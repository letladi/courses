const BST = require('./BSTree')

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

  get bf() {
    return this._balanceFactor
  }

  set bf(val) {
    this._balanceFactor = val
  }
}

const rotateToLeft = (node) => {
  if (node === null) throw new Error('Tree in invalid state; cannot rotate to left on an empty node')
  else if (node.right === null) throw new Error('Tree in invalid state; cannot rotate to left when there is not right subtree')

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
    else if (root.data === newNode.data) throw new Error('Duplicates are allowed')
    else if (root.data > newNode.data) {
      root.left = this._insertionHelper(root.left, newNode)

      if (this.isTaller) {
        switch (root.bf) {
          case -1:
            const newRoot = balanceFromLeft(root)
            this.isTaller = false
            return newRoot

          case 0:
            root.bf = -1
            this.isTaller = true
            return root

          case 1:
            root.bf = 0
            this.isTaller = false
            return root
        }
      } else return root
    } else {
      root.right = this._insertionHelper(root.right, newNode)

      if (this.isTaller) {
        switch (root.bf) {
          case -1:
            root.bf = 0
            this.isTaller = false
            return root

          case 0:
            root.bf = 1
            this.isTaller = true
            return root

          case 1:
            const newRoot = balanceFromRight(root)
            this.isTaller = false
            return newRoot
        }
      } else return root
    }
  }

}

module.exports = AVLTree
