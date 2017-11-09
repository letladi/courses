const hasCycle = (list) => {
  let slowRunner = list
  let fastRunner = list 

  // until we hit the end of the list
  while (fastRunner && fastRunner.next) {
    slowRunner = slowRunner.next 
    fastRunner = fastRunner.next.next 

    if (fastRunner === slowRunner) {
      return true
    }
  }

  return false
}

module.exports = {
	hasCycle
}