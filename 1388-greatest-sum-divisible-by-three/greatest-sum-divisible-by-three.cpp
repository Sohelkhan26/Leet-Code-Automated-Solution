class Solution {
public: 
    vector<vector<int>> dp;
    int solve(int i , int rem , vector<int> &nums){
        if(i == nums.size())
            return rem == 0 ? 0 : INT_MIN;
        if(dp[i][rem] != -1)
            return dp[i][rem];
        int take = nums[i] + solve(i + 1 , (rem + nums[i]) % 3 , nums);
        int dont = solve(i + 1 , rem , nums);
        return dp[i][rem] = max(take , dont);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n , vector<int> (3 , -1));
        return solve(0 , 0 , nums);
    }
};