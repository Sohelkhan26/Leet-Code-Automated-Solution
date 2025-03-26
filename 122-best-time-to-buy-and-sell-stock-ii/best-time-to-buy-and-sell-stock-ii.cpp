class Solution {
public:
    int dp[100000][2];
    int solve(int i , vector<int> &price , bool buy){
        if(i >= price.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int buyToday = INT_MIN , sellToday = INT_MIN , holdToday = INT_MIN;
        if(buy)
            buyToday = solve(i + 1 , price , not buy) - price[i];
        else sellToday = solve(i + 1 , price , not buy) + price[i];
        holdToday = solve(i + 1 , price , buy);
        return dp[i][buy] = max({buyToday , sellToday , holdToday});
    }
    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , prices , true);
    }
};