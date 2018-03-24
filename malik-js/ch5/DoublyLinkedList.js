class Node {
    constructor(info = null, back = null, next = null) {
        this._info = info
        this._back = back
        this._next = next
    }

    set info(info) {
        this._info = info
    }

    get info() {
        return this._info
    }

    set back(back) {
        this._back = back
    }

    get back() {
        return this._back
    }

    set next(next) {
        this._next = next
    }

    get next() {
        return this._next
    }
}

class DoublyLinkedList {
    constructor() {
        this._reset()
    }

    _reset() {
        this._first = null
        this._last = null
        this._count = 0
    }

    isEmpty() {
        return this._first === null
    }

    destroy() {
        this._reset()
    }

    each(cb) {
        let count = 0
        for (const el of this) cb(el, count++)
    }

    [Symbol.iterator]() {
        let current = this._first

        return {
            next() {
                if (current) {
                    const value = current.info
                    current = current.next
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

    iterator() {
        return this[Symbol.iterator]()
    }

    get length() {
        return this._count
    }

    front() {
        return this._first
    }

    back() {
        return this._last
    }

    search(item) {
        let found = false
        let current = this._first

        while (current !== null && found === false)
            if (current.info >= item) found = true
            else current = current.next

        if (found) found = (current.info === item)

        return found
    }

    insert(item) {

    }

    delete(item) {

    }
}
