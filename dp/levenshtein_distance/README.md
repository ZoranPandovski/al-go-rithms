### Levenshtein Distance (Edit Distance) Algorithm

The Levenshtein distance between two words is the minimum number of single-character edits 
(i.e. insertions, deletions or substitutions) required to change one word into the other. 
Each of these operations has unit cost.

It is a way of quantifying how dissimilar two strings are to one another by counting the minimum number 
of operations required to transform one string into the other.

For example, the Levenshtein distance between levenshtein and meilenstein is 4.

#### Working of the algorithm

The Levenshtein algorithm (also called Edit-Distance) calculates the least number of edit operations that are necessary to 
modify one string to obtain another string. The most common way of calculating this is by the dynamic programming approach. 
A matrix is initialized measuring in the (m,n)-cell the Levenshtein distance between the m-character prefix of one with the 
n-prefix of the other word. The matrix can be filled from the upper left to the lower right corner. Each jump horizontally 
or vertically corresponds to an insert or a delete, respectively. The cost is normally set to 1 for each of the operations. 
The diagonal jump can cost either one, if the two characters in the row and column do not match or 0, if they do. Each cell 
always minimizes the cost locally. This way the number in the lower right corner is the Levenshtein distance between both words. 

Here is an example that features the comparison of "meilenstein" and "levenshtein":

![](https://github.com/arijitkar98/al-go-rithms/blob/master/dp/levenshtein_distance/levenshtein_meilenstein_matrix.gif)

There are two possible paths through the matrix that actually produce the least cost solution. Namely

![](https://github.com/arijitkar98/al-go-rithms/blob/master/dp/levenshtein_distance/levenshtein_meilenstein_path.gif)

"=" Match; "o" Substitution; "+" Insertion; "-" Deletion