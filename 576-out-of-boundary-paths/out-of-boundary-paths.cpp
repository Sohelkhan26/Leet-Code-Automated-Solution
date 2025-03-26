class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[51][51][51] , mod = 1e9 + 7 , dir[] = {1 , 0 , -1 , 0 , 1};
        memset(dp , -1 , sizeof(dp));
        function<int(int,int,int)> solve = [&](int i , int j , int moveRem){
            if(min(i , j) < 0 or i >= m or j >= n)
                return 1;
            if(moveRem <= 0)
                return 0;
            if(dp[i][j][moveRem] != -1)
                return dp[i][j][moveRem];
            int ans = 0;
            for(int k = 0 ; k < 4 ; k++)
                ans = (ans + solve(i + dir[k] , j + dir[k + 1] , moveRem - 1)) % mod;
            return dp[i][j][moveRem] = ans;
        };
        return solve(startRow , startColumn , maxMove);
    }
};