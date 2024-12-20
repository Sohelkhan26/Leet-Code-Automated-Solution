class Solution {
public:
    void solve(TreeNode* left , TreeNode* right , int level){
        if(not left or not right)
            return;
        if(level&1 == 1)
            swap(left -> val , right -> val);
        solve(left -> left , right -> right , level + 1);
        solve(left -> right , right -> left , level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root -> left , root -> right , 1);
        return root;
    }
};