class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector <int> outDegree(n) , inDegree(n) , ans;
        vector <vector<int>> adj(n);
        for(auto &e : edges)
            outDegree[e[0]]++ , inDegree[e[1]]++, adj[e[1]].push_back(e[0]);
        queue <int> q;
        for(int i = 0 ; i < n ; i++)
            if(not outDegree[i])
                q.push(i);
        while(not q.empty()){
            int len = q.size();
            while(len--){
                int curr = q.front(); q.pop();
                if(inDegree[curr] == 0)
                    ans.push_back(curr);
                for(int nei : adj[curr])
                    if(--outDegree[nei] == 0)
                        q.push(nei);
            }
        }
        return ans;
    }
};