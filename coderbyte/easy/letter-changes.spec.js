const { expect } = require('chai')
const { each } = require('lodash')
const letterChanges = require('./letter-changes')

describe('letterChanges function', () => {
  const table = {
    'hello world': 'Ifmmp xpsmE',
    'sentence': 'tfOUfOdf',
    'replace!*': 'sfqmbdf!*',
    'coderbyte': 'dpEfsczUf',
    'beautiful^': 'cfbvUjgvm^',
    'oxford': 'pygpsE',
    '123456789ae': '123456789bf',
    'this long cake@&': 'UIjt mpOh dblf@&',
    'a b c dee': 'b c d Eff',
    'a confusing /:sentence:/[ this is not!!!!!!!~': 'b dpOgvtjOh /:tfOUfOdf:/[ UIjt jt OpU!!!!!!!~',
  }

  each(table, (finalValue, initialValue) => {
    it(`should turn "${initialValue}" into "${finalValue}"`, () => {
      expect(letterChanges(initialValue)).to.eql(finalValue)
    })
  })
})