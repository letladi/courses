const {
  toCandidateCollection, readVotingData, processVotingData,
  sortCandidatesByLastName, toValuesArray,
  printElectionResults, readCandidateData,
} = require('./util')
const sort = require('../quickSort')

const votingData = readVotingData('./voteData.txt')
const candidateData = readCandidateData('./candData.txt')
const candidateCollection = processVotingData(votingData, toCandidateCollection(candidateData))
const sortedCandidateList = sortCandidatesByLastName(toValuesArray(candidateCollection))

printElectionResults(sortedCandidateList)
