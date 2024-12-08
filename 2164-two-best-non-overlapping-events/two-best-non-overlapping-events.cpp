class Solution {
public:
    int dp[100001][3];
    int solve(vector<vector<int>> &events , int i , int count){
        if(count == 2 or i >= events.size())
            return 0;
        if(dp[i][count] != -1)
            return dp[i][count];
        int nextValidIdx = upper_bound(events.begin() , events.end() , vector<int> {events[i][1] , INT_MAX , INT_MAX}) - events.begin();// find the next event with non overlapping schedule
        int take = events[i][2] + solve(events , nextValidIdx , count + 1);
        int dont = solve(events , i + 1 , count);
        return dp[i][count] = max(take , dont);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        memset(dp , -1 , sizeof(dp));
        sort(events.begin() , events.end());
        return solve(events , 0 , 0);
    }
};