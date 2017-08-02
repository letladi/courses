class Set {
	constructor() {
		this._data = {}
		this._size = 0
	}

	add(el) {
		if (this._data.hasOwnProperty(el)) {
			return
		} else {
			this._data[el] = true
		this._size++
		}
	}

	remove(el) {
		if (this._data.hasOwnProperty(el)) {
			delete this._data[el]
			this._size--
		} 
	}

	member(el) {
		return this._data.hasOwnProperty(el)
	}

	union(other) {
		const ret = new Set()

		for (let key in this._data) {
			ret.add(key)
		}

		for (let key2 in other._data) {
			ret.add(key2)
		}

		return ret
	}

	intersect(other) {
		const ret = new Set()

		for (let key in this._data) {
			if(other.member(key)) {
				ret.add(key)
			}
		}

		return ret
	}

	difference(other) {
		const ret = new Set()

		for (let key in this._data) {
			if (this.member(key) && (other.member(key) == false)) {
				ret.add(key)
			}
		}
		return ret
	}

	size() {
		return this._size
	}
}

module.exports = Set