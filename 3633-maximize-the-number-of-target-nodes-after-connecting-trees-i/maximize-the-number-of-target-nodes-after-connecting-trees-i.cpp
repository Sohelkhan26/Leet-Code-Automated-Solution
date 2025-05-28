class Solution {
public:
    int dfs(int curr , int par , int k , unordered_map<int,vector<int>> &adj){
        if(k < 0)
            return 0;
        int cnt = 1;
        for(int &nei : adj[curr])
            if(nei != par)
                cnt += dfs(nei , curr , k - 1 , adj);
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int,vector<int>> adj1 , adj2;
        for(auto &e : edges1)
            adj1[e[0]].push_back(e[1]),
            adj1[e[1]].push_back(e[0]);
        for(auto &e : edges2)
            adj2[e[0]].push_back(e[1]),
            adj2[e[1]].push_back(e[0]);
        int n = adj1.size() , m = adj2.size();
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++)
            ans[i] = dfs(i , -1 , k , adj1);
        int best = 0;
        for(int i = 0 ; i < m ; i++)
            best = max(best , dfs(i , -1 , k - 1 , adj2));
        for(int &i : ans)
            i += best;
        return ans;
    }
};