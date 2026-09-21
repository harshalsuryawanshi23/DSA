class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int sum = INT_MIN;
        for(int i : nums){
            currsum = max(i,currsum + i);
            sum = max(sum,currsum);
        }
        return sum;
    }
};