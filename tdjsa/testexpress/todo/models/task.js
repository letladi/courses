const db = require('../db')
const { validateTask } = require('../public/javascripts/common/validate-task')
const { ObjectId } = require('mongodb')

const collectionName = 'tasks'

module.exports = {

	validate: validateTask,

	all(cb) {
		db.get().collection(collectionName).find().toArray(cb)
	},

	get(taskId, cb) {
		db.get().collection(collectionName)
			.find({ _id: new ObjectId(taskId) })
			.limit(1)
			.next(cb)
	},

	add(newTask, cb) {

		const found = (err, task) => {
			if (task) {
				cb(new Error('duplicate task'))
			} else {
				db.get().collection(collectionName).insertOne(newTask)		
				cb(err, task)
			}
		}

		if (this.validate(newTask)) {
			db.get().collection(collectionName).find(newTask).limit(1).next(found)
		} else {
			cb(new Error('unable to add task'))
		}
	},

	delete(taskId, cb) {
		const handleDelete = (err, result) => {
			if (result.deletedCount == 1) {
				cb(null)
			} else {
				cb(new Error(`unable to delete task with id: ${taskId}`))
			}
		}

		db.get().collection(collectionName)
			.deleteOne({ _id: new ObjectId(taskId) }, handleDelete)
	}
}