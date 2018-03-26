const Node = require('./Node');

class LinkedList {
    constructor() {
        this._reset()
    }

    _reset() {
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

    rEach(cb, node = this._first, index = this._count - 1) {
        if (index >= 0) {
            console.log('here is the index', index)
            console.log('here is the info: ', node.info)
            this.rEach(cb, node.link, index)
            cb(node.info, index)
        }
    }

    destroy() {
        this._reset()
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
                    const value = current.info
                    current = current.link
                    return {
                        value,
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

    deleteMin() {
        // case 1: list is empty, return false
        // case 2: search for smallest value
        // we need to keep track of two currents and two prev's (one for searching the list and another for the min)
        // if the element to be deleted is the first element, we must re-assign the first element
        let deleted = false

        if (this.isEmpty()) deleted = false
        else if (this.length === 1) {
            this._reset()
            deleted = true
        }
        else {
            let prev = this._first
            let current = this._first.link

            let minPrev = null
            let min = this._first

            while (current != null) {
                if (current.info < min.info) {
                    min = current
                    minPrev = prev
                }
                prev = current
                current = current.link
            }

            if (this._first === min) this._first = min.link
            else if (this._last === min) {
                this._last = minPrev
                this._last.link = null
            } else {
                minPrev.link = min.link
            }
            deleted = true
        }
        return deleted
    }

    deleteAll(item) {
        let deleted = false
        if (this.isEmpty()) deleted = false
        else {
            let found = false
            let prev = null
            let current = this._first

            while (current !== null) {
                if (current.info === item) {
                    if (current === this._first) {
                        this._first = current.link
                    } else if (current === this._last) {
                        this._last = prev
                        this._last.link = null
                    } else {
                        prev.link = current.link
                    }
                    deleted = true
                }
                prev = current
                current = current.link
            }
        }
        return deleted
    }

    at(i) {
        if (i < 0 || i >= this.length) return null
         else {
             let tracker = 0
             let current = this._first

             while (tracker < i) {
                current = current.link
                 tracker++
             }
             return current.info
         }
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
