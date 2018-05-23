const closedRangeElements = (begin, n) => {
    const ret = []
    let i = 0
    while (begin <= n) ret[i++] = begin++
    return ret
}

const isDivisibleBy = (n, d) => n % d === 0

function primeSieve(n) {
    if (this[n]) return this[n]
    else {
        let nums = closedRangeElements(2, n)
        for (let i = 0, len = nums.length; i < len - 1; i++) {
            for (let j = i + 1; j < len; j++) {
                if (isDivisibleBy(nums[j], nums[i])) nums[j] = void(0)
            }
        }
        nums = nums.filter((x) => x !== void(0))
        this[n] = nums
        return nums
    }
}

module.exports = primeSieve
