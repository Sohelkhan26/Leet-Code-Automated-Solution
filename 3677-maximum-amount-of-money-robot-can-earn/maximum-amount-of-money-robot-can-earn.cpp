class Solution {
public: 
    int n , m;
    int dp[501][501][3];
    int solve(int i , int j , vector<vector<int>> &coins , int k){
        if(i == n - 1 and j == m - 1){
            if(coins[i][j] < 0)
                return k > 0 ? 0 : coins[i][j];
            return coins[i][j];
        }
        if(min(i , j) < 0 or i >= n or j >= m or k < 0)  
            return INT_MIN;
        if(dp[i][j][k] != INT_MIN)
            return dp[i][j][k];
        int take = coins[i][j] + max(solve(i + 1 , j , coins , k) , solve(i , j + 1 , coins , k));
        int dont = INT_MIN;
        if(coins[i][j] < 0 and k > 0)
            dont = max(solve(i + 1 , j , coins , k - 1) , solve(i , j + 1 , coins , k - 1));
        return dp[i][j][k] = max(take , dont);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        for (int i = 0; i < 501; ++i)
            for (int j = 0; j < 501; ++j)
                for (int k = 0; k < 3; ++k)
                    dp[i][j][k] = INT_MIN;
        n = coins.size() , m = coins[0].size();
        return solve(0 , 0 , coins , 2);
    }
};

/*
Start of top-left corner and want to go to bottom-right corner.
Can change atmost 2 cell's value from negative to 0.
So, for each cell we can either include it(+ / -) or if can, make it 0 using one move.
Ultimately it boils down to take/dontTake DP problem with extra 'move' parameter.
Normal dp[i][j][k] != -1 don't work , cause total accumulated coins can be negative and if the answer is stored as -1 in the dp array then the subproblems get called again and again resulting TLE. So, fill dp array that is not a probable answer.
*/