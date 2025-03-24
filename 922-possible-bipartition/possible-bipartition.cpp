class Solution {
public:
    int white = 0 , red = 1 , blue = 2;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector <int> vis(n + 1) , color(n + 1);
        vector <vector<int>> adj(n + 1);
        for(auto &d : dislikes)
            adj[d[0]].push_back(d[1]) , adj[d[1]].push_back(d[0]);
        for(int i = 1 ; i <= n ; i++){
            if(not vis[i]){
                // this component not colored yet, so color it red.
                queue <int> q; //***
                color[i] = red;
                q.push(i);
                while(not q.empty()){
                    int curr = q.front(); q.pop();
                    if(vis[curr])continue;
                    vis[curr] = true;
                    for(int nei : adj[curr]){
                        if(color[nei] == color[curr])return false;
                        q.push(nei);
                        color[nei] = (color[curr] == red) ? blue : red;
                    }
                }
            }
        }
        return true;
    }
};