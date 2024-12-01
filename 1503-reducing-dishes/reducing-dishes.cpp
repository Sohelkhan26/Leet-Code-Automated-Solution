class Solution {
public:
    int dp[501][501];
    int solve(int index , int time , vector <int> &nums){
        if(index == nums.size())
            return 0;
        if(dp[index][time] != -1)
            return dp[index][time];
        int take = nums[index] * time + solve(index + 1 , time + 1 , nums);
        int dont = solve(index + 1 , time , nums);
        return dp[index][time] = max(take , dont);
    }
    int maxSatisfaction(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        sort(nums.begin() , nums.end());
        return solve(0 , 1 , nums);
    }
};