const { MongoClient } = require('mongodb')

module.exports = {
	connection: null,

	get() {
		return this.connection
	},

	close() {
		if (this.connection) {
			this.connection.close()
			this.connection = null
		}
	},

	connect(dbname, cb) {
		cacheConnection = (err, db) => {
			this.connection = db 
			cb(null)
		}

		MongoClient.connect(dbname, cacheConnection)
	},

	
}