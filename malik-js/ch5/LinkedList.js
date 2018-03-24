const Node = require('./Node');

class LinkedList {
    constructor() {
        this.__reset()
    }

    __reset() {
        this._first = null
        this._last = null
        this._count = 0
    }

    isEmpty() {
        return this._first === null;
    }

    get length() {
        return this._count;
    }

    get front() {
        if (this.isEmpty()) throw Error('list is empty')
        return this._first.info;
    }

    get back() {
        if (this.isEmpty()) throw Error('list is empty')
        return this._last.info;
    }

    each(cb) {
        let count = 0
        for (const el of this) cb(el, count++)
    }

    destroy() {
        this.__reset()
    }

    iterator() {
        return this[Symbol.iterator]()
    }

    entries() {
        const entries = []
        for (const el of this) entries.push(el)
        return entries
    }

    [Symbol.iterator]() {
        let current = this._first

        return {
            next() {
                if (current) {
                    const temp = current
                    current = current.link
                    return {
                        value: temp.info,
                        done: false,
                    }
                } else {
                    return {
                        done: true,
                    }
                }
            }
        }
    }

    insertFirst(item) {
        let node = new Node(item)
        node.link = this._first
        this._first = node
        this._count++

        if (this._last === null) this._last = node
    }

    insertLast(item) {
        let node = new Node(item)

        if (this._first === null) {
            this._first = node
            this._last = node
        } else {
            this._last.link = node
            this._last = node
        }
        this._count++
    }

    delete(item) {
        let current = null
        let prev = null
        let found = false
        let deleted = false

        if (this._first === null) deleted = false
        else {
            if (this._first.info === item) {
                current = this._first
                this._first = this._first.link
                this._count--

                if (this._first === null) this._last = null
                deleted = true
            } else {
                prev = this._first
                current = this._first.link

                while (current !== null && found === false) {
                    if (current.info !== item) {
                        prev = current
                        current = current.link
                    } else found = true
                }

                if (found) {
                    prev.link = current.link
                    this._count--

                    if (this._last === current) this._last = prev
                    deleted = true
                }
            }
        }

        return deleted
    }

    search(item) {
        let found = false
        let current = this._first

        while (current !== null && found === false)
            if (current.info === item) found = true
            else current = current.link

        return found
    }
}

module.exports = LinkedList
