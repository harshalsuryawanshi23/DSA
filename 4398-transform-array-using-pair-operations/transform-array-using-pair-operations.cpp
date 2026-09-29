class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long s1 = 0;
        long long s2 = 0;

        for(int x : source)
            s1 += x;

        for(int x : target)
            s2 += x;

        return s1 == s2;
    }
};