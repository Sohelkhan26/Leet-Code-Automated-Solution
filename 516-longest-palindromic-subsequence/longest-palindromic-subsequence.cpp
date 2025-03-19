class Solution {
public:
    int dp[1001][1001];
    int solve(int left , int right , string &s){
        int ans = 0;
        if(left > right)
            return 0;
        if(left == right)
            return 1;
        if(dp[left][right] != -1)
            return dp[left][right];
        if(s[left] == s[right])
            ans = 2 + solve(left + 1 , right - 1 , s);
        else{
            int takeLeft = solve(left , right - 1 , s);
            int takeRight = solve(left + 1 , right , s);
            ans = max(takeLeft , takeRight);
        }
        return dp[left][right] = ans;

    }
    int longestPalindromeSubseq(string s) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , s.size() - 1 , s);
    }
};