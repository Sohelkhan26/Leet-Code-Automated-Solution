class Solution {
public:
    int N;
    vector<vector<int>> adj;
    int BFS(){
        queue <int> q;
        vector<bool> vis(N);
        q.push(0);
        vis[0] = true;
        int level = 0;
        while(not q.empty()){
            int n = q.size();
            while(n--){
                int i = q.front();
                q.pop();
                if(i == N - 1)
                    return level;
                for(int j : adj[i]){
                    if(not vis[j]){
                        q.push(j);
                        vis[j] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        adj.resize(n);
        N = n;
        for(int i = 0 ; i < n - 1 ; i++)
            adj[i].push_back(i + 1);
        vector<int> ans;
        for(auto it : queries){
            adj[it[0]].push_back(it[1]);
            ans.push_back(BFS());
        }
        return ans;
    }
};