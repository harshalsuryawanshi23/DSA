class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int n = s.length();
        int cnt= n;

        for(int curr = 0; curr < n; curr++){
            int l = curr - 1;
            int r = curr + 1;
           while(l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                cnt++;
            }

            l = curr;
            r = curr + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
                cnt++;
            }
        }
        return cnt;

    }
};