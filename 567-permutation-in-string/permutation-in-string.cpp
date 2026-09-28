class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) return false;

        vector<int> freqs1(26,0);
        vector<int> freqs2(26,0);

        for (int i = 0; i < n; i++) {
            freqs1[s1[i] - 'a']++;
            freqs2[s2[i] - 'a']++;
        }

        for(int ed = n; ed < m; ed++){
            if(freqs1 == freqs2) return true;

            freqs2[s2[ed] - 'a']++;
            freqs2[s2[ed-n] - 'a']--;
        }
        return freqs1 == freqs2;
    }
};