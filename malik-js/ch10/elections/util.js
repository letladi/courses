const fs = require('fs')
const Candidate = require('./Candidate')
const sort = require('../quickSort')

const trim = (str = '') => str.trim()
const toArray = (str, byChar) => str.split(byChar)
const readFileData = (filename) => trim(fs.readFileSync(filename, 'utf8'))

const toCandidateCollection = (list) => {
  const candidates = new Map()

  for (const item of list) {
    const data = toArray(item, ' ')
    const [name, surname] = data
    const candidate = new Candidate(name, surname)
    candidates.set(item, candidate)
  }
  return candidates
}

const regions = new Set()
const getNumRegions = () => regions.size

let winningCandidate = void(0)
const getWinningCandidate = () => winningCandidate

const processVotingData = (dataList, candidateCollection) => {
  for (const item of dataList) {
    const [name, surname, region, votes] = item.split(' ')
    const fullName = `${name} ${surname}`
    const candidate = candidateCollection.get(fullName)
    candidate.addVotes(+region, +votes)
    regions.add(region)
    // we cache the winning candidate
    winningCandidate = winningCandidate || candidate
    if (winningCandidate === void(0)) {
      winningCandidate = candidate
    } else if (winningCandidate.totalVotes < candidate.totalVotes) winningCandidate = candidate
  }
  return candidateCollection
}

const sortCandidatesByLastName = (list) => {
  sort(list, (a, b) => (a.lastName < b.lastName) ? -1: 1)
  return list
}

const toValuesArray = (map) => {
  const ret = []
  let i = 0
  for (const [key, val] of map) ret[i++] = val
  return ret
}

const printElectionResultHeader = () => {
  console.log("\n-----------------------Election Results----------------------\t\n")
  console.log("Candidate Name\t\tRegion1\tRegion2\tRegion3\tRegion4\tTotal\n")
  console.log("--------------\t\t-------\t-------\t-------\t-------\t-----\n")
}

const printCandidateData = (candidate) => {
  let i = 1
  let info = `${candidate.firstName} ${candidate.lastName}\t\t`

  while (i <= getNumRegions()) {
    info += `${candidate.getRegionVotes(i)}\t`
    i++
  }
  info += `${candidate.totalVotes}\n`
  console.log(info)
}

const printWinningCandidate = () => {
  const winner = getWinningCandidate()
  console.log(`Winner: ${winner.firstName} ${winner.lastName}, Votes Received: ${winner.totalVotes}\n`)
}

const printTotal = (totalVotes) => {
  console.log(`Total votes polled: ${totalVotes}\n`)
}

const printElectionResults = (candidates) => {
  printElectionResultHeader()

  let totalVotes = 0
  for (const candidate of candidates) {
    printCandidateData(candidate)
    totalVotes += candidate.totalVotes
  }
  printWinningCandidate()
  printTotal(totalVotes)
}

const readDataFromFile = (filename) => toArray(trim(readFileData(filename)), '\n')

let votingData = null
const readVotingData = (filename) => votingData = votingData || readDataFromFile(filename)

let candidateData = null
const readCandidateData = (filename) => candidateData = candidateData || readDataFromFile(filename)

module.exports = {
  toCandidateCollection,
  processVotingData,
  sortCandidatesByLastName,
  toValuesArray,
  readVotingData,
  readCandidateData,
  printElectionResults,
}
