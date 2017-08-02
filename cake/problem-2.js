

function getProductsOfAllIntsExceptAtIndex(array) {
	if (array.length < 2) throw new Error('An array with at least two elements is required')

	const productsOfAllIntsExceptAtIndex = []
	let cumulativeProduct = 1
	for (let i = 0; i < array.length; i++) {
		productsOfAllIntsExceptAtIndex[i] = cumulativeProduct
		cumulativeProduct *= array[i]
	}

	cumulativeProduct = 1
	for (let i = array.length - 1; i >= 0; i--) {
		productsOfAllIntsExceptAtIndex[i] *= cumulativeProduct
		cumulativeProduct *= array[i]
	}


	return productsOfAllIntsExceptAtIndex
}

module.exports = getProductsOfAllIntsExceptAtIndex