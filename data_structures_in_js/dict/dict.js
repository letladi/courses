class Dict {
	constructor() {
		this._data = {}
		this._count = 0
	}

	add(key, val) {
		if ((typeof key != 'string') && (typeof key != 'number')) {
			throw 'A key can only be a number or string'
		}
		if (val == void(0)) {
			throw 'A value is required'
		} 
		if ((key in this._data) == false) {
			this._count++
		}
		this._data[key] = val 
	}

	get(key) {
		return this._data[key]
	}

	remove(key) {
		if (key in this._data) {
			delete this._data[key]
			this._count--
		}
	}

	size() {
		return this._count
	}
}

module.exports = Dict