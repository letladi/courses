const Person = require('./Person')

class Candidate extends Person {
  constructor(name, surname) {
    super(name, surname)
    this.votingData = {}
    this._totalVotesReceived = 0
  }
  addVotes(region, votes) {
    this.votingData[region] = (this.votingData[region] || 0) + votes
    this._totalVotesReceived += votes
  }

  get totalVotes() {
    return this._totalVotesReceived
  }

  getRegionVotes(region) {
    return this.votingData[region] || 0
  }

  compare(other, key = 'totalVotes') {
    if (this[key] < other[key]) return -1
    else if (this[key] > other[key]) return 1
    else return 0
  }
}

module.exports = Candidate
