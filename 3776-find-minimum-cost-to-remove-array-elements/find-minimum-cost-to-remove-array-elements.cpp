class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(int i , int prev , vector <int> &nums){ // i indicates start of the array. one previous element , and now i'th and (i + 1)th element act as the start. nums[0] = nums[prev] , nums[1] = nums[i] , nums[2] = nums[i + 1], out of these three take any two and calculate the rest of the subproblem. return the minimum answer.
        if(i == n)
            return nums[prev];
        if(i == n - 1)
            return max(nums[prev] , nums[i]);
        if(dp[i][prev] != -1)
            return dp[i][prev];
        int _110 = max(nums[prev] , nums[i]) + solve(i + 2 , i + 1 , nums);
        int _101 = max(nums[prev] , nums[i + 1]) + solve(i + 2 , i , nums);
        int _011 = max(nums[i] , nums[i + 1]) + solve(i + 2 , prev , nums);
        return dp[i][prev] = min({_110 , _101 , _011}); 
    }
    int minCost(vector<int>& nums) {
        n = nums.size();
        memset(dp , -1 , sizeof(dp));
        return solve(1 , 0 , nums);
    }
};