const fact = (num, product = 1) => {
 return num === 0 ? product : fact(num - 1, num * product )
}

module.exports = fact
