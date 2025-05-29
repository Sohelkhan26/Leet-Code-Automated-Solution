class Solution {
public:
    int dfs(int curr , int par , vector<int> &parity , unordered_map<int,vector<int>> &adj , bool even = true){
        int targets = even;
        parity[curr] = even;
        for(int &nei : adj[curr])
            if(nei != par)
                targets += dfs(nei , curr , parity , adj , not even);
        return targets;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto makeList = [&](vector<vector<int>> &edges){
            unordered_map <int,vector<int>> adj;
            for(auto &e : edges)
                adj[e[0]].push_back(e[1]),
                adj[e[1]].push_back(e[0]);
            return adj;
        }; 
        auto adj1 = makeList(edges1) , adj2 = makeList(edges2);
        int n = adj1.size() , m = adj2.size();
        vector<int> parity(n) , ignore(m) , ans(n);
        int even1 = dfs(0 , -1 , parity , adj1) , odd1 = n - even1;
        int even2 = dfs(0 , -1 , ignore , adj2) , odd2 = m - even2;
        for(int i = 0 ; i < n ; i++)
            ans[i] = (parity[i] ? even1 : odd1) + max(even2 , odd2);
        return ans;
    }
};