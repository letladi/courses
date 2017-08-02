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

		if (keyType !== 'string' && keyType !== 'number') {
			throw 'Only string or number keys are supported'
		}

		const hash = this.computeHash(key)

		if (this._buckets[hash] == void(0)) {
			this._buckets[hash] = {}
			this._buckets[hash][key] = value
			return
		} else if (this._buckets[hash].hasOwnProperty(key)) {
			throw 'Duplicate key is not allowed'
		}

		const bucketId = hash + 1

		do {
			if (bucketId >= this._bucketSize) {
				bucketId = 0
			}

			if (this._buckets[bucketId] == void(0)) {
				this._buckets[bucketId] = {}
				this._buckets[bucketId][key] = value
				return
			}

			bucketId++

		} while (bucketId != hash)

		throw 'HashTable is full. Rehashing needed.'
	}

	get(key) {
		const keyType = typeof(key)

		if (keyType !== 'string' && keyType !== 'number') {
			return void(0)
		}

		const hash = this.computeHash(key)

		if (this._buckets[hash] == void(0)) {
			return void(0)
		} else if (this._buckets[hash].hasOwnProperty(key)) {
			return this._buckets[hash][key]
		}

		const bucketId = hash + 1

		do {

			if (bucketId >= this._bucketSize) {
				bucketId = 0
			}

			if (this._buckets[bucketId] == void(0)) {
				return void(0)
			} else if (this._buckets[bucketId].hasOwnProperty(key)) {
				return this._buckets[bucketId][key]
			}

			bucketId++

		} while (bucketId != hash)

		return void(0)
	}
}

module.exports = HashTable