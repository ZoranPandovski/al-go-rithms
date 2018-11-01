data class Node(val name: String, val links: List<Link> = listOf())

data class Link(val to: Node, val weight: Int)

fun dijkstra(initialNode: Node, finalNode: Node) {
    val previous = mutableMapOf<Node, Node>()
    val distances = mutableMapOf(initialNode to 0)

    while (distances.isNotEmpty()) {
        val current = removeNearest(distances)

        if (current.key == finalNode) {
            finalNode.printPath(previous)
            return
        }

        for (link in current.key.links) {
            if (current.value + link.weight >= link.to.getDistanceFromStart(distances))
                break

            distances[link.to] = current.value + link.weight
            previous[link.to] = current.key
        }
    }
}

private fun removeNearest(distances: MutableMap<Node, Int>): Map.Entry<Node, Int> {
    val value = distances.map { pair -> pair }.sortedBy { pair -> pair.value }.first()
    distances.remove(value.key)
    return value
}

private fun Node.withDistance(weight: Int) = Link(this, weight)

private fun Node.getDistanceFromStart(distances: MutableMap<Node, Int>) =
    distances[this] ?: Int.MAX_VALUE

private fun Node.printPath(previous: Map<Node, Node>, postfix: String = "") {
    previous[this]?.printPath(previous, " -> ")

    print("$name$postfix")
}

fun main(args: Array<String>) {
    val nodeD = Node("D")

    val nodeC = Node("C", listOf(nodeD.withDistance(5)))
    val nodeB = Node("B", listOf(nodeD.withDistance(4)))

    val nodeA = Node("A", listOf(
        nodeD.withDistance( 15),
        nodeC.withDistance( 30),
        nodeB.withDistance( 10)
    ))

    dijkstra(nodeA, nodeD)
