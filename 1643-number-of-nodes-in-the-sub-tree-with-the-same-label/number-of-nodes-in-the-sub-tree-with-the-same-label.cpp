class Solution {
public:
    int N;
    vector<vector<int>> adj;
    vector <int> ans;
    vector<int> dfs(int curr , int par , string &label){
        vector <int> count(26);
        count[label[curr] - 'a'] = 1; // count -> count-of-all character in subtree rooted at curr
        for(int &nei : adj[curr]){
            if(nei != par){
                vector <int> child = dfs(nei , curr , label);
                for(int i = 0 ; i < 26 ; i++)
                    count[i] += child[i];
            }
        }
        ans[curr] = count[label[curr] - 'a']; 
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n);
        adj.resize(n);
        for(auto &e : edges)
            adj[e[0]].push_back(e[1]),
            adj[e[1]].push_back(e[0]);
        dfs(0 , -1 , labels);
        return ans;
    }
};

/*
There can't be no more than 26 unique labels. 
And we can't fix a character and find count of that character in each subtree, because for each new subtree, we have to do this again. O(n ^ 2)
Each child subtree will return count of all character rooted at child.
This is where I made a mistake. I wanted to pass a single vector to all childs and overthinked.
*/