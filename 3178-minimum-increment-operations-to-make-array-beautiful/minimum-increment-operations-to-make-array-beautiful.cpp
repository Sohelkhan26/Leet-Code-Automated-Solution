class Solution {
public:
    int n;
    vector <long long> dp;
    long long solve(int i , int k , vector<int> &nums){
        if(i > n - 3)   
            return 0ll;
        if(dp[i] != -1)
            return dp[i];
        long long first = max(0 , k - nums[i]) + solve(i + 1 , k , nums);
        long long second = max(0 , k - nums[i + 1]) + solve(i + 2 , k , nums);
        long long third = max(0 , k - nums[i + 2]) + solve(i + 3 , k , nums);
        return dp[i] = min(first , min(second , third));
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        n = nums.size();
        dp.resize(n , -1);
        if(n <= 3)
            return max(0 , k - *ranges::max_element(nums));
        return solve(0 , k , nums);
    }
};