class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int ans = 0;

        while(j > i){
            int h = min(height[i],height[j]);
            int w = j-i;
            int area = h*w;
            ans = max(ans,area);
            height[i] > height[j] ? j-- : i++;
        }
        return ans;
    }
};