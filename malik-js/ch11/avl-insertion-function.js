_insertionHelper(root, newNode) {
  if (root === null) {
    this.isTaller = true
    return newNode
  }
  else if (root.data === newNode.data) throw new Error('Duplicates are not allowed')
  else if (root.data > newNode.data) {
    root.left = this._insertionHelper(root.left, newNode)

    if (this.isTaller) {
      switch (root.bf) {
        case -1: // it was left high, now it's higher than that, so we must perform a right rotation
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
