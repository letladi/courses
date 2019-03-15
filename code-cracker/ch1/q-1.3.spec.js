const urlify = require('./q-1.3')

describe('q-1.3', () => {
  it('should work for "Mr John Smith        "', () => {
    expect(urlify("Mr John Smith        ")).toEqual('Mr%20John%20Smith')
  })
})
