class QueueTwoStacks {
	contructor() {
		this.inStack = []
		this.outStack = []
	}

	enqueue(item) {
		this.inStack.push(item)
	}

	dequeue() {
		if (this.outStack.length == 0) {

			while (this.inStack.length > 0) {

				let newestInStackItem = this.inStack.pop()
				this.outStack.push(newestInStackItem)
				
			}

			if (this.outStack.length == 0) {
				return void(0)
			}

		}

		return this.outStack.pop()
	}
}