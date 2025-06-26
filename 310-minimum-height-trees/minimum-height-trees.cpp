class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0)
            return {};
        if(n == 1)
            return {0};
        vector <int> degree(n) , ans;
        vector <vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue <int> q;
        for(int i = 0 ; i < n ; i++)
            if(degree[i] == 1)
                q.push(i);
        while(not q.empty()){
            int len = q.size();
            ans.clear();
            while(len--){
                int curr = q.front(); q.pop();
                ans.push_back(curr);
                for(auto &nei : adj[curr])
                    if(--degree[nei] == 1)
                        q.push(nei);
            }
        }
        return ans;
    }
};

/*
Such a trick problem. Root of MHT must be the mid points of longest leaf to leaf path in the tree. To find the mid point, start from all leafs and simulataneously move all by one until they meet at the middle or the have 1 node difference.
Kind of like topo sort.
Just return the node/nodes in the last iteration.
*/