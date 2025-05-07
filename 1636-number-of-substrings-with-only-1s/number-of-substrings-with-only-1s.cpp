class Solution {
public:
    int numSub(string s) {
        int mod = 1e9 + 7 , ans = 0 , one = 0;
        for(char &c : s){
            if(c == '1')one++;
            else one = 0;
            ans = (ans + one) % mod;
        }      
        return ans;
    }
};