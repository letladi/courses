const Candidate = require('./Candidate')

describe('Candidate', () => {
  let candidate = null
  beforeEach(() => candidate = new Candidate('Letladi', 'Sebesho'))
  afterEach(() => candidate = null)

  describe('.totalVotes', () => {
    test('returns the total votes received accross all regions', () => {
      candidate.addVotes(2, 4)
      candidate.addVotes(1, 10)
      expect(candidate.totalVotes).toEqual(14)
    })
    test('returns 0 the candidate has not received any votes', () => {
      expect(candidate.totalVotes).toEqual(0)
    })
  })

  describe('#getRegionVotes', () => {
    test('returns the total number of votes received in a region', () => {
      candidate.addVotes(1, 17)
      candidate.addVotes(2, 4)
      candidate.addVotes(1, 10)
      expect(candidate.getRegionVotes(1)).toEqual(27)
    })
    test('returns 0 if the candidate has not received votes in the given region', () => {
      candidate.addVotes(2, 4)
      candidate.addVotes(1, 10)
      expect(candidate.getRegionVotes(3)).toEqual(0)
    })
  })

  describe('#compare', () => {
    let candidate1 = null
    let candidate2 = null
    let candidate3 = null
    beforeEach(() => {
      candidate1 = new Candidate('Letladi', 'Sebesho')
      candidate2 = new Candidate('Kapei', 'Sebesho')
      candidate3 = new Candidate('Adelaide', 'Sebesho')
      candidate4 = new Candidate('Silo', 'Qwabe')

      candidate1.addVotes(1, 17)
      candidate1.addVotes(2, 4)
      candidate1.addVotes(1, 10)

      candidate2.addVotes(3, 20)
      candidate2.addVotes(1, 5)

      candidate3.addVotes(1, 17)
      candidate3.addVotes(2, 4)
      candidate3.addVotes(1, 10)
    })
    afterEach(() => {
      candidate1 = null
      candidate2 = null
    })
    test('returns 0 if two candidates have the same total votes', () => {
      expect(candidate1.compare(candidate3)).toEqual(0)
    })
    test('returns -1 if the candidate has less votes than the "other" one', () => {
      expect(candidate2.compare(candidate1)).toEqual(-1)
    })
    test('returns 1 if the candidate has more votes than the "other" one', () => {
      expect(candidate1.compare(candidate2)).toEqual(1)
    })
    describe('can compare on on a specific property of the object', () => {
      test('returns 0 the two object are equal on that property', () => {
        expect(candidate1.compare(candidate2, 'lastName')).toEqual(0)
      })
      test('returns -1 if this object is less than the "other" on that property', () => {
        expect(candidate4.compare(candidate1, 'lastName')).toEqual(-1)
      })
      test('returns 1 if this object is greater than the "other" on that  property', () => {
        expect(candidate1.compare(candidate4, 'lastName')).toEqual(1)
      })
    })
  })
})
