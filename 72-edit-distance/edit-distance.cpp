class Solution {
public:
    int dp[501][501];
    int solve(int i , int j , string &a , string &b){
        int n = a.size() , m = b.size();
        if(i == n)
            return m - j;
        if(j == m)
            return n - i;
        if(dp[i][j] != -1)
            return dp[i][j];
        int doNothing = (a[i] == b[j]) ? solve(i + 1 , j + 1 , a , b) : INT_MAX;
        int dlt = 1 + solve(i + 1 , j , a , b); // delete from a
        int replace = 1 + solve(i + 1 , j + 1 , a , b); // be greedy and replace with b[j]
        int insert = 1 + solve(i , j + 1 , a , b); // better to insert b[j] rather than some random value
        return dp[i][j] = min({dlt , replace , insert , doNothing});
    }
    int minDistance(string word1, string word2) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , word1 , word2);
    }
};

/*
Very important piece of info:
Operations can be performed only on word1.
*/