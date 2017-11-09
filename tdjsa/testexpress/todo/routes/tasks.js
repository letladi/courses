const express = require('express')
const task = require('../models/task')

const router = express.Router()

router.get('/', (req, res, next) => {
	task.all((err, tasks) => {
		res.send(tasks)
	})
})

router.get('/:id', (req, res, nest) => {})

router.get('/:id', (req, res, next) => {
	task.get(req.params.id, (err, task) => {
		res.send(task)
	})
})

module.exports = router