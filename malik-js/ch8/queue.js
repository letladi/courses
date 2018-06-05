class Node {
    constructor(val = null) {
        this.val = val
        this.link = null
    }
    get next() {
        return this.link
    }
    set next(val) {
        this.link = val
    }
    get info() {
        return this.val
    }
    set info(val) {
        this.val = val
    }
}

class Queue {
    constructor() {
        this.reset()
    }
    reset() {
        this.elCount = 0
        this.first = null
        this.last = null
    }
    get length() {
        return this.elCount;
    }
    isEmpty() {
        return this.length === 0
    }
    enqueue(val) {
        const node = new Node(val)
        if (this.isEmpty()) {
            this.first = this.last = node
        } else {
            this.last.next = node
            this.last = node
        }
        this.elCount++
    }
    dequeue() {
        const ret = this.front
        this.elCount--
        this.first = this.first.next
        return ret
    }
    get front() {
        if (this.isEmpty()) throw new Error('You may not read an empty queue')
        return this.first.info
    }
    get back() {
        if (this.isEmpty()) throw new Error('You may not read an empty queue')
        return this.last.info
    }

    moveNthFront(n) {
        const i = n - 1
        if (n > this.length) throw new Error('index of bounds error (the index to be moved does not exist)')
        let current = this.first
        let prev = null
        let count = 0
        while (count < i) {
            prev = current
            current = current.next
            count++

        }

        if (current === this.last) {
            prev.next = null
        }
        current.next = this.first
        this.first = current
    }
}

module.exports = Queue
