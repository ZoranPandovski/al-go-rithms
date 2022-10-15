class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int start = 0;
        int i = start, j = start;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows*cols;
        int count = 0;
        vector<int>result;

        while(count<n)
        {
            while(j<cols && count<n)
            {
                result.push_back(matrix[i][j]);
                cout<<matrix[i][j]<<",";
                j++;
                count++;
            }
            i++;j--;

            while(i<rows && count<n)
            {
                result.push_back(matrix[i][j]);
                cout<<matrix[i][j]<<",";
                i++;
                count++;
            }
            j--;i--;

            while(j>=start && count<n)
            {
                result.push_back(matrix[i][j]);
                cout<<matrix[i][j]<<",";
                j--;
                count++;
            }

            i --;j++;

            while(i>=(start+1) && count<n)
            {
                result.push_back(matrix[i][j]);
                cout<<matrix[i][j]<<",";
                i--;
                count++;
            }
            rows-=1;cols-=1;
            start++; i=j=start;

        }
        return result;

    }
};
