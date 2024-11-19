class Solution {
public:
    int K;
    unordered_map<string,int> dp;
    int solve(int position , int jump , bool canGoBack){
        if(position > K + 1)
            return 0;  
        string key = to_string(position) + "_" + to_string(jump) + "_" + to_string(canGoBack);
        if(dp.find(key) != dp.end())
            return dp[key];
        int ways = 0;
        if(position == K)
            ways++;
        if(canGoBack)
            ways += solve(position - 1 , jump , false);
        ways += solve(position + pow(2 , jump) , jump + 1 , true);
        return dp[key] = ways;
    }
    int waysToReachStair(int k) {
        dp.clear();
        K = k;
        return solve(1 , 0 , true);
    }
};