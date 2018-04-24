const isVowel = (c = '') => /[aeiou]/.test(c)

function vowelCount(str = '', total = 0, i = 0) {
    if (i === str.length) return total
    total  += isVowel(str[i]) ? 1 : 0
    return vowelCount(str, total, i + 1)
}

module.exports = vowelCount
