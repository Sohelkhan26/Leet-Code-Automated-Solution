class Solution {
public:
    long long dp[100001][3][3];
    long long solve(int i , int left , int right , vector<vector<int>> &cost){
        long long ans = LLONG_MAX , j = cost.size() - i - 1;
        if(i > j) 
            return 0;
        if(left != -1 and right != -1 and dp[i][left][right] != -1)
            return dp[i][left][right];
        for(int c = 0 ; c <= 2 ; c++){
            for(int d = 0 ; d <= 2 ; d++){
                if(c == left or d == right or c == d)
                    continue;
                ans = min(ans , cost[i][c] + cost[j][d] + solve(i + 1 , c , d , cost));
            }
        }
        return left != -1 and right != -1 ? dp[i][left][right] = ans : ans;
    }
    long long minCost(int n, vector<vector<int>>& cost) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , -1 , -1 , cost);
    }
};