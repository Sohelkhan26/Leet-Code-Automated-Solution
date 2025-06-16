class Solution {
public:
    int n;
    bool valid(int n){
        if(n == 1)
            return true;
        for(int i = 5 ; i <= n ; i *= 5)
            if(i == n)
                return true;
        return false;
    }
    int solve(int start , string &s){
        if(start == n)
            return 0; // can't split into any more substr
        int ans = 1e9;
        if(s[start] == '0') // leading zero can't split
            return ans;
        for(int len = 1 ; start + len <= n ; len++){
            string temp = s.substr(start , len);
            if(valid(stoi(temp , nullptr , 2)))
                ans = min(ans , 1 + solve(start + len , s));
        }
        return ans;
    }
    int minimumBeautifulSubstrings(string s) {
        n = s.size();
        int ans = solve(0 , s);
        return ans == 1e9 ? -1 : ans;
    }
};