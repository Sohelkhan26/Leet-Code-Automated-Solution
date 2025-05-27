class Solution {
public:
    int k , dp[101][101][101] , Max = 1e8;
    int solve(int i , int a , int b , vector<int> &nums){
        if(i == nums.size())
            return 0;
        if(dp[i][a][b] != -1)
            return dp[i][a][b];
        int half = ceil(nums[i] / 2.0) , one = Max , two = Max , both1 = Max , both2 = Max , none = Max;
        if(a)
            one = solve(i + 1 , a - 1 , b , nums);
        if(b and nums[i] >= k)
            two = solve(i + 1 , a , b - 1 , nums);
        if(a and b and half >= k)
            both1 = solve(i + 1 , a - 1 , b - 1 , nums);
        if(a and b and nums[i] >= k)
            both2 = solve(i + 1 , a - 1 , b - 1 , nums);
        none = solve(i + 1 , a , b , nums);
        return dp[i][a][b] = min({one + half , two + nums[i] - k , both1 + half - k , both2 + (nums[i] - k + 1) / 2 , none + nums[i]});
    }
    int minArraySum(vector<int>& nums, int K, int op1, int op2) {
        k = K;
        memset(dp , -1 , sizeof(dp));
        return solve(0 , op1 , op2 , nums);
    }
};