class Solution {
public:
    vector<vector<int>> col;
    int n , m;
    int dp[1001][11];
    int solve(int i , int prev , vector<vector<int>> &grid){
        if(i == m)
            return 0;
        if(dp[i][prev] != -1)
            return dp[i][prev];
        int ans = INT_MAX;
        for(int j = 0 ; j < 10 ; j++){ // for each column we leave j unchanged
            if(j == prev) // can't have same adjacent values
                continue;
            int cost = n - col[i][j] + solve(i + 1 , j , grid);
            ans = min(ans , cost);
        }
        return dp[i][prev] = ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        memset(dp , -1 , sizeof(dp));
        n = grid.size() , m = grid[0].size();
        col.resize(m , vector<int> (10));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++)
                col[j][grid[i][j]]++; // count frequency of digits in each column
        }  
        return solve(0 , 10 , grid);
    }
};

/*
All columns must be of same value.
Adjacent columns must have different values.
Simple counting?
n = 10
col1 = max(a) = 4 , b = 2 , c = 2 , d = 2
col2 = max(a) = 8 , b = 1 , c = 1
col3 = max(a) = 9 , b = 1
change col1 to b?
*/