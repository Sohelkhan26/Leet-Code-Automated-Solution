class Solution {
public:
    vector<vector<vector<long long>>> dp; // maybe 3D needed

    int n , m;
    long long solve(int i , int j , bool parity , vector<vector<int>> &cost){ 
        if(i == n or j == m)
            return 1e14;
        if(i == n - 1 and j == m - 1)
            return 0;
        if(dp[i][j][parity] != -1)
            return dp[i][j][parity];
        long long extra = (parity == 0 ? cost[i][j] : 0);
        long long right = 1ll * (j + 2) * (i + 1) + solve(i , j + 1 , 0 , cost);
        long long down = 1ll * (i + 2) * (j + 1) + solve(i + 1 , j , 0 , cost);
        return dp[i][j][parity] = min(down , right) + extra;
    }
    long long minCost(int row , int col , vector<vector<int>>& waitCost) {
        n = row , m = col;
        dp = vector<vector<vector<long long>>> (n , vector<vector<long long>> (m , vector<long long> (2 , -1)));
        return 1 + solve(0 , 0 , 1 , waitCost);
    }
};