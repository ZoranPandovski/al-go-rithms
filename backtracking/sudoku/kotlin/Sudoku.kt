/**
 * @author https://github.com/jeffament/
 */

private const val EMPTY_CELL = 0

fun main(args: Array<String>) {
    val board = arrayOf(
            intArrayOf(8, 0, 0,     0, 0, 0,    0, 0, 0),
            intArrayOf(0, 0, 3,     6, 0, 0,    0, 0, 0),
            intArrayOf(0, 7, 0,     0, 9, 0,    2, 0, 0),

            intArrayOf(0, 5, 0,     0, 0, 7,    0, 0, 0),
            intArrayOf(0, 0, 0,     0, 4, 5,    7, 0, 0),
            intArrayOf(0, 0, 0,     1, 0, 0,    0, 3, 0),

            intArrayOf(0, 0, 1,     0, 0, 0,    0, 6, 8),
            intArrayOf(0, 0, 8,     5, 0, 0,    0, 1, 0),
            intArrayOf(0, 9, 0,     0, 0, 0,    4, 0, 0)
    )

    if (solvePuzzle(board)) {
        println("Puzzle solved successfully!\n")
        printPuzzle(board)
    } else print("No solution is available for this puzzle!")
}

// solves the puzzle by recursively backtracking until a solution is found or all possibilities have been exhausted
private fun solvePuzzle(array: Array<IntArray>): Boolean {
    val locationOfEmptyCell = arrayOf(0, 0)
    if (!findNextEmptyCell(array, locationOfEmptyCell)) return true

    val row = locationOfEmptyCell[0]
    val column = locationOfEmptyCell[1]

    for (numChoice in 1..9) {
        if (isValidMove(array, row, column, numChoice)) {
            array[row][column] = numChoice
            if (solvePuzzle(array)) return true
            array[row][column] = EMPTY_CELL
        }
    }
    return false
}

// returns true if there are still empty cells and updates the locationOfEmptyCell array, returns false when puzzle
// is solved
private fun findNextEmptyCell(sudokuArray: Array<IntArray>, locationOfEmptyCell: Array<Int>): Boolean {
    for (row in 0..8) {
        for (column in 0..8) {
            if (sudokuArray[row][column] == EMPTY_CELL) {
                locationOfEmptyCell[0] = row
                locationOfEmptyCell[1] = column
                return true
            }
        }
    }
    return false
}

// returns true if the chosen number does not occur in the row, column and quadrant, false otherwise
private fun isValidMove(array: Array<IntArray>, row: Int, column: Int, numChoice: Int): Boolean {
    return checkRow(array, row, numChoice) &&
            checkColumn(array, column, numChoice) &&
            checkBox(array, row, column, numChoice)
}

// returns false if the chosen number is already in the box, true otherwise
private fun checkBox(array: Array<IntArray>, row: Int, column: Int, numChoice: Int): Boolean {
    val startingRowIndex = (row / 3) * 3
    val startingColumnIndex = (column / 3) * 3

    for (row in startingRowIndex..startingRowIndex + 2) {
        for (column in startingColumnIndex..startingColumnIndex + 2) {
            if (array[row][column] == numChoice) return false
        }
    }
    return true
}

// returns false if the chosen number is already in the row, true otherwise
private fun checkRow(array: Array<IntArray>, row: Int, numChoice: Int): Boolean {
    for (column in 0..8) {
        if (array[row][column] == numChoice) return false
    }
    return true
}

// returns false if the chosen number is already in the column, true otherwise
private fun checkColumn(array: Array<IntArray>, column: Int, numChoice: Int): Boolean {
    for (row in 0..8) {
        if (array[row][column] == numChoice) return false
    }
    return true
}

// prints the 9x9 grid with sudoku formatting
private fun printPuzzle(array: Array<IntArray>) {
    for (i in 0..8) {
        for (j in 0..8) {
            print("${array[i][j]} ")
        }
        println()
    }
}
