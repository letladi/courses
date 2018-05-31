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
}

module.exports = Queue
