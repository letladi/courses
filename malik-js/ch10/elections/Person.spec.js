const Person = require('./Person')

describe('Person', () => {

  let letladi = null
  let octavius = null
  let kapei = null
  beforeEach(() => {
    letladi = new Person('Letladi', 'Sebesho')
    octavius = new Person('Kapei', 'Sebesho')
    kapei = new Person('Kapei', 'Sebesho')
  })
  afterEach(() => {
    letladi = octavius = kapei = null
  })

  describe('#equals', () => {
    test('true if the first name and last name are equal', () => {
      expect(kapei.equals(octavius)).toEqual(true)
    })
    test('false if the last name and last name are not equal', () => {
      expect(letladi.equals(kapei)).toEqual(false)
    })
  })

  test('.firstName - returns the first name', () => {
    expect(letladi.firstName).toEqual('Letladi')
  })
  test('.firstName= - sets the first name', () => {
    letladi.firstName = 'Robinson'
    expect(letladi.firstName).toEqual('Robinson')
  })
  test('.lastName - returns the last name', () => {
    expect(letladi.lastName).toEqual('Sebesho')
  })
  test('.lastName= - sets the last name', () => {
    octavius.lastName = 'Caesar'
    expect(octavius.lastName).toEqual('Caesar')
  })
})
