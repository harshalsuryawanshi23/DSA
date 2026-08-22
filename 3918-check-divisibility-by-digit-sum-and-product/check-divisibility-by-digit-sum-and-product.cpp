class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int temp = n;
        while(temp > 0){
            sum += temp%10;
            pro *= temp%10;
            temp /= 10;
        }
        return n%(sum+pro) == 0 ? true : false;
    }
};