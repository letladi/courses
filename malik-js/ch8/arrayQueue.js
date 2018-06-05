
class Queue {
    constructor(maxSize = 5) {
        this._maxSize = maxSize
        this.reset()
    }

    reset() {
        this._list = new Array(this._maxSize)
        this._front = this._last = -1
        this._count = 0
    }

    isEmpty() {
        return this.length === 0
    }

    isFull() {
        return (this.size === this.length)
            || ((this._front === 0) && (this._last === this.maxSize - 1))
            || (this._front === this._last + 1)
    }

    _getNextIndex(i) {
        return (i + 1) % this.size
    }

    _getNormalizedIndex(i) {
        return i % this.size
    }

    enqueue(val) {
        if (this.isFull()) throw new Error('cannot enqueue to a full queue')
        if (this.isEmpty()) {
            this._front = this._getNextIndex(this._front)
            this._list[this._front] = val
        }
        this._last = this._getNextIndex(this._last)
        this._list[this._last] = val
        this._count++
    }

    dequeue() {
        if (this.isEmpty()) throw new Error('cannot dequeue an empty queue')
        const val = this.front
        this._front = this._getNextIndex(this._front)
        this._count--
        return val
    }

    get length() {
        return this._count
    }

    get size() {
        return this._maxSize
    }

    get back() {
        if (this.isEmpty()) throw new Error('cannot read from an empty queue')
        return this._list[this._last]
    }

    get front() {
        if (this.isEmpty()) throw new Error('cannot read from an empty queue')
        return this._list[this._front]
    }

    moveNthFront(n) {
        const i = n - 1
        if (i > this.length) throw new Error('index of bounds error (the index to be moved does not exist)')
        let queueIdx = this._getNormalizedIndex(this._front + i)

        const val = this._list[queueIdx]

        if (queueIdx < this._front) {
            let track = this._front
            while (queueIdx > 0) {
                this._list[queueIdx] = this._list[queueIdx - 1]
                queueIdx--
            }

            let index = this._list.length - 1
            while (index > this._front) {
                this._list[index] = this._list[index - 1]
                index--
            }
            this._list[index] = val
        } else {
            while (queueIdx > this._front) {
                this._list[queueIdx] = this._list[queueIdx - 1]
                queueIdx--
            }
            this._list[queueIdx] = val
        }
    }
}

module.exports = Queue
