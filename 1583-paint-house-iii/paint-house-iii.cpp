class Solution {
public:
    int target;
    int dp[101][101][24];
    int solve(int i , int hood , int prev , vector<vector<int>> &cost , vector<int> &houses){
        int n = cost.size() , m = cost[0].size();
        if(i == n)
            return hood == target ? 0 : INT_MAX;
        if(hood > target)
            return INT_MAX;
        if(dp[i][hood][prev] != -1)
            return dp[i][hood][prev];
        long long take = INT_MAX , skip = INT_MAX;
        if(houses[i] == 0){ // i'th house unpainted
            for(int j = 0 ; j < m ; j++){
                if(j + 1 == prev){ // i'th house included in previous hood
                    take = min(take , 0LL + cost[i][j] + solve(i + 1 , hood , prev , cost , houses));
                }else{ // i'th house starts new hood
                    skip = min(skip , 0LL + cost[i][j] + solve(i + 1 , hood + 1 , j + 1 , cost , houses));
                }
            }
        }else{ // i'th house painted
            if(prev == houses[i]) // if this matches previous hood's color, it can be included in that hood
                take = min(take , 0LL + solve(i + 1 , hood , prev , cost , houses));
            else skip = min(skip , 0LL + solve(i + 1 , hood + 1 , houses[i] , cost , houses)); // this house starts a new hood but not cost as it was already painted , missed a else here and WA
        }
        return dp[i][hood][prev] = min(skip , take);
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int t) {
        target = t;
        memset(dp , -1 , sizeof(dp));

        int ans = solve(0 , 0 , 22 , cost , houses);

        return ans == INT_MAX ? -1 : ans;
    }
};