class Solution {
public:
    typedef long long ll;
    ll dp[100001];
    ll solve(int i , vector <vector<int>> &nums){
        if(i >= nums.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        ll take = nums[i][0] + solve(i + nums[i][1] + 1 , nums);
        ll dont = solve(i + 1 , nums);
        return dp[i] = max(take , dont);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , questions);
    }
};