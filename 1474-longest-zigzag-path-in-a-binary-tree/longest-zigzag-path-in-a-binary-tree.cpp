/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root , bool goToLeft){
        if(not root)
            return 0;
        if(goToLeft)
            return max(1 + dfs(root -> left , false) , dfs(root -> right , true));
        else
            return max(1 + dfs(root -> right , true) , dfs(root -> left , false));
    }
    int ans = 0;
    void solve(TreeNode* root , bool goToLeft , int visCount){
        if(not root)
            return;
        ans = max(ans , visCount);
        if(goToLeft){
            solve(root -> left , false , visCount + 1);
            solve(root -> right , true , 1);
        }else{
            solve(root -> right , true , visCount + 1);
            solve(root -> left , false , 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        // return max(dfs(root , true) , dfs(root , false)) - 1; // Zigzag length is defined as the number of nodes visited - 1
        solve(root , true , 0);
        solve(root , false , 0);
        return ans;
    }
};
/*
Given the root of a binary tree. 
Choose a node and direction(left or right). Start traversing it and change direction every level.
Return the max number of nodes visited - 1

For every node we have two choice either we continue zigzag traversal or start a new traversal (going left or right based on condition).

If for a node we were going to left we have to go to right in the next call to continue zigzag pattern. If we conitnue zigzag number of visited nodes increases by one.
Otherwise we have to start new traversal with next direction still left but node visited resets to zero.

1 + dfs(root -> left , false) continues the zigzag pattern
dfs(root -> right , true) starts a new one

Though it may seem TC as O(n ^ 2) but truly we are calling only two dfs calls at each node one for left path and one for right path.
*/