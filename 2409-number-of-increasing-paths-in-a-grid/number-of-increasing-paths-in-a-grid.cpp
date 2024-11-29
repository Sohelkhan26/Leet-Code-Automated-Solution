class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() , mod = 1e9 + 7;
        vector<vector<int>> dp(n , vector<int> (m , -1));
        function<int(int , int)> solve = [&](int i , int j) -> int{
            if(dp[i][j] != -1)
                return dp[i][j];
            dp[i][j] = 1;
            for(auto &[di , dj] : vector<pair<int,int>> {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}}){
                int newi = i + di , newj = j + dj;
                if(min(newi , newj) >= 0 and newi < n and newj < m){
                    if(grid[newi][newj] > grid[i][j])
                        dp[i][j] += solve(newi , newj) % mod;
                }
            }
            return dp[i][j] % mod;
        };
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = (ans + solve(i , j) % mod) % mod;
            }
        }
        return ans;
    }
};