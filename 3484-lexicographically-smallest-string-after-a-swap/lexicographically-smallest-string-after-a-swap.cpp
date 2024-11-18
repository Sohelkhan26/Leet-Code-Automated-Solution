class Solution {
public:
    string getSmallestString(string s) {
        string ans = s;
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] % 2 == s[i - 1] % 2){
                swap(s[i] , s[i - 1]);
                ans = min(ans , s);
                swap(s[i] , s[i - 1]);
            }
        }
        return ans;
    }
};