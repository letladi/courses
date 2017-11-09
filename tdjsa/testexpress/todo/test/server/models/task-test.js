const { expect } = require('chai')
const { TEST_DB_NAME } = require('../../../constants')
const db = require('../../../db')
const { ObjectId } = require('mongodb')
const task = require('../../../models/task')
const { validateTask } = require('../../../public/javascripts/common/validate-task')

describe('task model tests', () => {
	let sampleTask = void(0)
	let sampleTasks = void(0)

	before((done) => {
		db.connect(TEST_DB_NAME, done)
	})

	after(() => {
		db.close()
	})

	const id = (value) => new ObjectId(value)

	beforeEach((done) => {
		sampleTask = { name: 'a new task', month: 12, day: 10, year: 2016 }

		sampleTasks = [
			{ _id: id('123412341240'), name: 'task1', month: 10, day: 5, year: 2016 },
			{ _id: id('123412341241'), name: 'task2', month: 11, day: 2, year: 2016 },
			{ _id: id('123412341242'), name: 'task3', month: 12, day: 8, year: 2016 },
		]

		db.get().collection('tasks').insert(sampleTasks, done)
	})

	afterEach((done) => {
		db.get().collection('tasks').drop(done)
	})

	const expectError = (message, done) => {
		return function(err) {
			expect(err.message).to.be.eql(message)
			done()
		}
	}

	describe('#all', () => {
		it('should return all the tasks', (done) => {
			const cb = (err, tasks) => {
				expect(tasks).to.be.eql(sampleTasks)
				done()
			}

			task.all(cb)
		})
	})

	describe('#get', () => {
		it(`should return tasks with given id`, (done) => {
			const cb = (err, task) => {
				expect(task.name).to.be.eql('task2')
				expect(task.month).to.be.eql(11)
				done()
			}

			task.get(sampleTasks[1]._id, cb)
		})

		it('should return null for non-existing task', (done) => {
			const cb = (err, task) => {
				expect(task).to.be.null
				done()
			}

			task.get(2319, cb)
		})
	})

	describe('#add', () => {
		it('should return null for valid task', (done) => {
			const cb = (err) => {
				expect(err).to.be.null
				task.all((err, tasks) => {
					expect(tasks[3].name).to.be.eql(sampleTask.name)
					done()
				})
			}

			task.add(sampleTask, cb)
		})

		it('should return Error if task already exists', (done) => {
			sampleTask = sampleTasks[0]
			delete sampleTask._id

			task.add(sampleTask, expectError('duplicate task', done))
		})

		it('should call validate', (done) => {
			let validateCalled = false

			task.validate = (task) => {
				expect(task).to.be.eql(sampleTask)
				validateCalled = true
				return validateTask(task)
			}

			task.add(sampleTask, done)

			expect(validateCalled).to.be.true

			task.validate = validateTask
		})

		it('should handle validation failure', (done) => {
			const onError = (err) => {
				expect(err.message).to.be.eql('unable to add task')
				done()
			}

			task.validate = (err) => false

			task.add(sampleTask, onError)

			task.validate = validateTask
		})

	})

	describe('#delete', () => {
		it('shouold send null after deleting existing task', (done) => {
			const cb = (err) => {
				expect(err).to.be.null

				task.all((err, tasks) => {
					expect(tasks.length).to.be.eql(2)
					done()
				})
			}

			task.delete(sampleTasks[2]._id, cb)
		})

		it('should return Error if task not found', (done) => {
			const nonExistingId = id('123412341245')
			task.delete(nonExistingId, expectError(`unable to delete task with id: ${nonExistingId}`, done))
		})

		it('should return Error if task id not given', (done) => {
			task.delete(void(0), expectError('unable to delete task with id: undefined', done))
		})

	})

	it('task.validate should refer to validateTask', () => {
		expect(task.validate).to.be.eql(validateTask)
	})

})