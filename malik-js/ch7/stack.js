class Node {
    constructor(val = null) {
        this.info = val
        this.link = null
    }
}

class Stack {
    constructor() {
        this.front = null
    }

    push(val) {
        const node = new Node(val)
        if (this.isEmpty()) {
            this.front = node
        } else {
            node.link = this.front
            this.front = node
        }
    }

    top() {
        if (this.isEmpty()) return null
        return this.front.info
    }

    pop() {
        if (this.isEmpty()) return null
        const val = this.front.info
        this.front = this.front.link
        return val
    }

    isEmpty() {
        return this.front === null
    }
}


module.exports = Stack
