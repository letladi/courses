function check(str = '', i = 0, j = str.length - 1) {
    if (i > j) return true
    else if (str[i] !== str[j]) return false
    else return check(str, i + 1, j - 1)
}

function isPalindrome(str = '') {
    if (str === '') return false
    str = str.toLowerCase()
    return check(str)
}

module.exports = isPalindrome
