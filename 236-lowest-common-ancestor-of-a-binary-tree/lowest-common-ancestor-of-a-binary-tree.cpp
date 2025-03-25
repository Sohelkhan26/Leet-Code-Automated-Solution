/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(not root or root == p or root == q)
            return root;
        auto left = lowestCommonAncestor(root -> left , p , q);
        auto right = lowestCommonAncestor(root -> right , p , q);
        return left and right ? root : not left ? right : left;
    }
};

/*
If either p or q found, that is the LCA.
If p , q are in seperate subtree, that implies split has ocurred. Current root is the LCA.
Other wise p and q will be either in left or right. If they are in the same subtree, then either p or q will be the LCA.
How to Detect if p,q are in different subtree? return NULL.
So, in case of split both left and right value will be non null, will point to p and q.
Otherwise one(left/right) will point to p/q and other will point to NULL;
*/