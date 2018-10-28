import java.util.ArrayList
import java.util.Collections
import java.util.HashMap
import java.util.HashSet
import java.util.LinkedList
import kotlin.test.assertNotNull
import kotlin.test.assertTrue

class DijkstraAlgorithm(graph: Graph) {

    private val nodes: List<Vertex>
    private val edges: List<Edge>
    private var settledNodes: MutableSet<Vertex>? = null
    private var unSettledNodes: MutableSet<Vertex>? = null
    private var predecessors: MutableMap<Vertex, Vertex>? = null
    private var distance: MutableMap<Vertex, Int>? = null

    init {
        // create a copy of the array so that we can operate on this array
        this.nodes = ArrayList<Vertex>(graph.vertexes)
        this.edges = ArrayList<Edge>(graph.edges)
    }

    fun execute(source: Vertex) {
        settledNodes = HashSet()
        unSettledNodes = HashSet()
        distance = HashMap()
        predecessors = HashMap()
        distance!![source] = 0
        unSettledNodes!!.add(source)
        while (unSettledNodes!!.size > 0) {
            val node = getMinimum(unSettledNodes!!)
            settledNodes!!.add(node!!)
            unSettledNodes!!.remove(node)
            findMinimalDistances(node)
        }
    }

    private fun findMinimalDistances(node: Vertex?) {
        val adjacentNodes = getNeighbors(node)
        for (target in adjacentNodes) {
            if (getShortestDistance(target) > getShortestDistance(node) + getDistance(node, target)) {
                distance!![target] = getShortestDistance(node) + getDistance(node, target)
                predecessors!![target] = node!!
                unSettledNodes!!.add(target)
            }
        }

    }

    private fun getDistance(node: Vertex?, target: Vertex): Int {
        for (edge in edges) {
            if (edge.source == node && edge.destination == target) {
                return edge.weight
            }
        }
        throw RuntimeException("Should not happen")
    }

    private fun getNeighbors(node: Vertex?): List<Vertex> {
        val neighbors = ArrayList<Vertex>()
        for (edge in edges) {
            if (edge.source == node && !isSettled(edge.destination)) {
                neighbors.add(edge.destination)
            }
        }
        return neighbors
    }

    private fun getMinimum(vertexes: Set<Vertex>): Vertex? {
        var minimum: Vertex? = null
        for (vertex in vertexes) {
            if (minimum == null) {
                minimum = vertex
            } else {
                if (getShortestDistance(vertex) < getShortestDistance(minimum)) {
                    minimum = vertex
                }
            }
        }
        return minimum
    }

    private fun isSettled(vertex: Vertex): Boolean {
        return settledNodes!!.contains(vertex)
    }

    private fun getShortestDistance(destination: Vertex?): Int {
        val d = distance!![destination]
        return d ?: Integer.MAX_VALUE
    }

    /*
     * This method returns the path from the source to the selected target and
     * NULL if no path exists
     */
    fun getPath(target: Vertex): LinkedList<Vertex>? {
        val path = LinkedList<Vertex>()
        var step = target
        // check if a path exists
        if (predecessors!![step] == null) {
            return null
        }
        path.add(step)
        while (predecessors!![step] != null) {
            step = predecessors!![step]!!
            path.add(step)
        }
        // Put it into the correct order
        Collections.reverse(path)
        return path
    }

}

class Edge(val id: String, val source: Vertex, val destination: Vertex, val weight: Int) {
    override fun toString(): String {
        return source.toString() + " " + destination.toString()
    }
}

class Graph(val vertexes: List<Vertex>, val edges: List<Edge>)

class Vertex(val id: String?, val name: String) {

    override fun hashCode(): Int {
        val prime = 31
        var result = 1
        result = prime * result + (id?.hashCode() ?: 0)
        return result
    }

    override fun equals(obj: Any?): Boolean {
        if (this === obj)
            return true
        if (obj == null)
            return false
        if (javaClass != obj.javaClass)
            return false
        val other = obj as Vertex?
        if (id == null) {
            if (other!!.id != null)
                return false
        } else if (id != other!!.id)
            return false
        return true
    }

    override fun toString(): String {
        return name
    }
}

class TestDijkstraAlgorithm {
    companion object {
        private lateinit var nodes: MutableList<Vertex>
        private lateinit var edges: MutableList<Edge>
        @JvmStatic
        fun main(args : Array<String>) {
            nodes = ArrayList()
            edges = ArrayList()
            for (i in 0..10) {
                val location = Vertex("Node_$i", "Node_$i")
                nodes.add(location)
            }

            addLane("Edge_0", 0, 1, 85)
            addLane("Edge_1", 0, 2, 217)
            addLane("Edge_2", 0, 4, 173)
            addLane("Edge_3", 2, 6, 186)
            addLane("Edge_4", 2, 7, 103)
            addLane("Edge_5", 3, 7, 183)
            addLane("Edge_6", 5, 8, 250)
            addLane("Edge_7", 8, 9, 84)
            addLane("Edge_8", 7, 9, 167)
            addLane("Edge_9", 4, 9, 502)
            addLane("Edge_10", 9, 10, 40)
            addLane("Edge_11", 1, 10, 600)

            // Lets check from location Loc_1 to Loc_10
            val graph = Graph(nodes, edges)
            val dijkstra = DijkstraAlgorithm(graph)
            dijkstra.execute(nodes[0])
            val path = dijkstra.getPath(nodes[10])

            assertNotNull(path)
            assertTrue(path!!.size > 0)

            for (vertex in path) {
                System.out.println(vertex)
            }
        }

        private fun addLane(laneId: String, sourceLocNo: Int, destLocNo: Int,
                            duration: Int) {
            val lane = Edge(laneId, nodes[sourceLocNo], nodes[destLocNo], duration)
            edges.add(lane)
        }
    }
}