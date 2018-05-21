class Stack {
    constructor() {
        this.list = []
        this.topI = -1
    }

    push(val) {
        this.list[++this.topI] = val
    }

    pop() {
        return (this.topI >= 0) ?  this.list[this.topI--] : null
    }

    top() {
        return this.list[this.topI] || null
    }

    isEmpty() {
        return this.topI === -1
    }
}

module.exports = Stack
