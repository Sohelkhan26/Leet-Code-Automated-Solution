class Solution {
public:
    int dfs(int i , int mid , vector <bool> &vis , vector<vector<pair<int, int>>> &revAdj){
        vis[i] = true;
        int count = 1;
        for(auto [j , w] : revAdj[i]){
            if(not vis[j] and w <= mid)
                count += dfs(j , mid , vis , revAdj);
        }
        return count;
    };

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int low = 1 , high = 1e6 , mid , ans = -1;
        vector<vector<pair<int, int>>> revAdj(n);
        for(auto it : edges){
            int u = it[0] , v = it[1] , w = it[2];
            revAdj[v].push_back({u , w});
        }
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(vector <bool> vis(n); dfs(0 , mid , vis , revAdj) == n){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};

/*
We can remove some edges. And each node must have at most threshold edges.
We need only one edge to visit a node. So we can always keep only one node and fulfill the condition of threshold.
It may seem we need to DFS OR BFS the graph continuously to find out if it's connected to zero th node.
But we can reverse the graph and check if all nodes are reachable from node zero.
And lastly we need to minimize the edge weight.
Binary search comes in mind.
Traverse the graph, if there is at least one edge with "mid" edge weight, we are golden.
*/