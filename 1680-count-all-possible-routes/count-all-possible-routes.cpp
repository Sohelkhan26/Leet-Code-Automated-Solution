class Solution {
public:

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size() , mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1 , vector<int> (fuel  + 1 , -1));
        function<int(int , int)> solve = [&](int i , int fuel) -> int{
            if(fuel < 0)
                return 0;
            if(dp[i][fuel] != -1)
                return dp[i][fuel];
            int ways = (i == finish); // We don't have to stop here. We can go to some other city and again come back to finish if there is fuel left.
            for(int nextCity = 0 ; nextCity < n ; nextCity++){
                if(nextCity != i){
                    ways = (ways + solve(nextCity , fuel - abs(locations[nextCity] - locations[i]))) % mod;
                }
            }
            return dp[i][fuel] = ways;
        };
        return solve(start , fuel);
    }
};
/*
Input:
fuel < 0 not allowed
fuel decreases by abs(location[nextCity] - locations[currCity])
can visit any city more than once
From a city we can go to any city other than itself
All integers in locations are distinct

Output:
All possible routes ending at finish. Return the answer modulo 1e9 + 7

Can you think of anything else than trying all possible routes ending at finish?
Then dp is necessary to avoid recomputing same subproblem.

Since the array contains distinct integers fuel will always be spent in each move and so there can be no cycles.

traverse from the given start. We can choose to go to any city. If that path ends at finish return 1
Do this for every city. 

Don't overthink.
*/