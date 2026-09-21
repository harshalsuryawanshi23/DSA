class Solution {
public:
    bool ispl(const string& s,int st, int ed){
        while(st < ed){
            if(s[st++] != s[ed--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int st = 0;
        int ed = s.length()-1;
        while(st < ed){
            if(s[st] != s[ed]){
                return ispl(s,st+1,ed) || ispl(s,st,ed-1);
            }
            st++;
            ed--;
        }
        return true;
    }
};