const RANGE_TYPE = Symbol()
const DOMAIN_TYPE = Symbol()
const ZERO = 0x0

class Vector {
  constructor(domain, range) {
    this[RANGE_TYPE] = range
    this[DOMAIN_TYPE] = domain
  }

  set(key, val) {
    if (!this[DOMAIN_TYPE].includes(key)) this[DOMAIN_TYPE].push(key)
    this[RANGE_TYPE][key] = val
  }

  get(key) {
    return this[RANGE_TYPE][key] || ZERO
  }

  scale(scalar) {
    const newRange = {}
    for (const el of this[DOMAIN_TYPE]) {
      if (this[RANGE_TYPE][el]) newRange[el] = this[RANGE_TYPE][el] * scalar
    }
    const ret = new Vector(this[DOMAIN_TYPE], newRange)
    return ret
  }

  divide(scalar) {
    return this.scale(1/scalar)
  }

  add(other) {
    const range1 = this[RANGE_TYPE]
    const domain = this[DOMAIN_TYPE]
    const range2 = other[RANGE_TYPE]
    const resultingRange = {}
    for (const x of domain) {
      if (range1[x]) {
        if (range2[x]) resultingRange[x] = range1[x] + range2[x]
        else resultingRange[x] = range1[x]
      }
    }

    const ret = new Vector(domain, resultingRange)
    return ret
  }

  negative() {
    return this.scale(-1)
  }

  subtract(other) {
    return this.add(other.negative())
  }

  dot(other) {
    let ret = 0
    for (const el of this[DOMAIN_TYPE]) {
      if (this[RANGE_TYPE][el] && other[RANGE_TYPE][el]) {
        ret += this[RANGE_TYPE][el] * other[RANGE_TYPE][el]
      }
    }
    return ret
  }

  equals(other) {
    if (this[DOMAIN_TYPE] !== other[DOMAIN_TYPE]) return false
    for (const el in this[RANGE_TYPE]) {
      if (!other[RANGE_TYPE][el] || this[RANGE_TYPE][el] !== other[RANGE_TYPE][el]) return false
    }
    return true
  }

  clone() {
    return this.scale(1)
  }

  toString() {
    return `Vector([${JSON.stringify(this[DOMAIN_TYPE])}], ${JSON.stringify(this[RANGE_TYPE])})`
  }

  static fromList(list) {
    const resultingRange = {}
    const resultingDomain = []

    list.forEach((el, i) => {
      resultingDomain[i] = i
      resultingRange[i] = el
    })

    const vec = new Vector(resultingDomain, resultingRange)
    return vec
  }

  static zero() {
    const vec = new Vector([], {})
    return vec
  }

  static solveTriangular(list) {

  }

  static lineardCombo(vlist, clist) {
    const resultingRange = {}
    let ret = null
    vlist.forEach((vec, i) => {
      ret = (!ret) ? vec.scale(clist[i]) : ret.add(vec.scale(clist[i]))
    })
    return ret
  }

  static standard(vector) {
    const list = []
    const domain = vector[DOMAIN_TYPE]
    domain.forEach((dEl, i) => {
      list[i] = new Vector(domain, { [dEl]: 1 })
    })
    return list
  }
}

module.exports = Vector
