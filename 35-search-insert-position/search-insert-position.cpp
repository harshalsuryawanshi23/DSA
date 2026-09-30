class Solution {
public:
    int binarys(vector<int>& nums, int st, int ed, int target) {

        if(st > ed)
            return st;

        int mid = st + (ed - st) / 2;

        if(target == nums[mid])
            return mid;

        else if(target > nums[mid])
            return binarys(nums, mid + 1, ed, target);

        else
            return binarys(nums, st, mid - 1, target);
    }

    int searchInsert(vector<int>& nums, int target) {
        return binarys(nums, 0, nums.size() - 1, target);
    }
};