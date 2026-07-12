class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(),sorted.end());

        unordered_map<int,int> map;
        int r = 1;

        for(int i : sorted){
            if(!map.count(i)){
                map[i] = r++;
            }
        }
        for(int &num : arr){
            num = map[num];
        }
        return arr;
    }
};