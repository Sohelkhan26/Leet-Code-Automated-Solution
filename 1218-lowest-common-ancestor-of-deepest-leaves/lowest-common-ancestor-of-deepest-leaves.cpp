class Solution {
public:
    int deepest = 0;
    TreeNode* lca = nullptr;
    int solve(TreeNode* root , int depth){
        deepest = max(deepest , depth);
        if(not root)
            return depth;
        int left = solve(root -> left , depth + 1);
        int right = solve(root -> right , depth + 1);
        if(left == deepest and right == deepest)
            lca = root;
        return max(left , right);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        solve(root , 0);
        return lca;
    }
};