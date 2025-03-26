class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int red = 1 , blue = 2;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : redEdges)
            adj[it[0]].push_back({it[1] , red});
        for(auto it : blueEdges)
            adj[it[0]].push_back({it[1] , blue});
        vector <int> dist(n , -1);
        set <pair<int,int>> vis;
        queue <pair<int,int>> q;
        q.push({0 , -1}); //
        int d = 0;
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto [node , color] = q.front(); q.pop();
                if(dist[node] == -1)
                    dist[node] = d;
                for(auto &[nei , neiC] : adj[node]){
                    if(color != neiC and not vis.contains({nei , neiC})){
                        vis.insert({nei , neiC});
                        q.push({nei , neiC});
                    }
                }
            }
            d++;
        }
        return dist;
    }
};