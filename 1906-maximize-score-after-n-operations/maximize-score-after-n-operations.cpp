class Solution {
public:
    int n;
    unordered_map <int,int> dp;
    int solve(int op , vector<int> &nums , bitset<16> &vis){
        int mask = vis.to_ulong();
        if(dp.contains(mask))
            return dp[mask];
        dp[mask] = 0;
        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 1)
                continue;
            for(int j = i + 1 ; j < n ; j++){
                if(vis[j] == 1)
                    continue;
                vis.set(i) , vis.set(j);
                int ans = op * __gcd(nums[i] , nums[j]) + solve(op + 1 , nums , vis);
                vis.reset(i) , vis.reset(j);
                dp[mask] = max(dp[mask] , ans);
            }
        }
        return dp[mask];
    }
    int maxScore(vector<int>& nums) {
        n = nums.size();
        bitset <16> vis = 0;
        return solve(1 , nums , vis);
    }   
};

/*
i'th operation yields i * gcd(n1 , n2)
For every i'th operation any pair can be chosen and we have to take the pair that yields max answer. So, for every i'th operation, fix a pair and solve the sub-problem, take the max answer.
And to keep track of which pair is chosen, use bitmask. And to farther improve TC, store answer to every subproblem. If n is length of nums , total possible states of bitmask is 2 ^ n(for every number two choice, include or don't). So, 2 ^ 14 states.
For every State solve function uses two loops to fix the first pair. TC = O(2 ^ n * n ^ 2)
*/