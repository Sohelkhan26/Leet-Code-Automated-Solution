class Solution {
public:
    // if some subtree returns true, remove that subtree
    bool solve(TreeNode* root){
        if(not root)
            return true;
        bool left = solve(root -> left) , right = solve(root -> right);
        if(left and right and root -> val != 1) // neither left or right subtree has 1, root is not 1 either
            return true;
        if(left)
            root -> left = nullptr;
        if(right)
            root -> right = nullptr;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(solve(root))
            return nullptr;
        return root;
    }
};