class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int st = 0;
        int curr = 0;
        int n = nums.size();
        int ans = 0;

        while (curr < n) {
            int m = nums[curr];
            map[m] += 1;
            while (map[m] > k) {
                map[nums[st]]--;
                st++;
            }
            ans = max(ans, curr - st + 1);
            curr++;
        }
        return ans;
    }
};