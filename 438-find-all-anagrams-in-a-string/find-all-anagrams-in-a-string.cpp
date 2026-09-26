class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int> ans;
        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        for(char c : p)
            freqP[c - 'a']++;

        for(int i = 0; i < n; i++) {
            freqS[s[i] - 'a']++;

            if(i >= m)
                freqS[s[i - m] - 'a']--;

            if(i >= m - 1 && freqS == freqP)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};