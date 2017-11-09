const validateTask = (task) => {
	if (task && task.name && task.month && isNaN(task.month) == false && 
		task.day && isNaN(task.day) == false && 
		task.year && isNaN(task.year) == false) {
		return true
	} else {
		return false
	}
}

module && (module.exports = {
	validateTask
})