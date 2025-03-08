class Solution {
public:
    int dp[201][201][201];
    int solve(int left , int right , int k , string &s){
        if(left > right)
            return 0;
        if(left == right)
            return 1;
        
        if(dp[left][right][k] == -1){
            int skipLeft = solve(left + 1 , right , k , s);
            int skipRight = solve(left , right - 1 , k , s);
            int cost = abs(s[left] - s[right]);
            int replace = min(cost , 26 - cost) , ans = max(skipLeft , skipRight);
            if(k >= replace) // This covers for the case s[left] == s[right], then replace = 0
                ans = max(ans , 2 + solve(left + 1 , right - 1 , k - replace , s));
            dp[left][right][k] = ans;
        }
        return dp[left][right][k];
    }
    int longestPalindromicSubsequence(string s, int k) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , s.size() - 1 , k , s);     
    }
};