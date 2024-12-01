class Solution {
public:
    unordered_map <string , int> dp;
    int solve(int index , int time , vector <int> &nums){
        if(index == nums.size())
            return 0;
        string key = to_string(index) + "-" + to_string(time);
        if(dp.find(key) != dp.end())
            return dp[key];
        int take = nums[index] * time + solve(index + 1 , time + 1 , nums);
        int dont = solve(index + 1 , time , nums);
        return dp[key] = max(take , dont);
    }
    int maxSatisfaction(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        return solve(0 , 1 , nums);
    }
};