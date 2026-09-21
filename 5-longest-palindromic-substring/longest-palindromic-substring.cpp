class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int sum = 0;
        int st = 0, ed = 0;
        int n = s.length();

        for(int curr = 0; curr < n; curr++){
            int l = curr - 1;
            int r = curr + 1;
           while(l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }

            if(r-l-1 > sum){
                sum = r-l-1;
                st = l+1;
                ed = r-1;
            } 

            l = curr;
            r = curr + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            if(r - l - 1 > sum) {
                sum = r - l - 1;
                st = l + 1;
                ed = r - 1;
            }
        }
        return s.substr(st, ed - st + 1);
    }
};