// A Dynamic Programming based C++ program to find minimum number operations to convert str_1 to str_2
#include <iostream>

using namespace std;
 
// Function to find minimum of three numbers
int min_of_three(int x, int y, int z)
{
    return min(min(x, y), z);
}
 
int levenshtein_distance(string str_1, string str_2, int m, int n)
{
    // Create a table to store results of subproblems
    int lev_dist[m+1][n+1];
 
    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, either insert all characters of second string into first string or remove them from the second string
            if (i==0)
                lev_dist[i][j] = j;                              // Min. operations = j
 
            // If second string is empty, either insert all characters of first string into second string or remove them from the first string
            else if (j==0)
                lev_dist[i][j] = i;                              // Min. operations = i
 
            // If last characters are same, ignore last character and recur for remaining string
            else if (str_1[i-1] == str_2[j-1])
                lev_dist[i][j] = lev_dist[i-1][j-1];             // No. of operstions same as that for strings excluding the last characters
 
            // If last character are different, consider all possibilities and find minimum of the cases
            else
                lev_dist[i][j] = 1 + min_of_three(lev_dist[i][j-1],       // Insert character
                                         lev_dist[i-1][j],                // Remove character
                                         lev_dist[i-1][j-1]);             // Replace character
        }
    }
    return lev_dist[m][n];
}
 
// Main function
int main(int argc, char const *argv[])
{
    // Example use of the function
    string str_1 = "levenshtein";
    string str_2 = "meilenstein";
 
    cout << "The Levenshtein Distance is " << levenshtein_distance(str_1, str_2, str_1.length(), str_2.length()) << endl;
 
    return 0;
}