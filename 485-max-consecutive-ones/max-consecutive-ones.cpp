class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int i = 0;
        int n = nums.size();
        int j;
        for(j = 0; j < n; j++){
            if(nums[j] == 0){
                m = max(m,j-i);
                i = j+1;
            }
        }
        m = max(m,j-i);
        return m;
    }
};