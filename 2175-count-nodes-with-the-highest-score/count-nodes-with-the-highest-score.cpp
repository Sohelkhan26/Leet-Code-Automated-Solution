class Solution {
public:
    long long  maxScore = -1;
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size() , count = 0;
        vector<vector<int>> adj(n);
        for(int i = 1 ; i < n ; i++) // parent of 0 node = -1 , so no need
            adj[parents[i]].push_back(i);
        function<int(int)> dfs = [&](int curr){
            long long score = 1;
            int childNodes = 1; // total descendent nodes , including itself
            for(int nei : adj[curr]){ // score of left and right child if exists
                int nodes = dfs(nei);
                score *= max(1 , nodes);
                childNodes += nodes;
            }
            score *= max(1 , n - childNodes); // upper nodes
            if(score > maxScore){
                maxScore = score;
                count = 1;
            }else if(score == maxScore)count++;
            return childNodes;
        };
        dfs(0);
        return count;
    }
};

/*
Find count of nodes that have the max score.
Score is the product of subtree lengths , when a node and it's edges is removed.
Once a node is removed , as it's binary tree, at most 3 subtree possible: left , right and upper subtree.
For each node find the count of left and right subtree by DFS, upper subtree length is : 
n - 1(for current node) - left - right. Most important part.
DFS only counts the nodes in the left and right subtree.
No need to fret over visiting the same node again and again. Tree is uni-directional. visited once only.
*/