class LongestCommonSubsequence {

    /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
    fun lcs(X: CharArray, Y: CharArray, m: Int, n: Int): Int {
        val L = Array(m + 1) { IntArray(n + 1) }

        /* Following steps build L[m+1][n+1] in bottom up fashion. Note
         that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
        for (i in 0..m) {
            for (j in 0..n) {
                if (i == 0 || j == 0)
                    L[i][j] = 0
                else if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1])
            }
        }
        return L[m][n]
    }

    /* Utility function to get max of 2 integers */
    fun max(a: Int, b: Int): Int {
        return if (a > b) a else b
    }

    companion object {

        @JvmStatic
        fun main(args: Array<String>) {
            val lcs = LongestCommonSubsequence()
            val s1 = "asdpoij"
            val s2 = "asdpfwefg"

            val X = s1.toCharArray()
            val Y = s2.toCharArray()
            val m = X.size
            val n = Y.size

            val result = lcs.lcs(X, Y, m, n)
            println(result)
        }
    }
}