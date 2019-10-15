package hacktoberfest

import java.util.Arrays
import java.util.Comparator

/**
 * Job Sequencing implementation in Kotlin
 * Algorithmic Paradigm - Greedy Algorithm
 * Assumes that the activities are already sorted according to their finish time
 * Time Complexity - O(n^2)
 */

internal class Job : Comparator<Job> {

    var id: Char = ' '
    var deadline: Int = 0
    private var profit: Int = 0

    constructor()
    constructor(id: Char, deadline: Int, profit: Int) {
        this.id = id
        this.deadline = deadline
        this.profit = profit
    }

    // Sorts in descending order on the basis of profit for each job
    override fun compare(j1: Job, j2: Job): Int {
        return if (j1.profit > j2.profit) -1 else 1
    }
}

object JobSequencing {

    /**
     * Schedules jobs based on maximum profit
     * @param arr array containing jobs with their deadlines and profits
     */
    private fun scheduleJobs(arr: Array<Job>) {
        // Sort Jobs in descending order on the basis of their profit
        Arrays.sort(arr, Job())
        val n = arr.size

        print("The following is maximum profit sequence of jobs : \n")

        val result = IntArray(n) // To store result (Sequence of jobs)
        val slot = BooleanArray(n)  // To keep track of free time slots

        // Initialize all slots to be free
        for (i in 0 until n)
            slot[i] = false

        // Iterate through all given jobs
        for (i in 0 until n) {
            // Find a free slot for this job
            for (j in kotlin.math.min(n, arr[i].deadline) - 1 downTo 0) {
                // Free slot found
                if (!slot[j]) {
                    result[j] = i  // Add this job to result
                    slot[j] = true // Make this slot occupied
                    break
                }
            }
        }

        // Print the result
        for (i in 0 until n)
            if (slot[i])
                print(arr[result[i]].id + " ")
    }

    @JvmStatic
    fun main(args: Array<String>) {

        val j1 = Job('a', 2, 100)
        val j2 = Job('b', 1, 19)
        val j3 = Job('c', 2, 27)
        val j4 = Job('d', 1, 25)
        val j5 = Job('e', 3, 15)

        val arr = arrayOf(j1, j2, j3, j4, j5)

        scheduleJobs(arr)
    }
}
