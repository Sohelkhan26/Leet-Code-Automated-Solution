class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& edge) {
        int n = edge.size() + 1 , mod = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edge)
            adj[e[0]].push_back({e[1] , e[2]});
        vector<int> ans(n);
        ans[0] = 1;
        function<void(int)> dfs = [&](int i){
            for(auto &[nei , rate] : adj[i])
                ans[nei] = (ans[nei] +  1ll * ans[i] * rate) % mod , dfs(nei);
        };
        dfs(0);
        return ans;
    }
};