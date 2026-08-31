class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;
        int presum = 0;
        int cnt = 0;
        for(int n : nums){
            presum += n;
            cnt += mp[presum - k];
            mp[presum]++;
        }
        return cnt;
    }
};