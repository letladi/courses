const reverse = require('./reverseString')

describe('recursive function to return a reversed string', () => {
    test('reverse("letladi") = "idaltel"', () => {
        expect(reverse('letladi')).toEqual('idaltel')
    })
    test('reverse("sebesho") = "ohsebes"', () => {
        expect(reverse('sebesho')).toEqual('ohsebes')
    })
})
