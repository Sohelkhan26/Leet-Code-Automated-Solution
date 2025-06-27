class Solution {
public:
    vector <int> ans , count;
    vector<vector<int>> adj;
    void dfs1(int root , int par){ // post-order dfs
        count[root] = 1;
        for(int &child : adj[root]){
            if(child == par)
                continue;
            dfs1(child , root);
            count[root] += count[child];
            ans[root] += (ans[child] + count[child]);
        }
    }
    void dfs2(int root , int par , int n){ // pre-order dfs
        for(int &child : adj[root]){
            if(child == par)
                continue;
            ans[child] = ans[root] - count[child] + n - count[child];
            dfs2(child , root , n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans = vector <int> (n);
        count = vector <int> (n);
        adj = vector<vector<int>> (n);
        for(auto &e : edges)
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(e[0]);
        dfs1(0 , -1);
        dfs2(0 , -1 , n);
        return ans;
    }
};

/*
Quite a hard problem , I think I will understand these kinds of problem better with time.
count[root] -> number of nodes in subtree rooted at 'root'
ans[root] -> sum of distances in subtree rooted at 'root'
Now if we want to calculate the answer for parent of root, 
ans[par] = ans[root] + count[root]
because we already calculated the sum of nodes at subtree 'root' and adding new edge between 'par' & 'root', 
all nodes at subtree rooted at 'root' will be 1 edge further away. This is First most crucial observation.

We can do this for all nodes, but that will be brute force.
Or we can calculate this answer for all nodes by fixing one node as 'root' 
And then we will use re-rooting technique.
When we go from one node 'root' to it's 'child' node, we will consider that child node as the new root(re-rooting),
Then count[child] number of nodes will be 1 edge closer to ans[root]
and all the rest of the nodes(n - count[child]) will be 1 edge further from 'child' node. According to the first observation they will add (n - count[child]) distance.
So, 
ans[child] = ans[root] - count[child] + n - count[child]
*/