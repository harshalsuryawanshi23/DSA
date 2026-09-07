class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr = 1;
        int ncur = 1;
        int maxp = INT_MIN;

        for(int i : nums) {
            if(i < 0)
                swap(curr, ncur);

            curr = max(i, curr * i);
            ncur = min(i, ncur * i);

            maxp = max(maxp,curr);
        }

        return maxp;
    }
};