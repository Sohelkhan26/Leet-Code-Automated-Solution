class Solution {
public:
    typedef long long ll;
    vector<vector<vector<ll>>> dp;
    ll solve(int i , int leftPrev , int rightPrev , vector<vector<int>> &cost){
        int j = cost.size() - i - 1;
        ll ans = LLONG_MAX;
        if(i > j)
            return 0;
        if(dp[i][leftPrev][rightPrev] != -1)
            return dp[i][leftPrev][rightPrev];
        for(int c = 0 ; c < 3 ; c++){ // assign color 'c' to left 
            for(int d = 0 ; d < 3 ; d++){ // color 'd' to right end house.
                if(c == d or c == leftPrev or d == rightPrev) // c == d , equidistant house can't have same color , c == leftPrev adjacent house can't have same color
                    continue;
                ans = min(ans , cost[i][c] + cost[j][d] + solve(i + 1 , c , d , cost));
            }
        }
        return dp[i][leftPrev][rightPrev] = ans;
    }
    ll minCost(int n, vector<vector<int>>& cost) {
        dp.resize(n / 2 , vector<vector<ll>> (4 , vector<ll> (4 , -1)));
        return solve(0 , 3 , 3 , cost);
    }
};

/*
n(even) house, 3 colors.
cost[i][j] is the cost to color i'th house with j + 1 color.
For simplicity we assume colors are 0,1,2(to match with index)
ajdacent and equidistant house can't have same color.
Instead of maintaining two index from left and right, we reuse left index 
for the right index. right = n - left - 1
Now brute force with memoization which is called DP.
*/