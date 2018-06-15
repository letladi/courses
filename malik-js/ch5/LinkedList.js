const Node = require('./Node');
const sort = require('../ch10/quickSort')

const isEven = (n) => n % 2 === 0

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

    rEach(cb, node = this._first, index = 0) {
        if (node !== null) {
            this.rEach(cb, node.link, index + 1)
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

    deleteMin(from = 0) {
       let deleted = false
       let min = null
       let minPrev = null

        if (this.isEmpty() || (from < 0 || from >= this.length)) deleted = false
        else if (this.length === 1) {
            min = this._first
            this._reset()
            deleted = true
        }
        else {
            let prev = this._first
            let current = this._first.link

            minPrev = null
            min = prev

            let i = 0
            while (i < from) {
              minPrev = min
              min = prev = current
              current = current.link
              i++
            }

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
            this._count--
            deleted = true
        }
        return deleted ? min.info : false
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
                    this._count--
                }
                prev = current
                current = current.link
            }
        }
        return deleted
    }

    deleteAt(i) {
        let deleted = false
        if (i < 0 || i >= this.length) deleted = false
        else {
            let prev = null
            let current = this._first

            let tracker = 0
            while (tracker < i) {
                prev = current
                current = current.link
                tracker++
            }
            if (current === this._first) {
                this._first = current.link
            }
            else if (current === this._last) {
                this._last = prev
                this._last.link = null
            } else {
                prev.link = current.link
            }
            this._count--
            deleted = true
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

    divideMid() {
        const list = new LinkedList()

        if (this.length === 1 || this.isEmpty()) return list

        const len = this.length
        const dividedLen = len / 2
        let numElementsInCurrentList = isEven(len) ? dividedLen : Math.floor(dividedLen) + 1
        this._count = numElementsInCurrentList
        let indexOfFirstElementInSecondList = numElementsInCurrentList
        let count = 0
        let current = this._first
        let prev = null
        while (count < numElementsInCurrentList) {
            prev = current
            current = current.link
            count++
        }

        this._last = prev
        this._last.link = null

        while (current !== null) {
            list.insertLast(current.info)
            current = current.link
        }
        return list
    }

    divideAt(val) {
        const list = new LinkedList()

        if (this.isEmpty()) return list

        let found = false
        let index = 0
        let prev = null
        let current = this._first

        while (current && found === false) {
            if (current.info === val) found = true
            else {
                prev = current
                current = current.link
                index++
            }
        }

        if (found === false) return list
        else {
            this._count = index
            this._last = prev

            if (index === 0) this._first = this._last = null
            else this._last.link = null

            while (current) {
                list.insertLast(current.info)
                current = current.link
            }
            return list
        }
    }

    selectionSort() {
      for (let i = 0, len = this.length; i < len; i++) {
        this.insertFirst(this.deleteMax(i))
      }
    }

    deleteMax(from = 0) {
       let deleted = false
       let max = null
       let maxPrev = null

        if (this.isEmpty() || (from < 0 || from >= this.length)) deleted = false
        else if (this.length === 1) {
            max = this._first
            this._reset()
            deleted = true
        }
        else {
            let prev = this._first
            let current = this._first.link

            maxPrev = null
            max = prev

            let i = 0
            while (i < from) {
              maxPrev = max
              max = prev = current
              current = current.link
              i++
            }

            while (current != null) {
                if (current.info > max.info) {
                    max = current
                    maxPrev = prev
                }
                prev = current
                current = current.link
            }

            if (this._first === max) this._first = max.link
            else if (this._last === max) {
                this._last = maxPrev
                this._last.link = null
            } else {
                maxPrev.link = max.link
            }
            this._count--
            deleted = true
        }
        return deleted ? max.info : false
    }

    quickSort() {
      const entries = this.entries()
      sort(entries)
      this.destroy()
      entries.forEach((el) => this.insertLast(el))
    }
}

module.exports = LinkedList
