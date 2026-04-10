class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int st = 0; 
        int sum = 0;

        for(int ed = 0; ed < n ; ed++){
            sum += nums[ed];
            while(sum >= target){
                ans = min(ans,ed-st+1);
                sum -= nums[st];
                st++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};