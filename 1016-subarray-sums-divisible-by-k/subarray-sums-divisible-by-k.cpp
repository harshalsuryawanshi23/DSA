class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int presum = 0;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            presum += nums[i];
            int rem = ((presum % k) + k) % k;

            if(mp[rem]) cnt += mp[rem];
            mp[rem]++;
        }
        return cnt;
    }
};