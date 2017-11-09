const { expect } = require('chai')
const sinon = require('sinon')
const task = require('../../../models/task')
const express = require('express')

describe('tasks routes tests', () => {
	let sandbox
	let router
	let sampleTask

	beforeEach(() => {
		sandbox = sinon.sandbox.create()

		sandbox.stub(express, 'Router').returns({
			get: sandbox.spy(),
			post: sandbox.spy(),
			delete: sandbox.spy(),
		})

		sampleTask = { name: 't1', month: 12, day: 1, year: 2016 }

		router = require('../../../routes/tasks')
	})

	afterEach(() => {
		sandbox.restore()
	})

	it(`should register URI / for get`, () => {
		expect(router.get.calledWith('/', sandbox.match.any)).to.be.true
	})

	const stubResSend = (expected, done) => {
		return {
			send(data) {
				expect(data).to.be.eql(expected)
				done()
			}
		}
	}

	it(`get / handler should call model's all & return result`, (done) => {
		const sampleTasks = [sampleTask]

		sandbox.stub(task, 'all', (cb) => {
			cb(null, sampleTasks)
		})

		const req = {}
		const res = stubResSend(sampleTasks, done)

		const registeredCb = router.get.firstCall.args[1]
		registeredCb(req, res)
	})

	it('should register URI /:id for get', () => {
		expect(router.get.calledWith('/:id'), sandbox.match.any).to.be.true
	})

	it(`get /:validid handler should call model's get & return a task`, (done) => {
		const req = { params: { id: 1}}
		
		sandbox.stub(task, 'get', (id, cb) => {
			expect(id).to.be.eql(req.params.id)
			cb(null, sampleTask)
		})

		const res = stubResSend(sampleTask, done)

		const registeredCb = router.get.secondCall.args[1]
		registeredCb(req, res)
	})

})