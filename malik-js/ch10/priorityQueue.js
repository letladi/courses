const { swap } = require('./util')

class PriorityQueue {
  constructor() {
    this._list = []
    this._count = 0
  }

  enqueue(val) {
    this._list[this._count++] = val
    this._turnToHeap()
  }

  _turnToHeap(list = this._list) {
    for (let len = this.length, i = Math.floor(len / 2) - 1; i >= 0; i--) {
      this._ensureHeapFormation(list, i, len - 1)
    }
  }

  _ensureHeapFormation(list = this._list, lo = 0, hi = this.length - 1) {
    let largeIndex = (lo * 2) + 1

    while (largeIndex <= hi) {
      if (largeIndex < hi)
        if (list[largeIndex] < list[largeIndex + 1]) largeIndex = largeIndex + 1

      if (list[lo] > list[largeIndex]) break
      else {
        swap(list, lo, largeIndex)
        lo = largeIndex
        largeIndex = largeIndex * 2 + 1
      }
    }
  }

  dequeue() {
    if (this.isEmpty() === false) {
      const val = this._list[0]
      swap(this._list, 0, --this._count)
      this._list[this._count] = void(0)
      this._ensureHeapFormation()
      return val
    } else return null
  }

  get length() {
    return this._count
  }

  isEmpty() {
    return this.length === 0
  }
}

module.exports = PriorityQueue
