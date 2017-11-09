const reverse = (list) => {
  let current = list
  let prev = null

  while (current.next) {
    const temp = current

    current.next = prev 
    prev = current
    console.log('prev', prev)
    current = temp.next 
  }

  return current
}

module.exports = {
  reverse,
}