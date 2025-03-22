class Solution {
public:
    vector <int> adj[51];
    vector <bool> vis;
    pair<int,int> dfs(int i){
        vis[i] = true;
        pair <int,int> nodeEdge = {1 , 0};
        nodeEdge.second += adj[i].size();
        for(int j : adj[i])
            if(not vis[j]){
                auto a = dfs(j);
                nodeEdge.first += a.first , nodeEdge.second += a.second;
            }
        return nodeEdge;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vis.resize(n);
        for(auto e : edges)
            adj[e[0]].push_back(e[1]) , adj[e[1]].push_back(e[0]);
        for(int i = 0 ; i < n ; i++){
            if(not vis[i]){
                auto [node , edge] = dfs(i);
                if(node * (node - 1) * 1ll == edge)
                    ans++;
            }
        }
        return ans;
    }
};