class Solution {
public:
    int mod = 1e9 + 7 , N;
    int dp[301][301];
    int power(int n , int p){
        if(p == 0)
            return 1;
        long long ans = power(n , p / 2);
        ans = (ans * ans) % mod;
        if(p % 2)
            ans = (ans * n) % mod;
        return ans;
    }
    int solve(int target , int x , int i){ // modular exponent
        if(target == 0)
            return 1;
        if(target < 0 or i > N)
            return 0;
        if(dp[target][i] != -1)
            return dp[target][i];
        int skip = solve(target , x , i + 1) % mod;
        int take = solve(target - power(i , x) , x , i + 1) % mod;
        return dp[target][i] = (0ll + skip + take) % mod;
    }
    int numberOfWays(int n, int x) {
        N = n;
        memset(dp , -1 , sizeof(dp));
        return solve(n , x , 1);
    }
};