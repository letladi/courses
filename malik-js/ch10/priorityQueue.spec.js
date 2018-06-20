const PriorityQueue = require('./priorityQueue')

describe('priorityQueue', () => {
  let queue = null
  beforeEach(() => queue = new PriorityQueue())
  afterEach(() => queue = null)

  test('#length - returns the number of elements in the list', () => {
    expect(queue.length).toEqual(0)
    const nums = [10, 20, 55, 200, 100]
    nums.forEach((n) => queue.enqueue(n))
    expect(queue.length).toEqual(5)
  })
  describe('#isEmpty', () => {
    test('returns true if the queue is empty', () => {
      expect(queue.isEmpty()).toEqual(true)
    })
    test('returns false if the queue is not empty', () => {
      queue.enqueue(1)
      expect(queue.isEmpty()).toEqual(false)
    })
  })
  test('#enqueue - adding elements should increase the size of the list', () => {
    expect(queue.length).toEqual(0)
    queue.enqueue(1)
    expect(queue.length).toEqual(1)
    queue.enqueue(2)
    expect(queue.length).toEqual(2)
  })
  describe('#dequeue', () => {
    test('should return the element with the highest priority', () => {
      const nums = [10, 20, 55, 200, 100]
      nums.forEach((n) => queue.enqueue(n))
      console.log('the queue', queue)
      const el = queue.dequeue()
      expect(el).toEqual(200)
    })
    test('should return null if the queue is empty', () => {
      const el = queue.dequeue()
      expect(el).toEqual(null)
    })
    test('should decrease the length of the queue', () => {
      const nums = [10, 20, 55, 200, 100]
      nums.forEach((n) => queue.enqueue(n))
      queue.dequeue()
      expect(queue.length).toEqual(4)
    })
    test('should not affect the length if the list is empty', () => {
      expect(queue.length).toEqual(0)
      queue.dequeue()
      expect(queue.length).toEqual(0)
    })
  })
})
