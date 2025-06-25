class Solution {
public:
    unordered_map <int,int> depth , height;
    int best[100001] = {} , secondBest[100001] = {};

    int DFS(TreeNode* root , int level){
        if(not root)
            return -1;

        int left = DFS(root -> left , level + 1) , right = DFS(root -> right , level + 1) , h = 1 + max(left , right);

        depth[root -> val] = level;
        height[root -> val] = h;

        if(best[level] < height[root -> val]){ // best[l] stores largest height of any node at level 'l'
            secondBest[level] = best[level];
            best[level] = height[root -> val];
        }else if(secondBest[level] < height[root -> val])
            secondBest[level] = height[root -> val];

        return height[root -> val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        fill(begin(best) , end(best) , -1);
        fill(begin(secondBest) , end(secondBest) , -1);

        DFS(root , 0);
        transform(queries.begin() , queries.end() , queries.begin() , [&](int q){
            int level = depth[q]; // if removed node is the node with largest height at 'level' then second largest height at that level will be added, otherwise, largest height will be added
            return level + (best[level] == height[q] ? secondBest[level] : best[level]);
        });
        return queries;
    }
};

/*
This is more of a trick problem.
Each node has a depth and height. Longest path passing it has length = 
depth + height
when a node is removed all it's children are removed. Path from root -> left gets reduced by removed nede's height , right? No.

Height of the tree is longest path from root to leaf.

There could be many nodes at that depth. Other nodes with height will still contribute to the total height of the tree. 
Basic Idea is If the removed node is not the node with largest/2nd largest height at that level, the height of the tree will not change.

So for every level store 2 nodes with highest heights.
And check if removed node is the top 2 or not.

What if there is no secondBest ? In that case, tree height becomes = level - 1
So, initialize both array with -1
*/