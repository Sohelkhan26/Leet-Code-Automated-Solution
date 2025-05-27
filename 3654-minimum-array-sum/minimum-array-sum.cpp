class Solution {
public:
    int k , dp[101][101][101] , Max = 1e8;
    int solve(int i , int a , int b , vector<int> &nums){
        if(i == nums.size())
            return 0;
        if(dp[i][a][b] != -1)
            return dp[i][a][b];
        int half = (nums[i] + 1) / 2.0 , one = Max , two = Max , both1 = Max , both2 = Max , none = Max;
        if(a)
            one = solve(i + 1 , a - 1 , b , nums);
        if(b and nums[i] >= k)
            two = solve(i + 1 , a , b - 1 , nums);
        if(a and b and half >= k) // op1 then op2
            both1 = solve(i + 1 , a - 1 , b - 1 , nums);
        if(a and b and nums[i] >= k) // op2 then op1
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

/*
Pretty awesome and annoying too. Constraints are small so easily Brute Force in other words DP.
For every number we can either do:
1. operation 1
2. operation 2
3. Both operation
4. Skip it.
There is a slight edge case for both operation. 2nd operation can be only applied if nums[i] >= k
After 1st operation half = (nums[i] + 1) / 2 may be < k , then we can't do 2nd operation.
So, two case for both operation: half >= k or nums[i] >= k 
*/