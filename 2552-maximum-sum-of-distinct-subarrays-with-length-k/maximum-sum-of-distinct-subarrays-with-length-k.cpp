class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long sum = 0;
        long long maxsum = INT_MIN;
        int i = 0;
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            while (mp[nums[j]] > 0) {
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            mp[nums[j]]++;
            sum += nums[j];

            if (j - i + 1 > k) {
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            if (j - i + 1 == k) {
                maxsum = max(maxsum, sum);
            }
        }

        return maxsum == INT_MIN ? 0 : maxsum;
    }
};