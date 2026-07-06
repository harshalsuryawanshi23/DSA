class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> sr(numRows,"");
        int i = 0;
        bool up = 0;
       for(char ch : s){
        
        sr[i].push_back(ch);

        if(numRows != 1){
            if(i == 0) up = 0;
            if(i == numRows-1) up = 1;

            if(up) i--;
            else i++;    
        }
       } 
       string ans = "";
       for(string str : sr){
        ans += str;
       }
       return ans;
    }
};