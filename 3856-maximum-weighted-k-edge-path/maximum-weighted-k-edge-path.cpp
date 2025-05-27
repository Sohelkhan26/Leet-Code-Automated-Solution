class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>>(k + 1));
        for(auto &e : edges)
            adj[e[0]].push_back({e[1] , e[2]});
        int ans = INT_MIN;
        function<int(int,int,int)> dfs = [&](int curr , int k , int pathSum){
            if(pathSum >= t)
                return INT_MIN;
            if(k == 0)
                return pathSum < t ? pathSum : INT_MIN;
            if(dp[curr][k].contains(pathSum))
                return dp[curr][k][pathSum];
            int ans = INT_MIN;
            for(auto &[nei , w] : adj[curr]){
                int temp = dfs(nei , k - 1 , pathSum + w);
                ans = max(ans , temp);
            }
            return dp[curr][k][pathSum] = ans;
        };
        for(int i = 0 ; i < n ; i++)
            ans = max(ans , dfs(i , k , 0));
        return ans == INT_MIN ? -1 : ans;
    }
};