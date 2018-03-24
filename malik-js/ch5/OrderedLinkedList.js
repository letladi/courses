const Node = require('./Node')
const LinkedList = require('./LinkedList')

class OrderedLinkedList extends LinkedList {
    constructor() {
        super()
    }

    search(item) {
        let found = false
        let current = this._first

        while (current !== null && found === false)
            if (current.info >= item) found = true
            else current = current.link

        if (found) found = (current.info === item)

        return found
    }

    insert(item) {
        let current = new Node()
        let prev = new Node()
        let newNode = new Node(item)
        let found = false

        if (this._first === null) {
            this._first = newNode
            this._last = newNode
            this._count++
        } else {
            current = this._first
            while (current !== null && found === false)
                if (current.info >= item) found = true
                else {
                    prev = current
                    current = current.link
                }

            if (current === this._first) {
                newNode.link = this._first
                this._first = newNode
                this._count++
            } else {
                prev.link = newNode
                newNode.link = current
                if (current === null) this._last = newNode
                this._count++
            }
        }
    }

    insertFirst(item) {
        this.insert(item)
    }

    insertLast(item) {
        this.insert(item)
    }

    delete(item) {
        let current = null
        let prev = null
        let found = false
        let deleted = false

        if (this._first === null) deleted = false
        else {
            current = this._first

            while (current !== null && found === false)
                if (current.info >= item) found = true
                else {
                    prev = current
                    current = current.link
                }

            if (current === null) deleted = false
            else if (current.info === item) {
                if (this._first === current) {
                    this._first = this._first.link
                    if (this._first === null) this._last = null
                } else {
                    prev.link = current.link
                    if (current === this._last) this._last = prev
                }
                this._count--
                deleted = true
            } else {
                deleted = false
            }
        }
        return deleted
    }
}

module.exports = OrderedLinkedList
