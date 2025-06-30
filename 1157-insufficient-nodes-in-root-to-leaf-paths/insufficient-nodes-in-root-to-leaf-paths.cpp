class Solution {
public:
    int limit;
    bool solve(TreeNode* root , int sum){
        if(not root)
            return true; // or false?
        sum += root -> val;
        if(not root -> left and not root -> right)
            return sum < limit;
        bool left = solve(root -> left , sum);
        bool right = solve(root -> right , sum);
        if(left and right)
            return true;
        if(left)
            root -> left = nullptr;
        if(right)
            root -> right = nullptr;
        return false;
    }
    TreeNode* sufficientSubset(TreeNode* root, int l) {
        limit = l;
        return solve(root , 0) ? nullptr : root;
    }
};