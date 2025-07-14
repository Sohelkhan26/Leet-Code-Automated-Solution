class Solution {
public:
    int dp[251][251];
    int solve(int i , int k , vector<int> &nums){
        int n = nums.size();
        if(i == n)
            return k == 0 ? 0 : INT_MAX;
        if(k <= 0)
            return INT_MAX;
        if(dp[i][k] != -1)
            return dp[i][k];
        int Xor = 0 , ans = INT_MAX;
        for(int j = i ; j < n ; j++){
            Xor ^= nums[j];
            ans = min(ans , max(Xor , solve(j + 1 , k - 1 , nums)));
        }
        return dp[i][k] = ans;
    }
    int minXor(vector<int>& nums, int k) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , k , nums);
    }
};