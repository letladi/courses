class HashTable {
	constructor() {
		this._bucketSize = 23
		this._buckets = []
		this._buckets.length = this._bucketSize
	}

	computeHash(key) {
		let total = 0
		for (let i = 0; i < key.length; i++) {
			total += key.charCodeAt(i)
		}
		return total % this._bucketSize
	}

	put(key, value) {
		const keyType = typeof(key)

		if (keyType  !== 'string' && keyType !== 'number') {
			throw 'Only string or number keys are supported'
		}

		const hash = this.computeHash(key)

		if (this._buckets[hash] == void(0)) {
			this._buckets[hash] = {}
		}

		const chain = this._buckets[hash]

		if (chain.hasOwnProperty(key)) {
			throw 'Duplicate key is not allowed'
		}

		chain[key] = value
	}

	get(key) {
		const keyType = typeof(key)

		if (keyType !== 'string' && keyType !== 'number') {
			return void(0)
		}

		const hash = this.computeHash(key)

		if (this._buckets[hash] == void(0)) {
			return void(0)
		}

		const chain = this._buckets[hash]

		if (chain.hasOwnProperty(key)) {
			return chain[key]
		}

		return void(0)
	}
}

module.exports = HashTable