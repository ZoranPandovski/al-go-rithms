
class Node(var value:Int,var edges:Set[Node]=Set[Node]()){

	override def toString: String = value.toString
}


	/**
		* Depth first search implemented recursively
		* based on algorithm given at http://manuel.kiessling.net/2016/02/15/scala-traversing-a-graph-in-a-functional-way/
		* */
	def depthFirst(current:Node, acc: Set[Node]): Set[Node] = {
		current.edges.foldLeft(acc) {
			(results, next) =>
				if (results.contains(next)) results
				else depthFirst(next, results + current)
		} + current
	}

	def test(): Unit ={
		val node1 = new Node(0,Set(new Node(1,Set[Node]()),new Node(4,Set[Node]())))

		val output = depthFirst(node1,Set[Node]())
		print(output)
	}


