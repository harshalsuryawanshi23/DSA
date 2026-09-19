class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currsum = 0, sum = nums[0];
        int currdiff = 0, diff = nums[0];

        for(int i : nums){
            currsum = max(i,currsum + i);
            sum = max(sum,currsum);

            currdiff = min(i,currdiff + i);
            diff = min(diff,currdiff);

        }
        return max(sum , abs(diff));
    }
};