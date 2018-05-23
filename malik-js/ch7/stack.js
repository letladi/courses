const LinkedList = require('../ch5/LinkedList')

class Stack {
    constructor() {
        this.list = new LinkedList
    }

    push(val) {
        this.list.insertFirst(val)
    }

    pop() {
        const val = this.top()
        if (val) this.list.deleteAt(0)
        return val
    }

    top() {
        return this.isEmpty() ? null : this.list.front
    }

    isEmpty() {
        return this.list.isEmpty()
    }
}

module.exports = Stack
