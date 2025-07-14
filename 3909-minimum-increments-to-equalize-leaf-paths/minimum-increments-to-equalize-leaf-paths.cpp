class Solution {
public:
    int ans = 0;
    vector<vector<int>> adj;
    long long dfs(int curr , int par , vector<int> &price){
        long long maxCost = 0;
        vector <long long> child;
        for(int nei : adj[curr]){
            if(nei == par)
                continue;
            long long t = dfs(nei , curr , price);
            maxCost = max(maxCost , t);
            child.push_back(t);
        }
        for(long long &i : child) // in a tree, one node can have multiple child
            if(i != maxCost) // out of all the child path values, if they don't match the max child path value, one node should be increased
                ans++;
        return 0ll + price[curr] + maxCost;
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        adj.resize(n);
        for(auto &e : edges)
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(e[0]);
        dfs(0 , 0 , cost);
        return ans;
    }
};


/*
changing a root value, affects the whole subtree rooted at that node uniformly.
Changing root node is not optimal right?
For each root, ask it's child, left and right child path sum differ, we need one change right? let's say we make the smaller child bigger, then propagate this answer to up. 
But we have to minimize operations. How can we do that? above one only simulates the process.
And amazingly it passes. Some questions asks to minimize the result but there is no place to minimize. Of course changing each node to some constant value works. Maybe that's why it asks to minimize operations.
*/