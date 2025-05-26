class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n , -1);
        function<int(int)> solve = [&](int i){
            if(i >= n)
                return 0;
            if(dp[i] != -1)
                return dp[i];
            int buy = INT_MAX; // we will buy i'th item and go to best free item. Out of next (i + 1) items , that gives the min answer.
            for(int j = i + 1 ; j <= 2 * i + 2 ; j++)
                buy = min(buy , solve(j)); // we can buy item even if it was acquired for free previously
            return dp[i] = buy + prices[i];
        };
        return solve(0);
    }
};

/*
If we are at i'th index, next i items are free.
But our array is 0 indexed. So, next (i + 1) items are free.
We have to buy i'th item though.
So, starting from (i + 1) , next (i + 1) items are free.
So, j -> [i + 1 , 2 * i + 2] are free.
*/