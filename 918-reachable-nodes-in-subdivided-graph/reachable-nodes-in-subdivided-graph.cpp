class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1] , e[2] + 1});
            adj[e[1]].push_back({e[0] , e[2] + 1});
        } 
        queue <array<int,3>> q; // {energy , curr , par}
        unordered_map <int,int> energyLeft;
        q.push({maxMoves , 0 , 0});
        energyLeft[0] = maxMoves;



        while(not q.empty()){
            auto a = q.front(); q.pop();
            int energy = a[0] , curr = a[1] , par = a[2];
            if(energyLeft.count(curr) and energyLeft[curr] > energy)
                continue; // already bigger energy recorded after reaching this node
            for(auto &[nei , cost] : adj[curr]){
                if(nei == par or cost > energy)
                    continue;
                int rem = energy - cost;
                if(not energyLeft.count(nei) or energyLeft[nei] < rem){
                    energyLeft[nei] = rem;
                    q.push({rem , nei , curr});
                }
            }
        }
        int ans = energyLeft.size();
        for(auto &e : edges){
            int u = e[0] , v = e[1] , cost = e[2];
            int fromU = energyLeft.count(u) ? energyLeft[u] : 0;
            int fromV = energyLeft.count(v) ? energyLeft[v] : 0;
            ans += min(cost , fromU + fromV); // calculates intermediary nodes.
        }
        return ans;
    }
};

/*
Interesting problem. Generating Intermediary nodes and creating edges between them is not feasible. 10 ** 8 new edges can be possible. 
BFS results in under/over counting of nodes. If a node can be reached via two paths , if one path can be traversed completely and another partially or both paths overlap it poses problem.
[a , b , 10]
4 nodes can be visited via a -> b
5 nodes can be visited via b -> a (now they don't overlap, but there could be cases of overlapping) How to account for those?
One way is to find out remaining energy after reaching every node if they can be reached.
edge = [a , b , 10]
if rem[a] + rem[b] >= 10 then all the intermediary nodes can be visited. Otherwise they can be visited partially.
*/