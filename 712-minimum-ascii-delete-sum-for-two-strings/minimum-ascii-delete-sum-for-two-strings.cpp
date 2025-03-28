class Solution {
public:
    int dp[1001][1001];
    int solve(int i , int j , string &a , string &b){
        if(i == a.size() and j == b.size())
            return 0;
        if(i == a.size())
            return accumulate(b.begin() + j , b.end() , 0);
        
        if(j == b.size())
            return accumulate(a.begin() + i , a.end() , 0);
        if(dp[i][j] != -1)
            return dp[i][j];
        if(a[i] == b[j])
            return solve(i + 1 , j + 1 , a , b);
        int dltFirst = (int)a[i] + solve(i + 1 , j , a , b);
        int dltSecond = (int)b[j] + solve(i , j + 1 , a , b);
        return dp[i][j] = min(dltFirst , dltSecond);
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , s1 , s2);
    }
};