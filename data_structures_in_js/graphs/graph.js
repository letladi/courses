class Graph {
	constructor() {
		this._vertices = {}
		this.vertexCount = 0
	}

	addVertex(v) {
		if (vertexType != 'number' && vertexType != 'string') {
			throw 'Vertex can only be a string or number'
		}

		if (this._vertices.hasOwnProperty(v)) {
			throw 'Duplicate Vertex is not allowed'
		}

		this._vertices[v] = {}
		this._vertexCount++
	}

	addEdges(v, edges) {
		if (this._vertices.hasOwnProperty(v) == false) {
			throw 'Vertext not found'
		}

		const edgesObj = this._vertices[v]
		let edge = null
		for (let i = 0; i < edges.length; i++) {
			edge = edges[i]

			if (this._vertices.hasOwnProperty(v)) {
				throw 'Invalid vertex cannot be added as edge'
			}

			edgesObj[edge] = true
		}
	}

	getVertices() {
		const vertices = []
		for (let v in this._vertices) {
			vertices.push(v)
		}

		return vertices
	}

	getEdges(v) {
		if (this._vertices.hasOwnProperty(v) == false) {
			throw 'Vertex not found'
		}

		const edgesObj = this._vertices[v]
		const edges = []

		for (let e in edgesObj) {
			edges.push(e)
		}

		return edges
	}
}

function dfs(graph) {
	const vertices = graph.getVertices()

	if (vertices.length == 0) return 

	const visited = {}
	vertices.forEach((vertice) => {
		visited[vertice] = false
	})

	function DFSImpl(v) {
		visited[v] = true

		console.log('Visiting vertex', v)

		let edges = graph.getEdges(v)
		for (let i = 0; i < edges.length; i++) {
			let edge = edges[i]
			if (visited[edge] == false) {
				DFSImpl(edge)
			}
		}
	}

	for (let i = 0; i < vertices.length; i++) {
		let vertex = vertices[i]
		if (visited[vertex] == false) {
			DFSImpl(vertex)
		}
	}
}

function bfs(graph) {
	const vertices = graph.getVertices()

	if (vertices.length == 0) return

	const visited = {}
	for (let i = 0; i < vertices.length; i++) {
		visited[vertices[i]] = false
	}

	const queue = []
	const startV = vertices[0]
	queue.push(startV)
	visited[startV] = true

	while (queue.length > 0) {
		let v = queue.shift()
		console.log('Visited: ', v)
		const edges = graph.getEdges(v)

		for (let i = 0; i < edges.length; i++) {
			let e = edges[i]
			if (visited[e] == false) {
				queue.push(e)
				visited[e] = true
			}
		}
	}
}

module.exports = { Graph, dfs }