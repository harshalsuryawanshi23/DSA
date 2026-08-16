class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int cnt0 = 0;
        int maxc = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] == 0)
                cnt0++;

            while(cnt0 > k){
                if(nums[i] == 0) cnt0--;
                i++;
            }
            maxc = max(maxc,j-i+1);
            
        }
        return maxc;
    }
};