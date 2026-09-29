class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {

        vector<long long> s(source.begin(), source.end());

        int i = -1;
        int j = -1;
        int cur = 0;

        while(cur < s.size()) {

            if(s[cur] != target[cur]) {
                if(i == -1)
                    i = cur;
                else
                    j = cur;
            }

            if(j != -1 && i != -1) {

                s[j] = s[i] - (long long)target[i] + s[j];

                s[i] = target[j];

                i = -1;

                if(s[j] == target[j])
                    j = -1;
            }

            cur++;
        }

        return i == -1 && j == -1;
    }
};