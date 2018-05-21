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
        this.list.deleteAt(0)
        return val
    }

    top() {
        try {
            return this.list.front
        } catch (e) {
            return null
        }
    }

    isEmpty() {
        return this.list.isEmpty()
    }
}

module.exports = Stack
