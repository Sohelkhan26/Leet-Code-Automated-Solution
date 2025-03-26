class Solution {
public:
    int dp[10001][2];
    // int solve(int i , vector<int> &price , int buy){    
    //     if(i >= price.size())
    //         return 0;
    //     if(dp.find({i , buy}) != dp.end())
    //         return dp[{i , buy}];
    //     int buyToday = solve(i + 1 , price , price[i]);
    //     int sellToday = INT_MIN;
    //     int holdStock = solve(i + 1 , price , buy);
    //     if(buy != INT_MAX)
    //         sellToday = price[i] - buy + solve(i + 2 , price , INT_MAX);
    //     return dp[{i , buy}] = max({buyToday , sellToday , holdStock});
    // }
    int solve(int i , vector<int> &price , bool buy){
        if(i >= price.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int buyToday = INT_MIN , sellToday = INT_MIN , holdToday = INT_MIN;
        if(buy)
            buyToday = solve(i + 1 , price , not buy) - price[i];
        else sellToday = solve(i + 2 , price , not buy) + price[i];
        holdToday = solve(i + 1 , price , buy);
        return dp[i][buy] = max({buyToday , sellToday , holdToday});
    }
    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , prices , true);
    }
};