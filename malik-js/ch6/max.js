function max(nums = [], maximum = nums[0], lo = 0, hi = nums.length - 1) {
    return (lo === hi) ? maximum : max(nums, Math.max(maximum, nums[lo + 1]), lo + 1)
}

module.exports = max
