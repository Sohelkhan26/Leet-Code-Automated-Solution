/*
For every day we have three choices. We choose the one with least cost.
A pass may include days that were not planned. So we find the index that is not covered by the pass and call solve on that index.
*/
class Solution {
public:
    vector<int> dp;
    vector<int> pass = {1 , 7 , 30};
    int solve(int i , vector<int> &days , vector<int> &costs){
        if(i == days.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int cost = INT_MAX , n = days.size();
        for(int k = 0 ; k < 3 ; k++){
            int j = i;
            while(j < n and days[j] < days[i] + pass[k]) // if we buy a pass at some day we can travel for that number of day including the day we are buying it.
                j++;
            cost = min(cost , costs[k] + solve(j , days , costs));
        }
        return dp[i] = cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size() , - 1);
        return solve(0 , days , costs);
    }
};