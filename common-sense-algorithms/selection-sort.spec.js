const { expect } = require('chai')
const sort = require('./selection-sort')

describe('selection-sort', () => {

  const table = new Map()
  table.set([4, 2, 7, 1, 3], [1, 2, 3, 4, 7])

  for (let [originalList, finalList] of table) {
    it(`should turn [${originalList}] into [${finalList}]`, () => {
      expect(sort(originalList)).to.eql(finalList)
    })
  } 
})