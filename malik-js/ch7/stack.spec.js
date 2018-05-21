const Stack = require('./stack')

describe('Stack', () => {
    let stack = null
    beforeEach(() => stack = new Stack())
    afterEach(() => stack = null)

    describe('#isEmpty', () => {
        test('returns true if empty', () => {
            expect(stack.isEmpty()).toEqual(true)
        })
        test('returns false if not empty', () => {
            stack.push(4)
            expect(stack.isEmpty()).toEqual(false)
        })
    })
    describe('#top', () => {
        test('returns top-most element', () => {
            stack.push(1)
            stack.push(2)
            expect(stack.top()).toEqual(2)
        })
        test('returns null if no top-most element exists', () => {
            expect(stack.top()).toEqual(null)
        })
    })
    describe('#push', () => {
        test('adds an element to the stack', () => {
            stack.push(1)
            expect(stack.isEmpty()).toEqual(false)
        })
    })
    describe('#pop', () => {
        test('removes and and returns top-most element from the stack', () => {
            const stack = new Stack()
            stack.push(3)
            stack.push(2)
            expect(stack.pop()).toEqual(2)
            expect(stack.pop()).toEqual(3)
        })

    })
})
