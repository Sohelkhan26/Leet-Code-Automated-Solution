class Solution {
public:
    vector <int> count;
    set <pair<int,int>> parent;
    vector <vector<int>> adj;
    int n , ans = 0 , k;
    int dfs1(int root , int par){
        for(int &child : adj[root]){
            if(child == par)
                continue;               // root is parent of child in guess
            count[root] += (parent.contains({root , child})) + dfs1(child , root);
        }
        return count[root];
    }
    void dfs2(int root , int par , int correct){
        if(correct >= k)
            ans++; 
        for(int &child : adj[root]){
            if(child == par)
                continue; // root is parent of child in guess // child is also parent of root in guess
            dfs2(child , root , correct - parent.contains({root , child}) + parent.contains({child , root}));
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int K) {
        n = edges.size() + 1; 
        adj = vector<vector<int>> (n);
        count = vector <int> (n);
        k = K;

        for(auto &g : guesses) // [parent , child]
            parent.insert({ g[0] , g[1] });
        for(auto &e : edges)
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(e[0]);
        int correct = dfs1(0 , -1);
        // for(int i = 0 ; i < n ; i++)
        //     cout << count[i] << ' ';
        dfs2(0 , -1 , correct);
        return ans;
    }
};

/*
given undirected tree, guesses and k
guess[i] = [parent , child] at least k of them are true
n >= k true
find count of possible roots based on guesses

What to find is not clear to me yet.
How to determine which guesses are false? They will contradict?
If a node is the root of the tree what changes? What does it take to be the root of the tree? Min Height?

From the example, maybe fix a root and find how many guesses are correct , if >= k , then that is a possible root?

count[root] -> number of true guess if tree is rooted at 'root'
Find this recursively.
Now, we have to find count[i] for all nodes(making them root) using brute force(using the same function)
Or we can do this in O(n) by re-rooting.

Find correct guess for any node, let's call it 'root'
Start another DFS
For it's child, think of that as root of tree
if child is parent of 'root' in guess, correct guess will increase.
if 'root' is parent of child in guess, correct guess will decrease.
*/