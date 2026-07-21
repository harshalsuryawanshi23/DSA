class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        for(int i = 0; i < n; i++){
            for( int j = i; j < n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        int l = 0;
        int r = n-1;
        while(l < r){
            for(int i = 0; i < n; i++){
                int temp = matrix[i][r];
                matrix[i][r] = matrix[i][l];
                matrix[i][l] = temp;
            }
            r--;
            l++;
        }
    }
};