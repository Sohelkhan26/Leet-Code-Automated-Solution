class Solution {
public:
    int dp[501][501];
    int solve(int i , int j , vector <int> &a , vector <int> &b){
        if(i == a.size() or j == b.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(a[i] == b[j])
            return dp[i][j] = 1 + solve(i + 1 , j + 1 , a , b);
        int takeI = solve(i , j + 1 , a , b);
        int takeJ = solve(i + 1 , j , a , b);
        return dp[i][j] = max(takeI , takeJ);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , nums1 , nums2);
    }
};

/*
Same as classic DP problem LCS(Longest Common Subsequence), the question maker cleverly deformed it. I couldn't find out the trick.
*/