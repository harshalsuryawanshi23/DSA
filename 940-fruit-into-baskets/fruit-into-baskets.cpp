class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n = fruits.size();
        int cnt = 0;
        int ans = 0;
        int st = 0;

        for(int ed = 0; ed < n; ed++){
            mp[fruits[ed]]++;
            if(mp[fruits[ed]] == 1) cnt++;

            while(cnt > 2){
                mp[fruits[st]]--;
                if(mp[fruits[st]] == 0) cnt--;                    
                st++;
            }
            ans = max(ans,ed-st+1);
        }
        return ans;
    }
};