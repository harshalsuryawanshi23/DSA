class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat[0].size(); // columns
        int m = mat.size();    // rows

        // Vertical prefix sum
        vector<vector<int>> prec(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            prec[0][j] = mat[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prec[i][j] = prec[i - 1][j] + mat[i][j];
            }
        }

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int total = 0;

                // Valid row range
                int rowStart = max(0, i - k);
                int rowEnd = min(m - 1, i + k);

                // Valid column range
                int colStart = max(0, j - k);
                int colEnd = min(n - 1, j + k);

                // Iterate over columns
                for (int col = colStart; col <= colEnd; col++) {

                    if (rowStart == 0) {
                        total += prec[rowEnd][col];
                    } 
                    else {
                        total += prec[rowEnd][col]
                               - prec[rowStart - 1][col];
                    }
                }

                ans[i][j] = total;
            }
        }

        return ans;
    }
};