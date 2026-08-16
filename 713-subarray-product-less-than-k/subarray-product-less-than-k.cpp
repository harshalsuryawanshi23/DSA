class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

         int st = 0;
         int ans = 0;
         int product = 1;
         int n = nums.size();

         for(int ed = 0; ed < n; ed++){
            product *= nums[ed];

            while(product >= k){
                product /= nums[st];
                st++;
            }

            ans += ed-st+1;
         }
         return ans;
    }
};