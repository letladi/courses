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

class AVLTree extends BST {

  insert(val) {
    const newNode = new Node(val)
    this.isTaller = false
    return this._insertionHelper({ root: this.root, newNode, isOnLeftSubtree: false, isOnRightSubtree: false, parentOfRoot: null })
  }

  balanceFromLeft({ root, parentOfRoot }) {
    let p = root.left
    let w = null

    switch (p.bf) {
      case -1:
        root.bf = 0
        p.bf = 0
        this.rotateToRight({ root, parentOfRoot, isOnLeftSubtree: true })
        break
      case 0: throw new Error('Cannot balance from the left')
      case 1:
        w = p.right
        switch (w.bf) {
          case -1:
            root.bf = 1
            p.bf = 0
            break;
          case 0:
            root.bf = 0
            p.bf = 0
            break
          case 1:
            root.bf = 0
            p.bf = -1
        }

        w.bf = 0
        this.rotateToLeft({ root: p, parentOfRoot: root, isOnLeftSubtree: true })
        root.left = p
        this.rotateToRight({ root, parentOfRoot, isOnLeftSubtree: true })
    }
  }

  balanceFromRight({ root, parentOfRoot }) {
    let p = root.right
    let w = null

    switch (p.bf) {
      case -1:
        w = p.left
        switch (w.bf) {
          case -1:
            root.bf = 0
            p.bf = 1
            break;
          case 0:
            root.bf = 0
            p.bf = 0
            break
          case 1:
            root.bf = -1
            p.bf = 0
        }

        w.bf = 0
        this.rotateToRight({ root: p, parentOfRoot: root })
        root.right = p
        this.rotateToLeft({ root, parentOfRoot })
        break;
      case 0: throw new Error('Cannot balance from the left')
      case 1:
        root.bf = 0
        p.bf = 0
        this.rotateToLeft({ root, parentOfRoot })
    }
  }

  rotateToLeft({ root, parentOfRoot, isOnLeftSubtree }) {
    let p = null
    if (root === null) throw new Error('Tree in invalid state')
    else if (root.right === null) throw new Error('Tree in invalid state; no right subtree to rotate')
    else {
      p = root.right
      root.right = p.left

      p.left = root
      if (isOnLeftSubtree) parentOfRoot.left = p
      else  parentOfRoot.right = p
    }
  }

  rotateToRight({ root, parentOfRoot, isOnLeftSubtree }) {
    let p = null
    if (root === null) throw new Error('Tree in invalid state')
    else if (root.left === null) throw new Error('Tree in invalid state; no left subtree to rotate')
    else {
      p = root.left
      root.left = p.right
      p.right = root
      if (isOnLeftSubtree) parentOfRoot.left = p
      else parentOfRoot.right = p
    }
  }

  _insertionHelper({ root, newNode, isOnLeftSubtree, parentOfRoot }) {
    if (root === null) {
      if (parentOfRoot === null) this.root = newNode
      else if (isOnLeftSubtree) parentOfRoot.left = newNode
      else parentOfRoot.right = newNode

      this.isTaller = true
    } else if (root.data === newNode.data) return false
    else if (root.data > newNode.data) {
      this._insertionHelper({ root: root.left, newNode, parentOfRoot: root, isOnLeftSubtree: true })

      if (this.isTaller) {
        switch (root.bf) {
          case -1:
            this.balanceFromLeft({ root, parentOfRoot })
            this.isTaller = false
            break;
          case 0:
            root.bf = -1
            this.isTaller = true
            break
          case 1:
            root.bf = 0
            this.isTaller = false
        }
      }
    } else {
      this._insertionHelper({ root: root.right, newNode, parentOfRoot: root, isOnLeftSubtree: false })

      if (this.isTaller) {
        switch (root.bf) {
          case -1:
            root.bf = 0
            this.isTaller = false
            break
          case 0:
            root.bf = 1
            this.isTaller = true
            break
          case 1:
            this.balanceFromRight({ root, parentOfRoot })
            this.isTaller = false
        }
      }

    }
  }
}

module.exports = AVLTree
