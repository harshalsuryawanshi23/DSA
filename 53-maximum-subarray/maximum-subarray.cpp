class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int maxsum = INT_MIN;
        bool psv = false;
        
        for(int i : nums){
            if(i >= 0 || psv == true){
                psv = true;
                currsum += i;
                maxsum = max(currsum,maxsum);
                if(currsum < 0) currsum = 0;
            }else{
                maxsum = max(maxsum,i);            
            }
        }
        return maxsum;
    }
};