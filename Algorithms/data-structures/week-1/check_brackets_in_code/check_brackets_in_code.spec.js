const { expect } = require('chai')
const { bracketsMatch } = require('./check_brackets')

describe('check brackets function', () => {
	const matching = ['[]', '()', '{}', '{}[]{}', '{[]}()', 'foo(bar)']
	const nonMatching = [['{', 1], ['{[}', 3], ['foo(bar[i);', 10]]
	
	matching.forEach((brackets, i) => {
		it(`should return true for '${brackets}'`, () => {
			expect(bracketsMatch(brackets)).to.eql(true)
		})
	})

	nonMatching.forEach(([brackets, unMatchedIndex]) => {
		it(`should return ${unMatchedIndex} for '${brackets}'`, () => {
			expect(bracketsMatch(brackets)).to.eql(unMatchedIndex)
		})
	})

})
