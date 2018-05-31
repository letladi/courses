const inFixToPostFix = require('./inFixToPostFix')

describe('inFixToPostFix', () => {
    const testData = new Map([
        ['A + B - C', 'A B + C -'],
        ['(A + B) * C', 'A B + C *'],
        ['(A + B) * (C - D)', 'A B + C D - *'],
        ['A + ((B + C) * (E - F) - G) / (H - I)', 'A B C + E F - * G - H I - / +'],
        ['A + B * (C + D) - E / F * G + H', 'A B C D + * + E F / G * - H +']
    ])

    testData.forEach((postfix, infix) => {
        test(`inFixToPostFix(${infix}) = ${postfix}`, () => {
            expect(inFixToPostFix(infix)).toEqual(postfix)
        })
    })
})
