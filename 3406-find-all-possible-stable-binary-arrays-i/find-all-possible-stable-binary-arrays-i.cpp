class Solution {
public:
    int mod = 1e9 + 7;
    int dp[201][201][201][2];
    int solve(int one , int zero , int limit , int currBlock){
        if(one == 0 and zero == 0)
            return 1;
        if(one < 0 or zero < 0)
            return 0;
        if(dp[one][zero][limit][currBlock] != -1)
            return dp[one][zero][limit][currBlock];
        int stable = 0;
        if(currBlock == 1){
            for(int i = 1 ; i <= min(one , limit) ; i++) // this block can have at most limit 1
                stable = (stable + solve(one - i , zero , limit , 0)) % mod; // next index should have 0, to form subarray like 101... or 110... or 1100....
        }else{
            for(int i = 1 ; i <= min(zero , limit) ; i++)
                stable = (stable + solve(one , zero - i , limit , 1)) % mod;
        }
        return dp[one][zero][limit][currBlock] = stable % mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp , -1 , sizeof(dp));
        int start0 = solve(one , zero , limit , 0) , start1 = solve(one , zero , limit , 1);
        return (start0 + start1) % mod;
    }
};

/*
Subarray of length > limit should have both 0,1. It means, we can't have more than limit consecutive same values. Stable array size is (one + zero) and it can be divided into some block each of limit size.
Any block can have all 1 or 0.
*/